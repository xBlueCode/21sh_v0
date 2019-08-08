#include "ftsh.h"

int			sh_p_subsh(t_parser *p, t_btree **ast)
{
	DP0
	if (sh_p_match(p, ast, TSPL)
		&& sh_p_comp_list(p, ast) && sh_p_match(p, ast, TSPR))
		PRET(1);
	PRET(0);
}
