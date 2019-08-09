#include "ftsh.h"

int		sh_p_sep_op(t_parser *p, t_btree **ast)
{
	t_btree *cast;

	DP0
	SHP_CAST_INIT(SH_GR_SEP_OP)
	if (sh_p_match(p, &cast, TSA) || sh_p_match(p, &cast, TSSC))
		PRET(1)
	PRET(0)
}

int		sh_p_sep(t_parser *p, t_btree **ast)
{
	t_btree *cast;
	t_btree *fast;

	DP0
	SHP_CAST_INIT(SH_GR_SEP)
	fast = ft_btreenew(NULL, 0);
	if (sh_p_sep_op(p, &fast))
	{
		cast->data = fast->data;
		cast->dsize = fast->dsize;
		if (sh_p_lbreak(p, NULL))
			PRET(1)
	}
	else if (sh_p_nl_list(p, NULL))
		PRET(1)
	PRET(0)
}

int		sh_p_seq_sep(t_parser *p, t_btree **ast)
{
	t_btree *cast;

	DP0
	SHP_CAST_INIT(SH_GR_SEQ_SEP)
	if ((sh_p_match(p, &cast, TSSC) && sh_p_lbreak(p, NULL))
		|| sh_p_nl_list(p, NULL))
		PRET(1)
	PRET(0)
}
