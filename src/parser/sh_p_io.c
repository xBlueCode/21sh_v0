#include "ftsh.h"

int		sh_p_io_redir(t_parser *p, t_btree **ast)
{
	DP0
	if (sh_p_match(p, ast, TSION))
	{
		if (sh_p_io_file(p, ast) || sh_p_io_here(p, ast))
			PRET(1)
		PRET(0)
	}
	if (sh_p_io_file(p, ast) || sh_p_io_here(p, ast))
		PRET(1)
	PRET(0)
}

int		sh_p_io_file(t_parser *p, t_btree **ast)
{
	DP0
	if (sh_p_match(p, ast, TSL)
		|| sh_p_match(p, ast, TSL_A)
		|| sh_p_match(p, ast, TSG)
		|| sh_p_match(p, ast, TSG_A)
		|| sh_p_match(p, ast, TSG2)
		|| sh_p_match(p, ast, TSL_G)
		|| sh_p_match(p, ast, TSG_O)
		)
	{
		if (sh_p_filename(p, ast))
			PRET(1)
		PRET(0)
	}
	PRET(0)
}

int		sh_p_filename(t_parser *p, t_btree **ast)
{
	DP0
	if (sh_p_match(p, ast, TSTOK_WORD)) //TODO: Rule 2
		PRET(1);
	PRET(0)
}

int		sh_p_io_here(t_parser *p, t_btree **ast)
{
	DP0
	if (sh_p_match(p, ast, TSL2)) // TODO: Implement <<-
	{
		if (sh_p_here_end(p, ast))
			PRET(1)
		PRET(0)
	}
	PRET(0)
}

int		sh_p_here_end(t_parser *p, t_btree **ast)
{
	DP0
	if (sh_p_match(p, ast, TSTOK_WORD)) // Apply Rule 3
		PRET(1);
	PRET(0);
}
