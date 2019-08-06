#include "ftsh.h"

int		sh_p_cb_group(t_parser *p, t_btree *ast)
{
	DP0
	/*
	return (sh_p_match(p, ast, TSCBL)
		&& sh_p_comp_list(p, ast)
		&& sh_p_match(p, ast, TSBR));
	 */
	PRET(sh_p_match(p, ast, TSCBL) && sh_p_comp_list(p, ast) && sh_p_match(p, ast, TSBR));
}

//int		sh_p_do_group(t_parser *p, t_btree *ast);
