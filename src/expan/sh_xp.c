#include "ftsh.h"

/**
 * brace expansion
 * :> generate a list of words
 * start with '{'
 * 		invoke lexers: cmdsub, quotes ...
 * 			if (space_lexer positive)
 * 				stop (and escape the first {) and return 0
 * 		if (c == '}')
 * 			break;
 * 		if (c == ',')
 * 			build a new word from pervious offset to current
*/

/**
 * tilde expansion
 * ~+[/[_word]], ~-[/[_word]], ~loginname[/[_word]]
 * detection: 1st char in word, 1st char after = or : in assign
*/

/**
 * param expansion
 * ${param}
 * ${param.:.modifier.word}
 * in case first part is not valid param --> err: bad subst
*/

int		sh_xp_start(t_sh *sh, t_dastr *words)
{
	int i;
	int j;

	i = -1;
	while (++i < words->len)
	{
		j = 0;
		sh_xp_tilde(sh, words, &i, &j);
		while (j < words->a[i]->len)
		{
			if (sh_xp_brace(sh, words, &i, &j)
				|| sh_xp_param(sh, words, &i, &j)
				|| sh_xp_var(sh, words, &i, &j)
				|| sh_xp_dq(sh, words, &i, &j)
				|| sh_xp_sq(sh, words, &i, &j)
				|| sh_xp_esc(sh, words, &i, &j)
			)
				continue;
			j++;
		}
	}
}

int 	sh_xp_dq(t_sh *sh, t_dastr *words, int *i, int *j)
{
	t_dstr *word;

	word = words->a[*i];
	if (word->str[*j] != '"')
		return (0);
	ft_dstrdel_n(words->a[*i], *j, 1);
	while (word->str[*j] && word->str[*j] != '"')
	{
		ft_printf(C_GRN"Worddq: %s\n"T_END, word->str + *j);
		if (//sh_xp_brace(sh, words, i, j)
			sh_xp_param(sh, words, i, j)
			|| sh_xp_var(sh, words, i, j)
			|| sh_xp_esc(sh, words, i, j)
		//	|| sh_xp_dq(sh, words, i, j)
			)
			continue;
		(*j)++;
	}
	if (word->str[*j] != '"')
		return (-1);
	ft_dstrdel_n(words->a[*i], *j, 1);
	return (1);
}

int 	sh_xp_sq(t_sh *sh, t_dastr *words, int *i, int *j)
{
	char *word;

	word = words->a[*i]->str;
	if (word[*j] != '\'')
		return (0);
	ft_dstrdel_n(words->a[*i], *j, 1);
	while (word[*j] && word[*j] != '\'')
		(*j)++;
	if (word[*j] != '\'')
		return (-1);
	ft_dstrdel_n(words->a[*i], *j, 1);
	return (1);
}

int 	sh_xp_esc(t_sh *sh, t_dastr *words, int *i, int *j)
{
	char *word;

	word = words->a[*i]->str;
	if (word[*j] != '\\')
		return (0);
	ft_dstrdel_n(words->a[*i], *j, 1);
	(*j)++;
	return (1);
}

int 	sh_xp_tilde(t_sh *sh, t_dastr *words, int *i, int *j)
{
	t_dstr	*word;
	char 	*rep;
	int 	k;

	word = words->a[*i];
	if (word->str[*j] != '~')
		return (0);
	k = *j + 1;
	if ((word->str[k] == '+' || word->str[k] == '-') && (!word->str[k + 1] || word->str[k + 1] == '/'))
	{
		rep = sh_var_getval(sh->var, word->str[k] == '+' ? "PWD" : "OLDPWD");
		ft_dstrdel_n(words->a[*i], *j, 2);
		ft_dstrins_str(words->a[*i], *j, rep); // TODO: free rep
		*j += ft_strlenz(rep);
		return (1);
	}
	while (k < words->a[*i]->len && word->str[k] != '/')
	{
		if (word->str[k] != '_' && !ft_isalnum(word->str[k]))
			break;
		k++;
	}
	if (word->str[k] && word->str[k] != '/')
		return (0);
	ft_dstrdel_n(words->a[*i], *j, k - *j);
	if (*j + 1 == k)
		rep = sh_var_getval(sh->var, "HOME");
	else
		rep = "USERPATH";
	ft_dstrins_str(words->a[*i], *j, rep);
	*j += ft_strlenz(rep);
	return (1);
}

