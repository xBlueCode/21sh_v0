#include "libft.h"
#include "sh_lex.h"

int		sh_lex_seek_start(t_lex *lex, int op)
{
	lex->buf = ft_dstrnew_max(1);
	while (lex->in->str[lex->i])
	{
		//lex->off = lex->i; // not final
		//lex->st = TSNONE; // not final
		//ft_printf("--->  seeking all from %d\n", off);
		if (//sh_lex_seek_escape(lex, op)
			sh_lex_seek_rescope(lex, op)
		    || sh_lex_seek_join(lex, op)
		    || sh_lex_seek_hash(lex, op)
		    //|| sh_lex_seek_escape(lex, op)
			|| sh_lex_seek_blank(lex, op)
			|| sh_lex_seek_p(lex, op)
			|| sh_lex_seek_cb(lex, op)
			|| (sh_lex_seek_als(lex, op) == 1)
			//|| sh_lex_seek_sq(lex, op)
			//|| sh_lex_seek_dq(lex, op)
			//|| sh_lex_seek_bq(lex, op)
			//|| sh_lex_seek_param(lex, op)
			//|| sh_lex_seek_smath(lex, op)
			//|| sh_lex_seek_scmd(lex, op)
			|| sh_lex_seek_hd(lex, op)
			//|| sh_lex_seek_hdk(lex, op) // TODO: replace {hdk, hdv} with hd
			//|| sh_lex_seek_hdv(lex, op)
			|| sh_lex_seek_op(lex, op)
			|| sh_lex_seek_ion(lex, op) // check in other scopes
			|| sh_lex_seek_nl(lex, op)
			|| sh_lex_seek_tok(lex, op)
			)
			//continue;
		{
			if (lex->st != TSNONE)
				sh_lex_seek_ctx(lex, op);
			if (sh_lex_seek_add(lex, op) < 0)
				return (KO);
		}
		else
			lex->i++;
	}
	return (OK);
}

int 		sh_lex_seek_tok_delim(t_lex *lex, int op)
{
	(void)op;
	if (sh_lex_tok_isdelim(lex->in->str[lex->i])
		|| !lex->in->str[lex->i])
	//	|| (lex->in->str[lex->i] == '}'
	//	&& sh_lex_tok_isdelim(lex->in->str[lex->i + 1])))
	{
//		if (sh_lex_tok_last(lex)->t == TSL2)
//			ft_dastrins_str(lex->hd_key, -1, hd_key);
//		if (!*lex->scope->str)
//ft_printf(C_RED"\nST before adding TOK %d\n"T_END, lex->st);
//			sh_lex_seek_ctx(lex, op);
			lex->st = TSTOK;
//		else
//			lex->st = TSNONE;
		return (1);
	}
	if (lex->in->str[lex->i] == '=' && lex->assi < 0)
		lex->assi = lex->i;
	return (0);
}

int 		sh_lex_seek_tok(t_lex *lex, int op)
{
	int 	off;

	(void)op;
	off = lex->i;
	lex->assi = -1;
	while (lex->i < lex->in->len + 1)
	{
		if (sh_lex_seek_rescope(lex, op)
			|| sh_lex_seek_join(lex, op)
			|| sh_lex_seek_escape(lex, op)
			|| sh_lex_seek_sq(lex, op)
			|| sh_lex_seek_dq(lex, op)
			|| sh_lex_seek_bq(lex, op)
			|| sh_lex_seek_param(lex, op)
			|| sh_lex_seek_smath(lex, op)
			|| sh_lex_seek_scmd(lex, op)
			//|| sh_lex_seek_ssh(lex, op)
			//|| sh_lex_seek_hd(lex, op)
			//|| sh_lex_seek_op(lex, op)
			//|| sh_lex_seek_ion(lex, op) // check in other scopes
			//|| sh_lex_seek_wo(lex, op)
			//|| sh_lex_seek_nl(lex, op)
			)
			continue;
		else if (sh_lex_seek_tok_delim(lex, op))
			return (1);
		lex->i++;
	}
	return (1);
}

int         sh_lex_seek_rescope(t_lex *lex, int op)
{
	ssize_t		i;
	char 		*line;

	(void)op;
	i = lex->i;
	line = lex->in->str;
	if (ft_dstrget_ch(lex->scope, -1) == RL_SCP_JOIN)
		ft_dstrdel_n(lex->scope, -1, 1);
	else if (
			ft_dstrget_ch(lex->scope, -1) == RL_SCP_PIPE
			|| ft_dstrget_ch(lex->scope, -1) == RL_SCP_AND
			|| ft_dstrget_ch(lex->scope, -1) == RL_SCP_OR
			)
	{
		while (ft_isspace(line[i]))
			i++;
		if (sh_lex_seek_join(lex, op))
			return (1);
		if (line[i] && line[i] != '\n')
			ft_dstrdel_n(lex->scope, -1, 1);
		lex->i = i;
		return (1);
	}
	return (0);
}