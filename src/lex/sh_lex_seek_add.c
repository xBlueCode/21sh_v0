#include "libft.h"
#include "sh_lex.h"

int		sh_lex_seek_add(t_lex *lex, int op)
{
	int		l;
	t_token	*tok;

	(void)op;
	//ft_printf("seek_add:: ST: <%d>  off: <%d>  i: <%d>\n", lex->st, off, lex->i);
	if (lex->st == TSERR)
	{
//		ft_printf("Parsing Error at [%d]: '%c'\n", lex->i, lex->in->str[lex->i]);
		return (-1);
	}
	if (lex->st == TSBLANK || lex->st == TSNONE || lex->st == TSALIAS)
	{
		lex->off = lex->i;
		lex->st = TSNONE;
		return (0);
	}
	l = lex->i - lex->off;
	if (lex->st == TSW || lex->st == TSSQ || lex->st == TSDQ || lex->st == TSBQ
		|| lex->st == TSD_CBL || lex->st == TSD_PL || lex->st == TSD_PL2
		|| lex->st == TSION || lex->st == TSTOK)
	{
		tok = sh_lex_tok_new(lex->st, lex->off, l,
							 ft_strndup(lex->in->str + lex->off, l));
		sh_lex_seek_rw(tok, sh_lex_ctx_last(lex, op));
		if (sh_lex_tok_last(lex)->t == TSL2 && lex->st == TSTOK)
		{
			ft_dastrins_str(lex->hd_key, -1, tok->val->str);
			ft_dstrins_ch(ft_dastrget_i(lex->hd_key, -1), -1, '\n');
		}
		if (lex->assi > -1)
			tok->assi = lex->assi - lex->off;
		//lex->assi = -1;
	}
	else if (sh_lex_tok_last(lex)->t == TSL2 && lex->st != TSTOK)
	{
		ft_dstrdel_n(lex->scope, -1, 1);
		lex->st = TSERR;
		return (-1);
	}
	else
		tok = sh_lex_tok_new(lex->st, lex->off, l, NULL);
	sh_lex_tok_add(lex, tok);
//	sh_lex_seek_ctx(lex, op);
	lex->st = TSNONE; // not final
	lex->off = lex->i; // not final
	if (op)
		ft_printf(C_MGN"Tok: %-4d - %-24s %3d\n"T_END, tok->t, tok->val ? tok->val->str : "", tok->assi);
	return (1);
}