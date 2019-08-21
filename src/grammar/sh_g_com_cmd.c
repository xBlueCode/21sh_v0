#include "ftsh.h"

int 			g_g_putlev = 0;

void			*sh_g_com_cmds_new(void)
{
	t_com_cmds	*com_cmds;

	SHG_CHECK_MALL(com_cmds)
	com_cmds->lst_com_cmd = NULL;
	return (com_cmds);
}

void			*sh_g_com_cmd_new(void)
{
	t_com_cmd	*com_cmd;

	SHG_CHECK_MALL(com_cmd)
	com_cmd->lst_and_or = NULL;
	com_cmd->sep = ft_dstrnew_max(2);
	com_cmd->gr = -1;
	return (com_cmd);
}

void			*sh_g_com_cmds(t_btree *ast)
{
	t_com_cmds	*com_cmds;
	t_com_cmd	*com_cmd;

	if (!ast ||
		(ast->op != SH_GR_COMPLETE_CMDS
		&& ast->op != SH_GR_COMPLETE_CMDS_SUB))
		return (NULL);
	com_cmds = sh_g_com_cmds_new();
	while (ast)
	{
		if (!(com_cmd = sh_g_com_cmd(ast->left)))
			break ;
		com_cmd->gr = SH_GR_COMPLETE_CMD;
		SHG_LSTADD(com_cmds, lst_com_cmd, com_cmd)
		ast = ast->right;
	}
	if (!com_cmds->lst_com_cmd)
		return (NULL);
	return (com_cmds);
}

void			*sh_g_com_cmd(t_btree *ast) // takes com_cmd, and com_list
{
	t_com_cmd	*com_cmd;
	t_and_or	*and_or;
	t_btree		*list;

	//SHG_CHECK_AST(ast, SH_GR_COMPLETE_CMD) // TODO: || _COMP_LIST
	if (!ast || (ast->op != SH_GR_COMPLETE_CMD && ast->op != SH_GR_COMP_LIST))
		return (NULL);
	com_cmd = sh_g_com_cmd_new();
	list = ast->left; // term_std
	while (list)
	{
		if ((and_or = sh_g_and_or(list->left)))
			SHG_LSTADD(com_cmd, lst_and_or, and_or)
		if (list->data) // list & term_std must store the sep in data
			ft_dstrins_ch(com_cmd->sep, -1, SHG_AST_TOK(list)->t);
		else // TODO: FOR COMP_LIST but it must be compatible with complete_cmd
			ft_dstrins_ch(com_cmd->sep, -1, TSFAKE);
		list = list->right;
	}
	if (!com_cmd->lst_and_or)
		return (NULL);
	return (com_cmd);
}

void			sh_g_com_cmds_put(void*g, int op)
{
	t_com_cmds *com_cmds;

	if (!g)
		return ;
	//com_cmds = (t_com_cmds*)g;
	SHG_PUT_CASTVAR(com_cmds, g, t_com_cmds*, op)
	SHG_PUT_PRINTF("complete_commands:\n", g_g_putlev);
	ft_lstiterop(com_cmds->lst_com_cmd, SHG_PUT_CASTFUN(sh_g_com_cmd_put), 1);
}

void			sh_g_com_cmd_put(void*g, int op)
{
	t_com_cmd	*com_cmd;
	int 		i;

	if (!g)
		return ;
	g_g_putlev++;
	SHG_PUT_CASTVAR(com_cmd, g, t_com_cmd*, op);
	SHG_PUT_PRINTF("complete_command: ", g_g_putlev++);
	ft_printf("GROUP(%d)\n", com_cmd->gr);
	SHG_PUT_PRINTF("and_or_list:\n", g_g_putlev);
	ft_lstiterop(com_cmd->lst_and_or, SHG_PUT_CASTFUN(sh_g_and_or_put), 1);
	SHG_PUT_PRINTF("separators: ", g_g_putlev);
	i = -1;
	while (++i < com_cmd->sep->len)
		ft_putchar(com_cmd->sep->str[i] == TSSC ? ';' : '&');
	ft_putchar('\n');
	g_g_putlev -= 2;
}
