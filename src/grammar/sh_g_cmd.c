/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_g_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 19:12:57 by abbesbes          #+#    #+#             */
/*   Updated: 2019/10/07 19:12:59 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftsh.h"

extern int		g_g_putlev;

void			*sh_g_cmd_new(void)
{
	t_cmd *cmd;

	SHG_CHECK_MALL(cmd);
	cmd->core = NULL;
	cmd->lst_redir = NULL;
	cmd->type = -1;
	return (cmd);
}

void			sh_g_cmd_free(void **g)
{
	t_cmd **cmd;

	cmd = (t_cmd**)g;
	ft_lst_free(&(*cmd)->lst_redir, &sh_g_redir_free);
	(*cmd)->tfree((void**)&(*cmd)->core);
	FT_MEMDEL(*g);
}

static void		sh_g_cmd_update(t_cmd *cmd, t_btree *ast_core)
{
	cmd->type = ast_core->op;
	cmd->core = ((void*(*)(t_btree*))sh_g_cmd_core(cmd->type))(ast_core);
	cmd->exec = sh_g_cmd_core_get_exec(cmd->type);
	cmd->wait = sh_g_cmd_core_get_wait(cmd->type);
	cmd->kill = sh_g_cmd_core_get_kill(cmd->type);
	cmd->tfree = sh_g_cmd_core_get_free(cmd->type);
}

void			*sh_g_cmd(t_btree *ast)
{
	t_cmd	*cmd;
	t_btree	*ast_redirlist;
	t_btree	*ast_core;
	t_redir	*redir;

	SHG_CHECK_AST(ast, SH_GR_CMD);
	cmd = sh_g_cmd_new();
	if (!ast->left)
		return (NULL);
	if (!(ast_core = ast->left->op == SH_GR_COMP_CMD
		? ast->left->left : ast->left))
		return (NULL);
	sh_g_cmd_update(cmd, ast_core);
	ast_redirlist = ast->right;
	while (ast_redirlist)
	{
		if ((redir = sh_g_redir(ast_redirlist->left)))
			SHG_LSTADD_FREE(cmd, lst_redir, redir);
		ast_redirlist = ast_redirlist->right;
	}
	if (!cmd->core)
		return (NULL);
	return (cmd);
}

void			sh_g_cmd_put(void *g, int op)
{
	t_cmd *cmd;

	if (!g)
		return ;
	g_g_putlev++;
	SHG_PUT_CASTVAR(cmd, g, t_cmd*, op);
	SHG_PUT_PRINTF("command:\n", g_g_putlev++);
	SHG_PUT_PRINTF("command_core:\n", g_g_putlev);
	((void(*)(void*, int))sh_g_cmd_core_put(cmd->type))(cmd->core, 0);
	SHG_PUT_PRINTF("redirect_list:\n", g_g_putlev);
	ft_lstiterop(cmd->lst_redir, SHG_PUT_CASTFUN(sh_g_redir_put), 1);
	g_g_putlev -= 2;
}
