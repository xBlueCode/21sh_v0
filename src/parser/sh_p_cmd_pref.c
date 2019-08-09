#include "ftsh.h"

int		sh_p_cmd_pref(t_parser *p, t_btree **ast)
{
	t_list	*back;
	t_btree *cast;

	DP0
	SHP_CAST_INIT(SH_GR_CMD_PREF)
	back = p->tlook;
	if (sh_p_io_redir(p, SHP_CAST_L)
		&& sh_p_cmd_pref_sub(p, SHP_CAST_R))
		PRET(1)
	p->tlook = back;
	cast->left = NULL;
	if (sh_p_match(p, &cast, TSTOK_ASS_WORD)
		&& sh_p_cmd_pref_sub(p, SHP_CAST_R))
		PRET(1)
	PRET(0)
}
int		sh_p_cmd_pref_sub(t_parser *p, t_btree **ast)
{
	t_list	*back;
	t_btree *cast;

	DP0
	SHP_CAST_INIT(SH_GR_CMD_PREF_SUB)
	if (!(back = p->tlook))
		PRET(1)
	if (sh_p_io_redir(p, SHP_CAST_L)
		&& sh_p_cmd_pref_sub(p, SHP_CAST_R))
		PRET(1)
	p->tlook = back;
	cast->left = NULL;
	if (sh_p_match(p, &cast, TSTOK_ASS_WORD) // TODO
		&& sh_p_cmd_pref_sub(p, SHP_CAST_R))
		PRET(1)
	p->tlook = back;
	PRET(1)
}
