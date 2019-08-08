#include "ftsh.h"

int		sh_p_complete_cmds(t_parser *p, t_btree **ast)
{
	DP0
	if (sh_p_complete_cmd(p, ast) && sh_p_complete_cmds_sub(p, ast))
	{
		//sh_p_lookshift(p);
		PRET(1)
	}

	PRET(0)
}

int		sh_p_complete_cmds_sub(t_parser *p, t_btree **ast)
{
	DP0
	if (!p->tlook)
		PRET(1)
	if (sh_p_nl_list(p, ast))
	{
		if (sh_p_complete_cmd(p, ast) && sh_p_complete_cmds_sub(p, ast))
			PRET(1)
		PRET(0)
	}
	PRET(1)
}

int		sh_p_complete_cmd(t_parser *p, t_btree **ast)
{
	DP0
	//if (!p->tlook)
	//	PRET(0)
	if (sh_p_list(p, ast))
	{
		if (sh_p_sep_op(p, ast))
			PRET(1)
		PRET(1)
	}
	PRET(0)
	//sh_p_lookshift(p);
	//PRET(1)
}
