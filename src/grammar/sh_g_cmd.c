#include "ftsh.h"


void			*sh_g_cmd_new(void)
{
	t_cmd *cmd;

	SHG_CHECK_MALL(cmd)
	cmd->core = NULL;
	cmd->lst_redir = NULL;
	cmd->type = -1;
	return (cmd);
}

void			sh_g_cmd_put(t_cmd *cmd)
{
	ft_printf("command:\n", cmd->type);
	ft_printf("command_core (%d):\n", cmd->type);
	//sh_g_cmd_core_put(cmd->core);
	ft_putendl("redirect_list");
	//ft_lstiter(cmd->lst_redir, sh_g_redir_put);

}

void			*sh_g_cmd(t_btree *ast)
{
	t_cmd	*cmd;
	t_btree	*ast_redirlist;
	t_redir	*redir;

	SHG_CHECK_AST(ast, SH_GR_CMD)
	cmd = sh_g_cmd_new();
	cmd->core = sh_g_cmd_core(ast->left);
	ast_redirlist = ast->right;
	while (ast_redirlist)
	{
		if ((redir = sh_g_redir(ast_redirlist->left)))
			SHG_LSTADD(cmd, lst_redir, redir);
		ast_redirlist = ast_redirlist->right;
	}
	return (cmd);
}
