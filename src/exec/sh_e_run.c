/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_e_run.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 21:42:16 by abbesbes          #+#    #+#             */
/*   Updated: 2019/10/08 21:42:19 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftsh.h"
#include <fcntl.h>
#include <signal.h>

static int	sh_e_run_process_reset(t_sh *sh)
{
	pid_t	pid;

	if (!sh->inter)
		return (KO);
	pid = getpid();
	if (sh->jc->cjob->pgid == 0)
		sh->jc->cjob->pgid = pid;
//	setpgid(pid, sh->jc->cjob->pgid);
	if (!sh->jc->cjob->bg)
		tcsetpgrp(sh->term_std, sh->jc->cjob->pgid);
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
	signal(SIGTSTP, SIG_DFL);
	signal(SIGTTIN, SIG_DFL);
	signal(SIGTTOU, SIG_DFL);
	signal(SIGCHLD, SIG_DFL);
	return (OK);
}

static void	sh_e_run_exec_redir_scmd(t_sh *sh)
{
	if (BIT_IS(sh->mode, SH_MODE_SCMD))
	{
		ft_dup2(sh->sub_pipe[1], STDOUT_FILENO, 1);
		fcntl(sh->sub_pipe[1], F_SETFL, O_NONBLOCK);
	}
	else
	{
		sh_e_run_process_reset(sh);
		sh_termconfig_reset(&sh->term);
	}
}

int			sh_e_run_exec(t_sh *sh, t_simp_cmd *simp_cmd)
{
	pid_t	pid;

	if (BIT_IS(sh->mode, SH_MODE_SCMD))
		pipe(sh->sub_pipe);
	if ((pid = fork()) < 0)
		return (ft_printf("fork error\n"));
	else if (!pid)
	{
		sh_e_run_exec_redir_scmd(sh);
		sh_e_redirect(simp_cmd->lst_redir);
		if (!ft_strcmp(simp_cmd->argv[0], "env"))
			exit(sh_e_run_env(sh, simp_cmd));
		else
			execve(simp_cmd->argv[0], simp_cmd->argv, simp_cmd->envp);
		exit(1);
	}
	if (BIT_IS(sh->mode, SH_MODE_SCMD) && !close(sh->sub_pipe[1]))
		ft_read_fd_in(sh->sub_pipe[0], sh->sub_out);
	//sleep(2);
	simp_cmd->pid = pid;
	if (sh->inter)
	{
		if (sh->jc->cjob->pgid == 0)
			sh->jc->cjob->pgid = pid;
//		setpgid(pid, sh->jc->cjob->pgid);
	}
	sh_jc_add_proc(sh->jc, pid);
	return (0);
}

int			sh_e_run_built(t_sh *sh, t_simp_cmd *simp_cmd)
{
	int			ret;
	t_sh_blt	bi;

	DF0;
	if (!(bi = sh_e_get_blt(simp_cmd->argv[0])))
		return (-1);
	if (BIT_IS(sh->mode, SH_MODE_SCMD))
	{
		pipe(sh->sub_pipe);
	}
	if (BIT_IS(sh->mode, SH_MODE_SCMD))
	{
		ft_dup2(sh->sub_pipe[1], STDOUT_FILENO, 1);
	}
	sh_e_redirect(simp_cmd->lst_redir);
	ret = bi(sh, simp_cmd->argv, simp_cmd->envp);
	if (BIT_IS(sh->mode, SH_MODE_SCMD))
		ft_read_fd_in(sh->sub_pipe[0], sh->sub_out);
	simp_cmd->state = ret;
	return (ret);
}

int			sh_e_run_env(t_sh *sh, t_simp_cmd *simp_cmd)
{
	int		i;
	int		ret;

	DF0;
	i = 1;
	if (!simp_cmd->argv[i])
		return (sh_blt_printenv(sh, simp_cmd->argv + i, simp_cmd->envp));
	if (sh_e_check_built(simp_cmd->argv[i]) != -1)
		return (sh_e_run_built(sh, simp_cmd));
	if ((ret = sh_e_check_exec(simp_cmd->argv[0])) == OK)
	{
		execve(simp_cmd->argv[i], simp_cmd->argv + i, simp_cmd->envp);
		exit(1);
	}
	FT_INST_RET(ret,
		ft_dprintf(2, "ftsh: env: %s not found !\n", simp_cmd->argv[i]));
}
