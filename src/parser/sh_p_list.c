#include "ftsh.h"

int		sh_p_list(t_parser *p, t_btree *ast)
{
	DP0
	if (sh_p_and_or(p, ast) && sh_p_list_sub(p, ast))
		PRET(1)
		//return (sh_p_lookshift(p));
	PRET(0)
}

int		sh_p_list_sub(t_parser *p, t_btree *ast)
{
	DP0
	t_list *back;

	if (!(back = p->tlook))
		PRET(1)
	/*
	if (sh_p_sep_op(p, ast) && sh_p_and_or(p, ast) && sh_p_list_sub(p, ast))
		PRET(1)
	 */

	if (sh_p_sep_op(p, ast))
	{
		if (sh_p_and_or(p, ast) && sh_p_list_sub(p, ast))
			PRET(1);
		p->tlook = back;
		PRET(1)
	}
	//return (sh_p_lookshift(p));
//	p->tlook = back;
	PRET(1)
}
