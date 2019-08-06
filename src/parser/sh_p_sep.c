#include "ftsh.h"

int		sh_p_sep_op(t_parser *p, t_btree *ast)
{
	DP0
	if (sh_p_match(p, ast, TSA) || sh_p_match(p, ast, TSSC))
		PRET(1)
	PRET(0)
}

int		sh_p_sep(t_parser *p, t_btree *ast)
{
	DP0
	if ((sh_p_sep_op(p, ast) && sh_p_lbreak(p, ast)) || sh_p_nl_list(p, ast))
		PRET(1)
	PRET(0)
}

int		sh_p_seq_sep(t_parser *p, t_btree *ast)
{
	DP0
	if ((sh_p_match(p, ast, TSSC) && sh_p_lbreak(p, ast))
		|| sh_p_nl_list(p, ast))
		PRET(1)
	PRET(0)
}

