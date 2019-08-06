#include "ftsh.h"

int		sh_p_redir_list(t_parser *p, t_btree *ast)
{
	DP0
	return (sh_p_io_redir(p, ast) && sh_p_redir_list_sub(p, ast));
}

int		sh_p_redir_list_sub(t_parser *p, t_btree *ast)
{
	t_list	*back;

	DP0
	if (!(back = p->tlook))
		PRET(1)
	if (sh_p_io_redir(p, ast) && sh_p_redir_list_sub(p, ast))
		PRET(1)
	p->tlook = back;
	PRET(1)
}
