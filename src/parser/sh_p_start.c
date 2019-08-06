#include "ftsh.h"

int 	sh_p_start(t_lex *lex)
{
	t_parser p;

	p.tbase = lex->tlst;
	p.tlook = lex->tlst;
	p.tlast = lex->tlst;
	p.lev = 0;

	sh_p_program(&p, NULL);
	if (p.tlook && p.tlook->content)
	{
		ft_printf("\nParsing Error at: ");
		DPTOKPUT(((t_token*)p.tlook->content))
		ft_printf(C_RED"Near : '%c'\n"T_END, lex->in->str[((t_token*)p.tlook->content)->p]);
	}
	return (0);
}
