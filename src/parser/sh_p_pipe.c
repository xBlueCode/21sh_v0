#include "ftsh.h"


int		sh_p_pipeline(t_parser *p, t_btree **ast)
{
	DP0
	if (sh_p_match(p, ast, TSBANG))
	{
		if (sh_p_pipe_seq(p, ast))
			PRET(1)
		PRET(0)
	}
	else if (sh_p_pipe_seq(p, ast))
		PRET(1)
	else
		PRET(0)
}

int		sh_p_pipe_seq(t_parser *p, t_btree **ast)
{
	DP0
	if (sh_p_cmd(p, ast) && sh_p_pipe_seq_sub(p, ast))
		PRET(1)
	PRET(0)
}

int		sh_p_pipe_seq_sub(t_parser *p, t_btree **ast)
{
	t_list *back;

	DP0
	if (!(back = p->tlook))
		PRET(1)
	if (sh_p_match(p, ast, TSO) && sh_p_lbreak(p, ast) && sh_p_cmd(p, ast)
		&& sh_p_pipe_seq_sub(p, ast))
		PRET(1)
	p->tlook = back;
	PRET(1)
}
