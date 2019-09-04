#include "ftsh.h"

int 	sh_e_run_exec(t_sh *sh, t_simp_cmd *simp_cmd)
{
	pid_t	pid;
	int 	wstat;

	if (BIT_MIS(sh->mode, SH_MODE_M, SH_MODE_SCMD))
		pipe(sh->sub_pipe);
	if ((pid = fork()) < 0)
		return (ft_printf("fork error\n"));
	else if (!pid)
	{
		if (BIT_MIS(sh->mode, SH_MODE_M, SH_MODE_SCMD))
			ft_dup2(sh->sub_pipe[1], STDOUT_FILENO, 1);
		sh_e_redirect(simp_cmd->lst_redir);
		execve(simp_cmd->argv[0], simp_cmd->argv, simp_cmd->envp);
		exit(1);
	}
	wait(&wstat);
	if (BIT_MIS(sh->mode, SH_MODE_M, SH_MODE_SCMD) && !close(sh->sub_pipe[1]))
		ft_read_fd_in(sh->sub_pipe[0], sh->sub_out);
	sh->exit = WEXITSTATUS(wstat);
	return (WEXITSTATUS(wstat));
}

int 	sh_e_run_built(t_sh *sh, t_simp_cmd *simp_cmd)
{
	int 		ret;
	t_sh_blt	bi;

	if (!(bi = sh_e_get_blt(simp_cmd->argv[0])))
		return (-1);
	if (BIT_MIS(sh->mode, SH_MODE_M, SH_MODE_SCMD))
		pipe(sh->sub_pipe);
	if (BIT_MIS(sh->mode, SH_MODE_M, SH_MODE_SCMD))
		ft_dup2(sh->sub_pipe[1], STDOUT_FILENO, 1);
	sh_e_redirect(simp_cmd->lst_redir);
	ret = bi(sh, simp_cmd->argv, simp_cmd->envp);
	if (BIT_MIS(sh->mode, SH_MODE_M, SH_MODE_SCMD) && !close(sh->sub_pipe[1]))
		ft_read_fd_in(sh->sub_pipe[0], sh->sub_out);
	return (ret);
}

int 	sh_e_run_env(t_sh *sh, t_simp_cmd *simp_cmd)
{

}
