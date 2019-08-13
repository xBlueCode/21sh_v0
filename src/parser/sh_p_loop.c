#include "ftsh.h"

int				sh_p_loop(t_parser *p, t_btree **ast) // TODO: deprecated !
{
	(void)p;
	(void)ast;
	return (0);
}

int				sh_p_while_clause(t_parser *p, t_btree **ast)
{
	t_btree *cast;

	DP0
	SHP_CAST_INIT(SH_GR_WHILE_CLAUSE)
	if (sh_p_match(p, NULL, TSRW_WHILE))
	{
		if (sh_p_comp_list(p, SHP_CAST_L) && sh_p_do_group(p, SHP_CAST_R))
			PRET(1);
		PRET(0)
	}
	PRET(0)
}

int				sh_p_until_clause(t_parser *p, t_btree **ast)
{
	t_btree *cast;

	DP0
	SHP_CAST_INIT(SH_GR_UNTIL_CLAUSE)
	if (sh_p_match(p, NULL, TSRW_UNTIL))
	{
		if (sh_p_comp_list(p, SHP_CAST_L) && sh_p_do_group(p, SHP_CAST_R))
			PRET(1);
		PRET(0)
	}
	PRET(0)
}
