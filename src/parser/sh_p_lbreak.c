#include "ftsh.h"

int		sh_p_nl_list(t_parser *p, t_btree *ast)
{
	DP0
	if (sh_p_match(p, ast, TSNL) && sh_p_nl_list_sub(p, ast))
		PRET(1);
	PRET(0);
}

int		sh_p_nl_list_sub(t_parser *p, t_btree *ast)
{
	t_list	*back;

	DP0
	if (!(back = p->tlook))
		PRET(1)
	if (sh_p_match(p, ast, TSNL))
	{
		if (sh_p_nl_list_sub(p, ast))
			PRET(1)
		PRET(1)
	}
	p->tlook = back;
	PRET(1);
}

int		sh_p_lbreak(t_parser *p, t_btree *ast)
{
	DP0
	if (!p->tlook)
		PRET(1)
	if (sh_p_nl_list(p, ast))
		PRET(1)
	PRET(1)
}