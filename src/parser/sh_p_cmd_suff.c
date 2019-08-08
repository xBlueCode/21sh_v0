#include "ftsh.h"

int		sh_p_cmd_suff(t_parser *p, t_btree **ast)
{
	t_list	*back;

	DP0
	back = p->tlook;
	if (sh_p_match(p, ast, TSTOK_WORD) && sh_p_cmd_suff_sub(p, ast))
		PRET(1)
	p->tlook = back;
	if (sh_p_io_redir(p, ast) && sh_p_cmd_suff_sub(p, ast))
		PRET(1)
	PRET(0)
}
int		sh_p_cmd_suff_sub(t_parser *p, t_btree **ast)
{
	t_list	*back;

	DP0
	if (!(back = p->tlook))
		PRET(1)
	if (sh_p_io_redir(p, ast) && sh_p_cmd_suff_sub(p, ast))
		PRET(1)
	p->tlook = back;
	if (sh_p_match(p, ast, TSTOK_WORD) && sh_p_cmd_suff_sub(p, ast))
		PRET(1)
	p->tlook = back;
	PRET(1)
}
