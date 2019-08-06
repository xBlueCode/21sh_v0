#include "ftsh.h"

int		sh_p_simp_cmd(t_parser *p, t_btree *ast)
{
	t_list	*back0;
	t_list	*back1;
	t_list	*back2;

	DP0
	back0 = p->tlook;
	if (sh_p_cmd_pref(p, ast))
	{
		back1 = p->tlook;
		if (sh_p_cmd_word(p, ast))
		{
			back2 = p->tlook;
			if (sh_p_cmd_suff(p, ast))
				PRET(1)
			p->tlook = back2;
			PRET(1)
		}
		p->tlook = back1;
		PRET(1)
	}
	p->tlook = back0; // TODO: Check if it should return the back
	if (sh_p_cmd_name(p, ast))
	{
		back1 = p->tlook;
		if (sh_p_cmd_suff(p, ast))
			PRET(1)
		p->tlook = back1;
		PRET(1)
	}
	PRET(0)
}

int		sh_p_cmd_name(t_parser *p, t_btree *ast)
{
	(void)p;
	(void)ast;
	DP0
	//p->tlook = p->tlook->next;
	if (sh_p_match(p, ast, TSTOK))
		PRET(1)
	PRET(0)
}

int		sh_p_cmd_word(t_parser *p, t_btree *ast)
{
	(void)p;
	(void)ast;
	DP0
	p->tlook = p->tlook->next;
	if (sh_p_match(p, ast, TSTOK))
		PRET(1)
	PRET(0)
}
