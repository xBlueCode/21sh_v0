#include "libft.h"
#include "sh_lex.h"

t_token			*sh_lex_tok_new(int type, ssize_t pos, int len, char *xme)
{
	t_token		*tok;

	if (!(tok = (t_token*)ft_memalloc(sizeof(t_token))))
		return (NULL);
	tok->t = type;
	tok->p = pos;
	tok->l = len;
	tok->val = ft_dstrset_str(xme);
	return (tok);
}

int				sh_lex_tok_free(t_token **ptok)
{
	ft_dstrfree(&(*ptok)->val);
	ft_memdel((void**)ptok);
	return (OK);
}