#include "ftsh.h"

int 	sh_p_start(t_lex *lex)
{
	t_parser	p;
	t_btree		*ast;

	p.tbase = lex->tlst;
	p.tlook = lex->tlst;
	p.tlast = lex->tlst;
	p.lev = 0;
	ast = ft_btreenew(NULL, 0);
	ast->op = SH_GR_START;

	sh_p_program(&p, ast);
	if (p.tlook && p.tlook->content)
	{
		//ast->left = ft_btreenew(NULL, 0);
		//ast->leftop = SH_GR_START;
		ft_printf("\nParsing Error at: ");
		DPTOKPUT(((t_token*)p.tlook->content))
		ft_printf(C_RED"Near : '%c'\n"T_END, lex->in->str[((t_token*)p.tlook->content)->p]);
	}
	return (0);
}
