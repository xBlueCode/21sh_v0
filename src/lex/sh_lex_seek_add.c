#include "libft.h"
#include "sh_lex.h"

int		sh_lex_seek_add(t_lex *lex, int op)
{
	int		l;
	t_token	*tok;

	(void)op;
	//ft_printf("seek_add:: ST: <%d>  off: <%d>  i: <%d>\n", lex->st, off, lex->i);
	if (lex->st == TSWS)
	{
		lex->off = lex->i;
		return (0);
	}
	l = lex->i - lex->off;
	if (lex->st == TSW || lex->st == TSSQ || lex->st == TSDQ || lex->st == TSBQ
		|| lex->st == TSD_CBL || lex->st == TSD_PL || lex->st == TSD_PL2
		|| lex->st == TSION || lex->st == TSTOK)
		tok = sh_lex_tok_new(lex->st, lex->off, l,
			ft_strndup(lex->in->str + lex->off, l));
	else
		tok = sh_lex_tok_new(lex->st, lex->off, l, NULL);
	sh_lex_tok_add(lex, tok);
	lex->st = TSNONE; // not final
	lex->off = lex->i; // not final
	ft_printf("Tok: %-4d - %s\n", tok->t, tok->val ? tok->val->str : "");
	return (1);
}