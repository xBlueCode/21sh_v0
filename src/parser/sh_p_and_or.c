#include "ftsh.h"

int		sh_p_and_or(t_parser *p, t_btree **ast)
{
	DP0
	if (sh_p_pipeline(p, ast) && sh_p_and_or_sub(p, ast))
		PRET(1)
		//return (sh_p_lookshift(p));
	PRET(0)
}
int		sh_p_and_or_sub(t_parser *p, t_btree **ast)
{
	t_list	*back;

	DP0
	if (!(back = p->tlook))
		PRET(1)
	if (sh_p_match(p, ast,TSA2))
	{
		if (sh_p_lbreak(p, ast) && sh_p_pipeline(p, ast)
			&& sh_p_and_or_sub(p, ast))
			PRET(1)
		PRET(0)
	}
	if (sh_p_match(p, ast, TSO2))
	{
		if (sh_p_lbreak(p, ast) && sh_p_pipeline(p, ast)
			&& sh_p_and_or_sub(p, ast))
			PRET(1)
		PRET(0)
	}
	PRET(1)
}
