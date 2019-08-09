#include "ftsh.h"

int		sh_p_list(t_parser *p, t_btree **ast)
{
	t_btree *cast;

	DP0
	SHP_CAST_INIT(SH_GR_LIST)
	if (sh_p_and_or(p, SHP_CAST_L) && sh_p_list_sub(p, SHP_CAST_R))
		PRET(1)
		//return (sh_p_lookshift(p));
	PRET(0)
}

int		sh_p_list_sub(t_parser *p, t_btree **ast)
{
	t_btree *cast;
	t_btree *fast;
	t_list *back;

	DP0
	SHP_CAST_INIT(SH_GR_LIST_SUB)
	fast = ft_btreenew(NULL, 0);
	if (!(back = p->tlook))
		PRET(1)
	if (sh_p_sep_op(p, &fast)) // TODO: TBD in data
	{
		cast->data = fast->data;
		cast->dsize = fast->dsize;
		if (sh_p_and_or(p, SHP_CAST_L) && sh_p_list_sub(p, SHP_CAST_R))
			PRET(1);
		p->tlook = back;
		PRET(1)
	}
	PRET(1)
}
