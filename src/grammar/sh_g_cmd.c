#include "ftsh.h"

extern int 		g_g_putlev;

void			*sh_g_cmd_new(void)
{
	t_cmd *cmd;

	SHG_CHECK_MALL(cmd)
	cmd->core = NULL;
	cmd->lst_redir = NULL;
	cmd->type = -1;
	//cmd->stdi = STDIN_FILENO;
	//cmd->stdo = STDOUT_FILENO;
	//cmd->stde = STDERR_FILENO;
	return (cmd);
}

void			sh_g_cmd_free(void**g)
{
	t_cmd **cmd;

	cmd = (t_cmd**)g;
	ft_lst_free(&(*cmd)->lst_redir, &sh_g_redir_free);
	(*cmd)->tfree((void**)&(*cmd)->core);
	FT_MEMDEL(*g);
}

void			*sh_g_cmd(t_btree *ast)
{
	t_cmd	*cmd;
	t_btree	*ast_redirlist;
	t_btree	*ast_core;
	t_redir	*redir;

	SHG_CHECK_AST(ast, SH_GR_CMD)
	cmd = sh_g_cmd_new();
	if (!ast->left)
		return (NULL); // TODO: free cmd
	if (!(ast_core = ast->left->op == SH_GR_COMP_CMD ? ast->left->left : ast->left))
		return (NULL); // TODO: free cmd
	cmd->type = ast_core->op;
	cmd->core = ((void*(*)(t_btree*))sh_g_cmd_core(cmd->type))(ast_core);
	cmd->exec = sh_g_cmd_core_get_exec(cmd->type);
	cmd->tfree = sh_g_cmd_core_get_free(cmd->type);
	ast_redirlist = ast->right;
	while (ast_redirlist)
	{
		if ((redir = sh_g_redir(ast_redirlist->left)))
			SHG_LSTADD_FREE(cmd, lst_redir, redir);
		ast_redirlist = ast_redirlist->right;
		//FT_MEMDEL(redir);
	}
	if (!cmd->core)
		return (NULL);
	return (cmd);
}

void			sh_g_cmd_put(void *g, int op)
{
	t_cmd *cmd;

	if (!g)
		return;
	g_g_putlev++;
	SHG_PUT_CASTVAR(cmd, g, t_cmd*, op)
	SHG_PUT_PRINTF("command:\n", g_g_putlev++);
	SHG_PUT_PRINTF("command_core:\n", g_g_putlev);
	((void(*)(void*, int))sh_g_cmd_core_put(cmd->type))(cmd->core, 0);
	SHG_PUT_PRINTF("redirect_list:\n", g_g_putlev);
	ft_lstiterop(cmd->lst_redir, SHG_PUT_CASTFUN(sh_g_redir_put), 1);
	g_g_putlev -= 2;
}