int 	sh_xp_var(t_sh *sh, t_dastr *words, int *i, int *j)
{
	t_dstr	*word;
	char 	*key;
	char 	*val;
	int		off;

	word = words->a[*i];
	if (word->str[*j] != '$' || ft_strchr("{(", word->str[*j + 1]))
		return (0);
	off = ++(*j);
	if (!sh_lex_isinname(word->str[*j]))
		return (1);
	while (sh_lex_isinname(word->str[*j]))
		(*j)++;
	key = ft_strndup(word->str + off, *j - off);
	ft_dstrdel_n(word, off - 1, *j - off + 1);
	ft_printf(C_RED"word after deletion: %s\n"T_END, word->str);
	val = sh_var_getval(sh->var, key);
	(*j) = off - 1 + ft_strlenz(val);
	ft_dstrins_str(word, off - 1, val);
	return (1); // TODO: don't free val (it still point in the env)
}

int 	sh_xp_param(t_sh *sh, t_dastr *words, int *i, int *j)
{
	char	*word;
	char 	*param;
	char	*val;
	int		off;

	word = words->a[*i]->str;
	if (ft_strncmp("${", word + *j, 2))
		return (0);
	ft_dstrdel_n(words->a[*i], *j, 2);
	off = *j;
	while (word[*j] && word[*j] != '}')
	{
		if (!sh_lex_isinname(word[*j]))
			break ;
		(*j)++;
	}
	if (word[*j] != '}')
		return (-1);
	param = ft_strndup(word + off, *j - off);
	ft_dstrdel_n(words->a[*i], off, *j - off + 1);
	ft_printf(C_RED"After deleting: %s\n"T_END, words->a[*i]->str);
	val = sh_var_getval(sh->var, param);
	ft_dstrins_str(words->a[*i], off, val);
	ft_printf(C_RED"After insertion: %s\n"T_END, words->a[*i]->str);
	if (val)
		*j = off + ft_strlenz(val);
	ft_printf(C_RED"After moving: %s\n"T_END, words->a[*i]->str + *j);
	return (1); // TODO: free param
}

int 	sh_xp_brace(t_sh *sh, t_dastr *words, int *i, int *j)
{
	t_dastr	*res;
	char 	*word;
	char 	*inp;
	t_lex	*lex;
	int		off;
	int		k;
	char 	*pref;
	char 	*suff;

	(void)sh;
	word = words->a[*i]->str;
	if (word[*j] != '{')
		return (0);
	off = *j + 1;
	*j += 1;
	pref = ft_strndup(words->a[*i]->str, *j - 1);
	sh_lex_init(&lex, word + off);
	off = 0;
	inp = lex->in->str;
	res = ft_dastrnew_max(2);
	while (inp[lex->i] && lex->st != TSBLANK && inp[lex->i] != '}')
	{
		*j += lex->i;
		if (sh_lex_seek_scmd(lex, 0)
			|| sh_lex_seek_dq(lex, 0)
			|| sh_lex_seek_blank(lex, 0)
			|| sh_lex_seek_brace(lex, 0)
			//|| sh_xp_brace(sh, words, i, j, 0)
			)
			continue;
		if (inp[lex->i] == ',')
		{
			inp[lex->i++] = '\0';
			ft_dastrins_str(res, -1, inp + off);
			off = lex->i;
		}
		/*
		else if (inp[lex->i] == '{')
		{
			while (inp[lex->i] && inp[lex->i++] != '}')
				;
		}
		 */
		else
			lex->i++;
	}
	if (lex->st == TSBLANK || inp[lex->i] != '}')
		return (0);
	inp[lex->i++] = '\0';
	ft_dastrins_str(res, -1, inp + off);
	*j = lex->i;
	suff = ft_strdup(lex->in->str + *j);
	if (res->len)
		ft_dastrdel_n(words, *i, 1);
	k = -1;
	while (++k < res->len)
	{
		ft_dstrins_str(res->a[k], 0, pref);
		ft_dstrins_str(res->a[k], -1, suff);
		ft_dastrins_str(words, *i + k, res->a[k]->str);
	}
	if (res->len)
		*i -= 1;
	ft_putstr(C_MGN);
	ft_dastrprint_all(res, "\n");
	ft_putstr(T_END"\n");
	// TODO: free res dastr
	return (1);
}
