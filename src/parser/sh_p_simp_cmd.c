#include "ftsh.h"

int		sh_p_simp_cmd(t_parser *p, t_btree **ast)
{
//	t_list	*back[3]; // TODO : Replace back vars with the array
	t_list	*back0;
	t_list	*back1;
	t_list	*back2;
	t_btree *cast;
	t_btree *fast;

	DP0
	SHP_CAST_INIT(SH_GR_SIMP_CMD)
	fast = ft_btreenew(NULL, 0);
	back0 = p->tlook;
	if (sh_p_cmd_pref(p, SHP_CAST_L))
	{
		back1 = p->tlook;
		if (sh_p_cmd_word(p, &fast)) // TODO
		{
			back2 = p->tlook;
			cast->data = fast->data;
			cast->dsize = fast->dsize;
			if (sh_p_cmd_suff(p, SHP_CAST_R))
				PRET(1)
			p->tlook = back2;
			PRET(1)
		}
		p->tlook = back1;
		PRET(1)
	}
	p->tlook = back0; // TODO: Check if it should return the back
	if (sh_p_cmd_name(p, &fast)) // TODO
	{
		cast->data = fast->data;
		cast->dsize = fast->dsize;
		back1 = p->tlook;
		if (sh_p_cmd_suff(p, SHP_CAST_R))
			PRET(1)
		p->tlook = back1;
		PRET(1)
	}
	PRET(0)
}

int		sh_p_cmd_name(t_parser *p, t_btree **ast)
{
	t_btree *cast;

	DP0
	SHP_CAST_INIT(SH_GR_CMD_NAME)
	//p->tlook = p->tlook->next;
	if (sh_p_match(p, &cast, TSTOK)) // TODO
		PRET(1)
	PRET(0)
}

int		sh_p_cmd_word(t_parser *p, t_btree **ast)
{
	t_btree *cast;

	DP0
	SHP_CAST_INIT(SH_GR_CMD_WORD)
	p->tlook = p->tlook->next;
	if (sh_p_match(p, &cast, TSTOK)) // TODO
		PRET(1)
	PRET(0)
}
