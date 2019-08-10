#include "ftsh.h"

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
	return (com_cmd);
}

void			*sh_g_com_cmds(t_btree *ast)
{
	t_com_cmds	*com_cmds;
	t_com_cmd	*com_cmd;

	if (!ast ||
		(ast->op != SH_GR_COMPLETE_CMDS
		&& ast->op != SH_GR_COMPLETE_CMDS_SUB))
		return (0);
	com_cmds = sh_g_com_cmds_new();
	while (ast)
	{
		com_cmd = sh_g_com_cmd(ast->left);
		if (com_cmd)
			SHG_LSTADD(com_cmds, lst_com_cmd, com_cmd)
		else
			break;
		ast = ast->right;
	}
	return (com_cmds);
}

void			*sh_g_com_cmd(t_btree *ast)
{
	t_com_cmd	*com_cmd;
	t_and_or	*and_or;
	t_btree		*list;

	SHG_CHECK_AST(ast, SH_GR_COMPLETE_CMD)
	com_cmd = sh_g_com_cmd_new();
	list = ast->left;
	while (list)
	{
		if ((and_or = sh_g_and_or(list->left)))
			SHG_LSTADD(com_cmd, lst_and_or, and_or)
		if (list->data)
			ft_dstrins_ch(com_cmd->sep, -1, SHG_AST_TOK(list)->t);
		list = list->right;
	}
	return (com_cmd);
}

/*
void			*sh_g_and_or(t_btree *ast)
{
	t_and_or	and_or;
	t_pipe		pipe;

	if (!ast || ast->op != SH_GR_AND_OR)
		return (0);
	and_or.lst_pipe = NULL;
	and_or.sep = ft_dstrnew_max(2);
//	ast = ast->left;
	while (ast->left && ast->left->op == SH_GR_PIPELINE)
	{
		if (sh_g_pipe(ast->left, &and_or))
			ft_lst_addlast(&and_or.lst_pipe, ft_lstnew(&pipe, sizeof(t_pipe*)));
		if (ast->data)
			ft_dstrins_ch(and_or.sep, -1, ((t_token*)(ast->data))->t); // TODO: change to 0, 1, 2
		ast = ast->right;
	}
//	gr = &and_or;
	return (1);
}

void			*sh_g_pipe(t_btree *ast)
{
	t_pipe		pipe;
	t_btree		*pipe_sec;
	t_cmd		cmd;

	if (!ast || !gr || ast->op != SH_GR_PIPELINE)
		return (0);
	pipe.lst_cmd = NULL;
	pipe.neg = ast->data ? 1 : 0;
	pipe_sec = ast->left;
	while (pipe_sec)
	{
		if (sh_g_cmd(pipe_sec->left, &cmd))
			ft_lst_addlast(&pipe.lst_cmd, ft_lstnew(&cmd, sizeof(t_and_or*)));
		pipe_sec = pipe_sec->right;
	}
//	gr = &pipe;
	return (1);
}

void			*sh_g_cmd(t_btree *ast)
{
	t_cmd	cmd;
	t_redir	*redir;
	t_btree	*redir_list;
	t_btree	*ast_core;
//	void	*cmd_core;

	if (!ast || ast->op != SH_GR_CMD)
		return (0);
	cmd.lst_redir = NULL;
	redir_list = ast->right;
	ast_core = ast->left;
	while (redir_list)
	{
		if (sh_g_redir(redir_list->left, &redir))
			ft_lst_addlast(&cmd.lst_redir, ft_lstnew(&redir, sizeof(t_and_or*)));
		redir_list = redir_list->right;
	}
	if (ast_core)
	{
		ft_printf("      Adding simp cmd from %d in %d\n", ast_core->op, ast->op);
	}
//	gr = &cmd;
	return (1);
}

void			*sh_g_redir(t_btree *ast)
{
	t_redir	redir;
	t_btree	*ast_io;

	if (!ast || ast->op != SH_GR_IO_REDIR)
		return (0);
	if (ast->data)
		redir.ion = 21;
	else
		redir.ion = -42;
	ast_io = ast->left;
	if (ast_io)
	{
		if (ast_io->data)
			redir.op = ((t_token*)ast_io->data)->t;
		if (ast_io->left)
			redir.word = ft_strdup(((t_token*)ast_io->left->data)->val->str);
	}
//	gr = &redir;
	return (1);
}
*/