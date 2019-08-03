#include "libft.h"
#include "sh_lex.h"

int 	sh_lex_seek_ctx(t_lex *lex, int op)
{
	(void)op;
	if (lex->st == TSBLANK)
		return (0);
	if (lex->st == TSSTART
		||	lex->st == TSSC
		|| lex->st == TSA || lex->st == TSA2
		|| lex->st == TSO || lex->st == TSO2
		|| lex->st == TSPL || lex->st == TSNL
		)
		lex->ctx = TCTX_FIRSTW;
	else
		lex->ctx = TCTX_NONE;
	return (1);
}