#include "ftsh.h"

int		sh_p_cb_group(t_parser *p, t_btree *ast)
{
	DP0
	/*
	return (sh_p_match(p, ast, TSCBL)
		&& sh_p_comp_list(p, ast)
		&& sh_p_match(p, ast, TSBR));
	 */
	if (sh_p_match(p, ast, TSCBL)
		&& sh_p_comp_list(p, ast) && sh_p_match(p, ast, TSBR))
		PRET(1)
	PRET(0)
}

//int		sh_p_do_group(t_parser *p, t_btree *ast);
