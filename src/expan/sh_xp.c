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
		while (j < words->a[i]->len)
		{
			if (sh_xp_brace(sh, words, i, &j))
				continue;
			j++;
		}
	}
}

int 	sh_xp_brace(t_sh *sh, t_dastr *words, int i, int *j)
{
	t_dastr	*res;
	char 	*word;
	char 	*inp;
	t_lex	*lex;
	int		off;

	(void)sh;
	word = words->a[i]->str;
	if (word[*j] != '{')
		return (0);
	off = *j + 1;
	*j += 1;
	sh_lex_init(&lex, word + off);
	off = 0;
	inp = lex->in->str;
	res = ft_dastrnew_max(2);
	while (inp[lex->i] && lex->st != TSBLANK && inp[lex->i] != '}')
	{
		if (sh_lex_seek_scmd(lex, 0)
			|| sh_lex_seek_dq(lex, 0)
			|| sh_lex_seek_blank(lex, 0)
			)
			continue;
		if (inp[lex->i] == ',')
		{
			inp[lex->i++] = '\0';
			ft_dastrins_str(res, -1, inp + off);
			off = lex->i;
		}
		else
			lex->i++;
	}
	if (lex->st == TSBLANK || inp[lex->i] != '}')
		return (0);
	inp[lex->i++] = '\0';
	ft_dastrins_str(res, -1, inp + off);
	*j = lex->i;
	ft_putstr(C_MGN);
	ft_dastrprint_all(res, "\n");
	ft_putstr(T_END"\n");
	return (1);
}