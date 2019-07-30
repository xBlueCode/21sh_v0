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
	while (lex->in->str[lex->i] && lex->in->str[++lex->i] != '\'')
		;
	if (!lex->in->str[lex->i])
		SH_LEX_RETERR(lex, TSSQ)
	lex->i++;
	lex->st = TSSQ;
	return (1);
}

int 			sh_lex_seek_bq(t_lex *lex, int op) {
	(void)op;
	if (lex->in->str[lex->i] != '`')
		return (0);
	while (lex->in->str[lex->i] && lex->in->str[++lex->i] != '`')
		;
	if (!lex->in->str[lex->i])
		SH_LEX_RETERR(lex, TSBQ)
	lex->i++;
	lex->st = TSBQ;
	return (1);
}

int 			sh_lex_seek_dq(t_lex *lex, int op) {
	if (lex->in->str[lex->i] != '"')
		return (0);
	lex->i++;
	while (lex->in->str[lex->i] && lex->in->str[lex->i] != '"')
	{
		if (sh_lex_seek_rescope(lex, op)
			|| sh_lex_seek_join(lex, op)
			//|| sh_lex_seek_space(lex, op)
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
	if (!lex->in->str[lex->i])
		SH_LEX_RETERR(lex, TSDQ)
	lex->i++;
	lex->st = TSDQ;
	return (1);
}
