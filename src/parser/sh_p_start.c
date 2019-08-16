#include "ftsh.h"

void	sep(t_list *e)
{
	t_com_cmd com_cmd;

	ft_printf("sep\n");
	if (!e)
		ft_printf("ELEM NULL\n");
	com_cmd = *((t_com_cmd*)(e->content));
	if (!e->content)
		ft_printf("content NULL\n");
	else if (!com_cmd.sep)
		ft_printf("sep NULL");
	else if (!com_cmd.sep->str)
		ft_printf("sep->str NULL");
	else
		ft_putendl(com_cmd.sep->str);
}

int 	sh_p_start(t_lex *lex)
{
	t_parser	p;
	t_btree		*ast;
	t_com_cmds	*com_cmds;

	p.tbase = lex->tlst;
	p.tlook = lex->tlst;
	p.tlast = lex->tlst;
	p.lev = 0;
//	ast = ft_btreenew(NULL, 0);
//	ast->op = SH_GR_START;
	ft_btreeinit(&ast, NULL, 0, SH_GR_START);
	sh_p_program(&p, &(ast->left));
	if (p.tlook && p.tlook->content)
	{
		//ast->left = ft_btreenew(NULL, 0);
		//ast->leftop = SH_GR_START;
		ft_printf("\nParsing Error at: ");
		DPTOKPUT(((t_token*)p.tlook->content))
		ft_printf(C_RED"Near : '%c'\n"T_END, lex->in->str[((t_token*)p.tlook->content)->p]);
	}
	else
	{
		ft_btreeapp_prefix(ast, test_sh_p_astapp);
		com_cmds = sh_g_com_cmds(ast->left->left);
		/*
		ft_printf("Separators: \n");
		if (com_cmds)
			ft_lstiter(com_cmds->lst_com_cmd, &sep);
		else
			ft_printf("Failed to build com_cmds !!!!\n");
		 */
		sh_g_com_cmds_put(com_cmds, 0);
		t_sh sh;
		sh.inter = 1;
		sh.term = 0;
		sh.pgid = -1;
		sh.jc = ft_memalloc(sizeof(t_jcon));
		sh.jc->cind = -1;
		//sh.jc->jlev = -1;
		sh.jc->jobs = NULL;
		sh.jc->cjob = NULL;

		return (sh_e_com_cmds(&sh, com_cmds, 0));
	}
	return (0);
}
