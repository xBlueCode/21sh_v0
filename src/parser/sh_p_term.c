#include "ftsh.h"

int				sh_p_term(t_parser *p, t_btree **ast)
{
	t_btree *cast;

	DP0
	SHP_CAST_INIT(SH_GR_TERM)
	//return (sh_p_and_or(p, ast) && sh_p_term_sub(p, ast));
	if (sh_p_and_or(p, SHP_CAST_L) && sh_p_term_sub(p, SHP_CAST_R))
		PRET(1);
	PRET(0);
}

int				sh_p_term_sub(t_parser *p, t_btree **ast)
{
	t_list *back;
	t_btree *cast;
	t_btree *fast;

	DP0
	SHP_CAST_INIT(SH_GR_TERM_SUB)
	fast = ft_btreenew(NULL, 0);
	if (!(back = p->tlook))
		PRET(1)
	if (sh_p_sep(p, &fast) // TODO: TBD
		&& sh_p_and_or(p, SHP_CAST_L)
		&& sh_p_term_sub(p, SHP_CAST_R))
	{
		cast->data = fast->data;
		cast->dsize = fast->dsize;
		PRET(1)
	}
	p->tlook = back;
	PRET(1) // TODO: Check CAST in case of empty
}
