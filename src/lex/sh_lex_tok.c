//
// Created by xbluecode on 24.05.19.
//

#include "libft.h"
#include "sh_lex.h"

t_token			*sh_lex_tok_set(int type, ssize_t pos, int len, char *xme)
{
	t_token		*tok;

	if (!(tok = (t_token*)ft_memalloc(sizeof(t_token))))
		return (NULL);
	tok->t = type;
	tok->p = pos;
	tok->l = len;
	tok->xme = xme;
}

int				sh_lex_tok_free(t_token **ptok)
{
	ft_memdel((void**)&(*ptok)->xme);
	ft_memdel((void**)ptok);
}