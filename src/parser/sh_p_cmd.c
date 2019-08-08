#include "ftsh.h"

int				sh_p_cmd(t_parser *p, t_btree **ast)
{
	t_list	*back;

	DP0
	back = p->tlook;
	if (sh_p_comp_cmd(p, ast))
	{
		sh_p_redir_list(p, ast);
		PRET(1)
	}
	p->tlook = back;
	if (sh_p_simp_cmd(p, ast))
		PRET(1)
	//TODO : func_def
	PRET(0)
}

int				sh_p_comp_cmd(t_parser *p, t_btree **ast)
{
	DP0
	if (sh_p_cb_group(p, ast))
		PRET(1)
	if (sh_p_subsh(p, ast))
		PRET(1)
	PRET(0)
}
