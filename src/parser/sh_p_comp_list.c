#include "ftsh.h"

int				sh_p_comp_list(t_parser *p, t_btree **ast)
{
	DP0
	if (sh_p_lbreak(p, ast) && sh_p_term(p, ast))
	{
		sh_p_sep(p, ast);
		PRET(1)
	}
	PRET(0)
}
