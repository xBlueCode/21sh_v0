#include "ftsh.h"

int				sh_p_program(t_parser *p, t_btree *ast)
{
	p_lev = 0;
	DP0
	if (!sh_p_lbreak(p, ast))
		PRET(0)
	if (sh_p_complete_cmds(p, ast)
		&& sh_p_lbreak(p, ast))
		PRET(1)
	PRET(1)
}
