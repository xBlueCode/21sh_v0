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

t_com_cmds 	*sh_p_start(t_lex *lex)
{
	t_parser	p;
	t_btree		*ast;
	t_com_cmds	*com_cmds;

	p.tlook = lex->tlst;
//	p.hd_key = lex->hd_val;
	p.hd_val = lex->hd_val;
	p.lev = 0;
	ft_btreeinit(&ast, NULL, 0, SH_GR_START);
	//DF_PFWAIT("prog <", 8)
	sh_p_program(&p, &(ast->left));
	//DF_PFWAIT("prog >", 8)
	if (p.tlook && p.tlook->content)
	{
		ft_printf(C_RED"\nParsing Error at: %d\n"T_END,
				(((t_token*)p.tlook->content)->p));
		DPTOKPUT(((t_token*)p.tlook->content))
		ft_btreefree(&ast, (t_free)&sh_lex_tok_tfree);
		//ft_printf(C_RED"Near : '%c'\n"T_END, lex->in->str[((t_token*)p.tlook->content)->p]);
	}
	else
	{
		//ft_btreeapp_prefix(ast, test_sh_p_astapp);
		if (!ast || !ast->left || !ast->left->left)
			return (NULL);
		//DF_PFWAIT("gram <", 8)
		com_cmds = sh_g_com_cmds(ast->left->left);
		DF_PFWAIT("gram >", 8)
		//sh_g_com_cmds_put(com_cmds, 0);
		//ft_btreefree(&ast, (t_free)sh_lex_tok_free);
		ft_btreefree(&ast, (t_free)&sh_lex_tok_tfree); // TODO: delay freeing
		return (com_cmds);
	}
	return (NULL);
}
