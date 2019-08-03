//
// Created by xbluecode on 26.05.19.
//

#include "libft.h"
#include "sh_lex.h"

int 			sh_lex_seek_sq(t_lex *lex, int op)
{
	(void)op;
	if (lex->in->str[lex->i] != '\'')
		return (0);
	ft_dstrins_ch(lex->scope, -1, RL_SCP_SQ);
	while (lex->in->str[lex->i] && lex->in->str[++lex->i] != '\'')
		;
	//if (!lex->in->str[lex->i])
	//	SH_LEX_RETERR(lex, TSSQ)
	if (lex->in->str[lex->i])
		ft_dstrdel_n(lex->scope, -1, 1);
	lex->i++;
	lex->st = TSSQ;
	return (1);
}

int 			sh_lex_seek_bq(t_lex *lex, int op) {
	(void)op;
	if (lex->in->str[lex->i] != '`')
		return (0);
	ft_dstrins_ch(lex->scope, -1, RL_SCP_BQ);
	while (lex->in->str[lex->i] && lex->in->str[++lex->i] != '`')
		;
	//if (!lex->in->str[lex->i])
	//	SH_LEX_RETERR(lex, TSBQ)
	if (lex->in->str[lex->i])
		ft_dstrdel_n(lex->scope, -1, 1);
	lex->i++;
	lex->st = TSBQ;
	return (1);
}

int 			sh_lex_seek_dq(t_lex *lex, int op) {
	if (lex->in->str[lex->i] != '"')
		return (0);
	ft_dstrins_ch(lex->scope, -1, RL_SCP_DQ);
	lex->i++;
	while (lex->in->str[lex->i] && lex->in->str[lex->i] != '"')
	{
		if (sh_lex_seek_rescope(lex, op)
			|| sh_lex_seek_join(lex, op)
			//|| sh_lex_seek_blank(lex, op)
			|| sh_lex_seek_escape(lex, op)
			|| sh_lex_seek_sq(lex, op)
			//|| sh_lex_seek_dq(lex, op)
			|| sh_lex_seek_bq(lex, op)
			|| sh_lex_seek_param(lex, op)
			|| sh_lex_seek_smath(lex, op)
			|| sh_lex_seek_scmd(lex, op)
			//|| sh_lex_seek_op(lex, op)
			//|| sh_lex_seek_wo(lex, op)
			//|| sh_lex_seek_nl(lex, op)
			)
			continue;
			//sh_lex_seek_add(lex, op);
		else
			lex->i++;
	}
	//if (!lex->in->str[lex->i])
	//	SH_LEX_RETERR(lex, TSDQ)
	if (lex->in->str[lex->i])
		ft_dstrdel_n(lex->scope, -1, 1);
	lex->i++;
	lex->st = TSDQ;
	return (1);
}
