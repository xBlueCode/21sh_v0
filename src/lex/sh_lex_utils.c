#include "libft.h"
#include "sh_lex.h"

int		sh_lex_isinname(char c)
{
	return (c == '_' || ft_isalnum(c));
}

int 	sh_lex_tok_isdelim(char c)
{
	if (!c)
		return (1);
	return (ft_strchr(SH_LEX_SEPSET_X, c) || ft_isspace(c));
}

t_token	*sh_lex_tok_last(t_lex *lex)
{
	if (!lex)
		return (NULL);
	return (lex->tokend);
}

t_token	*sh_lex_tokdup(t_token *t)
{
	if (!t)
		return (NULL);
	return (sh_lex_tok_new(t->t, t->p, t->l,
		!t->val ? NULL : t->val->str)); // TODO: check memory leaks
}
