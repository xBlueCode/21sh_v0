#include "ftsh.h"

int 	sh_e_run_exec(t_sh *sh, t_simp_cmd *simp_cmd)
{
	pid_t	pid;
	int 	wstat;

	//ft_printf("run exec");
	//DF0
	if (BIT_IS(sh->mode, SH_MODE_SCMD))
		pipe(sh->sub_pipe);
	if ((pid = fork()) < 0)
		return (ft_printf("fork error\n"));
	else if (!pid)
	{
		if (BIT_IS(sh->mode, SH_MODE_SCMD))
			ft_dup2(sh->sub_pipe[1], STDOUT_FILENO, 1);
		sh_e_redirect(simp_cmd->lst_redir);
		if (!ft_strcmp(simp_cmd->argv[0], "env"))
		{
			exit(sh_e_run_env(sh, simp_cmd));
		}
		else
			execve(simp_cmd->argv[0], simp_cmd->argv, simp_cmd->envp);
		exit(1);
	}
	wait(&wstat);
	if (BIT_IS(sh->mode, SH_MODE_SCMD) && !close(sh->sub_pipe[1]))
		ft_read_fd_in(sh->sub_pipe[0], sh->sub_out);
	sh->exit = WEXITSTATUS(wstat);
	return (WEXITSTATUS(wstat));
}

int 	sh_e_run_built(t_sh *sh, t_simp_cmd *simp_cmd) // TODO: redirect cmd-sub
{
	int 		ret;
	t_sh_blt	bi;

	if (!(bi = sh_e_get_blt(simp_cmd->argv[0])))
		return (-1);
	if (BIT_IS(sh->mode, SH_MODE_SCMD))
		pipe(sh->sub_pipe);
	if (BIT_IS(sh->mode, SH_MODE_SCMD))
	{
		//ft_dup2(sh->sub_pipe[0], STDOUT_FILENO, 1);
		ft_dup2(sh->sub_pipe[1], STDOUT_FILENO, 1);
	}
	sh_e_redirect(simp_cmd->lst_redir);
	ret = bi(sh, simp_cmd->argv, simp_cmd->envp);
	if (BIT_IS(sh->mode, SH_MODE_SCMD))// && !close(sh->sub_pipe[1]))
		ft_read_fd_in(sh->sub_pipe[0], sh->sub_out);
	return (ret);
}

int 	sh_e_run_env(t_sh *sh, t_simp_cmd *simp_cmd)
{

	int i, ret;

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
