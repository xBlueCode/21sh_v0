/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_e_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 19:07:29 by abbesbes          #+#    #+#             */
/*   Updated: 2019/10/07 19:07:31 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftsh.h"

static int	sh_e_pipe_cmd(t_sh *sh, t_list *cmd_lst, int *fifo)
{
	t_cmd	*cmd;
	int		ret;

	cmd = cmd_lst->content;
	ft_dup_stdioe_copy(cmd->stdioe, 0);
	if (fifo[0] != -1)
		cmd->stdioe[0] = fifo[0];
	if (cmd_lst->next)
	{
		if (pipe(fifo) < 0)
		{
			ft_printf("error: pipe()\n");
			exit(1);
		}
		cmd->stdioe[1] = fifo[1];
	}
	ret = sh_e_cmd(sh, cmd);
	return (ret);
}

int			sh_e_pipe(t_sh *sh, void *gr)
{
	t_list	*cmd_lst;
	int		fifo[2];
	int		ret;
	int		state;

	DF0;
	if ((ret = 0) || !sh || !gr)
		return (0);
	cmd_lst = ((t_pipe*)gr)->lst_cmd;
	fifo[0] = -1;
	while (cmd_lst)
	{
		ret = sh_e_pipe_cmd(sh, cmd_lst, fifo);
		cmd_lst = cmd_lst->next;
	}
	ret = sh_e_pipe_wait(sh, gr, WUNTRACED, &state);
	return (ret);
}

int			sh_e_pipe_wait(t_sh *sh, void *gr, int op, int *state)
{
	t_pipe	*pip;
	int		ret;

	DF0;
	if ((ret = 0) || !sh || !gr)
		return (0);
	pip = (t_pipe*)gr;
	return (sh_e_cmd_lst_wait(sh, pip->lst_cmd, op, state));
}

int			sh_e_cmd_lst_wait(t_sh *sh, t_list *cmd_lst, int op, int *state)
{
	int		nstate;
	int		ret;

	DF0;
	if (!cmd_lst)
	{
		*state = SH_E_STATE_EXEC;
		return (0);
	}
	ret = sh_e_cmd_lst_wait(sh, cmd_lst->next, op, &nstate);
	if (nstate == SH_E_STATE_EXEC)
		ret = sh_e_cmd_wait(sh, cmd_lst->content, op, state);
	else if (nstate == SH_E_STATE_STOP)
		sh_e_cmd_kill(sh, cmd_lst->content, SIGQUIT);
	else
		sh_e_cmd_kill(sh, cmd_lst->content, SIGQUIT);
	return (ret);
}

int			sh_e_cmd(t_sh *sh, void *gr)
{
	t_cmd	*cmd;
	int		ret;
	int		stdioe[3];

	DF0;
	if (!sh || !gr)
		return (0);
	cmd = (t_cmd*)gr;
	ft_dup_stdioe_copy(stdioe, 0);
	ft_dup_stdioe_set(cmd->stdioe, 1);
	sh_e_redirect(cmd->lst_redir);
	ret = cmd->exec(sh, cmd->core);
	ft_dup_stdioe_set(stdioe, 1);
	return (ret);
}
