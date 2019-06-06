//
// Created by xbluecode on 26.05.19.
//

#include "libft.h"
#include "sh_lex.h"

int 			sh_lex_seek_sq(t_lex *lex, int op)
{
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
	if (lex->in->str[lex->i] != '`')
		return (0);
	while (lex->in->str[lex->i] && lex->in->str[++lex->i] != '`');
	if (!lex->in->str[lex->i])
		SH_LEX_RETERR(lex, TSBQ)
	lex->i++;
	lex->st = TSBQ;
	return (1);
}
