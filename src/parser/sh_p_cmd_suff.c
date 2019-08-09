#include "ftsh.h"

int		sh_p_cmd_suff(t_parser *p, t_btree **ast)
{
	t_list	*back;
	t_btree *cast;

	DP0
	SHP_CAST_INIT(SH_GR_CMD_SUFF)
	back = p->tlook;
	if (sh_p_match(p, &cast, TSTOK_WORD)
		&& sh_p_cmd_suff_sub(p, SHP_CAST_R))
		PRET(1)
	p->tlook = back;
	if (sh_p_io_redir(p, SHP_CAST_L)
		&& sh_p_cmd_suff_sub(p, SHP_CAST_R))
		PRET(1)
	PRET(0)
}
int		sh_p_cmd_suff_sub(t_parser *p, t_btree **ast)
{
	t_list	*back;
	t_btree *cast;

	DP0
	SHP_CAST_INIT(SH_GR_CMD_SUFF_SUB)
	if (!(back = p->tlook))
		PRET(1)
	if (sh_p_io_redir(p, SHP_CAST_L)
		&& sh_p_cmd_suff_sub(p, SHP_CAST_R))
		PRET(1)
	p->tlook = back;
	if (sh_p_match(p, &cast, TSTOK_WORD) // TODO
		&& sh_p_cmd_suff_sub(p, SHP_CAST_R))
		PRET(1)
	p->tlook = back;
	PRET(1)
}
