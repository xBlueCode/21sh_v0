#include "ftsh.h"

int				sh_p_term(t_parser *p, t_btree *ast)
{
	DP0
	//return (sh_p_and_or(p, ast) && sh_p_term_sub(p, ast));
	if (sh_p_and_or(p, ast) && sh_p_term_sub(p, ast))
		PRET(1);
	PRET(0);
}

int				sh_p_term_sub(t_parser *p, t_btree *ast)
{
	t_list *back;

	DP0
	if (!(back = p->tlook))
		PRET(1)
	if (sh_p_sep(p, ast) && sh_p_and_or(p, ast) && sh_p_term_sub(p, ast))
		PRET(1)
	p->tlook = back;
	PRET(1)
}
