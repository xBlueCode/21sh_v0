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

int			sh_e_pipe(t_sh *sh, void *gr)
{
	t_pipe	*pip;
	t_list	*cmd_lst;
	t_cmd	*cmd;
	int 	fifo[2];
	int 	ret;
	int		state;

	DF0;
	if ((ret = 0) || !sh || !gr)
		return (0);
	pip = (t_pipe*)gr;
	cmd_lst = pip->lst_cmd;
	fifo[0] = -1;
	while (cmd_lst)
	{
		cmd = cmd_lst->content;
		ft_dup_stdioe_copy(cmd->stdioe, 0);
		if (fifo[0] != -1)
			cmd->stdioe[0] = fifo[0];
		if (cmd_lst->next)
		{
			//ft_printf(C_MGN"--> piping ...\n"T_END);
			if (pipe(fifo) < 0)
			{
				ft_printf("error: pipe()\n");
				exit(1);
			}
			//ft_printf(C_GRN"PIPE (%d, %d)\n"T_END, fifo[0], fifo[1]);
			cmd->stdioe[1] = fifo[1];
			//if (pip->op->str[0] == TSO_A)
			//	ft_dup2(fifo[1], STDERR_FILENO, 0);
			//ft_dstrdel_n(pip->op, 0, 1);
		}
		ret = sh_e_cmd(sh, cmd);
		cmd_lst = cmd_lst->next;
	}
	//while (wait(&ret) > -1)
	//	ret = WEXITSTATUS(ret);
	//ret = pip->neg ? pip->neg - ret : ret; // TODO: recheck
	ret = sh_e_pipe_wait(sh, gr, WUNTRACED, &state);
	return (ret);
}

int			sh_e_pipe_wait(t_sh *sh, void *gr, int op, int *state)
{
	t_pipe	*pip;
//	t_list	*cmd_lst;
//	t_cmd	*cmd;
//	int 	fifo[2];
	int 	ret;

	DF0;
	if ((ret = 0) || !sh || !gr)
		return (0);
	pip = (t_pipe*)gr;
	return (sh_e_cmd_lst_wait(sh, pip->lst_cmd, op, state)); // TODO: check neg
	//if (state == SH_E_STATE_DONE)
}


int			sh_e_cmd_lst_wait(t_sh *sh, t_list *cmd_lst, int op, int *state)
{
	int		nstate;
	int 	ret;

	DF0;
	if (!cmd_lst) // TODO: recheck condition
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
	int 	ret;
	int 	stdioe[3];

	DF0;
	if (!sh || !gr)
		return (0);
	cmd = (t_cmd*)gr;
	// TODO: perform redirection for compound cmd
	ft_dup_stdioe_copy(stdioe, 0);
	ft_dup_stdioe_set(cmd->stdioe, 1);
	sh_e_redirect(cmd->lst_redir);
	ret = cmd->exec(sh, cmd->core);
	ft_dup_stdioe_set(stdioe, 1);
	return (ret);
	/*
	if (cmd->type == SH_GR_SIMP_CMD)
	{
		ret = sh_e_simp_cmd(sh, cmd->core);
		ft_dup_stdioe_set(stdioe, 1);
		return (ret);
	}
	 */
}

int			sh_e_cmd_wait(t_sh *sh, void *gr, int op, int *state)
{
	t_cmd	*cmd;

	DF0;
	if (!gr || !sh)
		return (0); // TODO: check
	cmd = (t_cmd*)gr;
	return (cmd->wait(sh, cmd->core, op, state)); // TODO: store state in cmd->state
}

int			sh_e_cmd_kill(t_sh *sh, void *gr, int sig)
{
	t_cmd	*cmd;

	DF0;
	if (!gr)
		return (0); // TODO: check
	cmd = (t_cmd*)gr;
	return (cmd->kill(sh, cmd->core, sig)); // TODO: store state in cmd->state
}
