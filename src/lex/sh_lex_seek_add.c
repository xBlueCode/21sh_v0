//
// Created by xbluecode on 26.05.19.
//

#include "libft.h"
#include "sh_lex.h"

int		sh_lex_seek_add(t_lex *lex, ssize_t off)
{
	int l;

	if (lex->st == TSNONE)
		return (0);
	l = lex->i - off;
	if (lex->st == TSW)
	{
		sh_lex_tok_add(lex, sh_lex_tok_new(lex->st, off, l,
			ft_strndup(lex->in->str + off, l)));
	}
	else
		sh_lex_tok_add(lex, sh_lex_tok_new(lex->st, off, l, NULL));
}