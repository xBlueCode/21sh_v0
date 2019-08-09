#include "ftsh.h"

int				sh_p_program(t_parser *p, t_btree **ast)
{
	t_btree *cast;

	p_lev = 0;
	DP0
	SHP_CAST_INIT(SH_GR_PROGRAM) // It does init cast, inc level, and print current action
	if (!sh_p_lbreak(p, NULL))
		PRET(0) // TODO: add free_btree cast when RET 0
	if (sh_p_complete_cmds(p, SHP_CAST_L))
	{
		if (sh_p_lbreak(p, NULL))
			PRET(1);
		PRET(1)
	}
	PRET(0) // TODO : It was 1
}
