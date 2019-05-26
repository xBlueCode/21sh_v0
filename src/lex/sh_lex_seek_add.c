//
// Created by xbluecode on 26.05.19.
//

#include "libft.h"
#include "sh_lex.h"

int		sh_lex_seek_add(t_lex *lex, ssize_t off)
{
	int		l;
	t_token	*tok;

	//ft_printf("seek_add:: ST: <%d>  off: <%d>  i: <%d>\n", lex->st, off, lex->i);
	if (lex->st == TSNONE)
		return (0);
	l = lex->i - off;
	if (lex->st == TSW || lex->st == TSSQ)
		tok = sh_lex_tok_new(lex->st, off, l,
			ft_strndup(lex->in->str + off, l));
	else
		tok = sh_lex_tok_new(lex->st, off, l, NULL);
	sh_lex_tok_add(lex, tok);
	lex->st = TSNONE;
	ft_printf("Tok: %-4d - %s\n", tok->t, tok->val->str);
	return (1);
}