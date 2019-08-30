#include "ftsh.h"
#include <sys/wait.h>
//#include <sys/types.h>

int 		sh_e_simp_cmd(t_sh *sh, void *gr)
{
	t_simp_cmd	*simp_cmd;
	char 		**argv;
	char 		**envp;
	int 		ret;
	pid_t		pid;
	int 		wstat;

	DF0
	if ((ret = 0) || !sh || !gr)
		return (0);
	simp_cmd = (t_simp_cmd*)gr;
	sh_xp_word(sh, simp_cmd->lst_words);
	sh_xp_assign(sh, simp_cmd->lst_assign);
	//ft_printf(C_GRN"Assignments:\n");
	//ft_dastrprint_all(simp_cmd->lst_assign, "\n");
	//ft_printf("\n"T_END);
	if (!(argv = sh_e_get_argv(sh, simp_cmd->lst_words))) // assign to current env
	{
		sh_var_assign(sh->var, simp_cmd->lst_assign);
		return (0);
	}
	envp = sh_e_get_envp(sh, simp_cmd->lst_assign);
	if (BIT_MIS(sh->mode, SH_MODE_M, SH_MODE_SCMD))
		pipe(sh->sub_pipe);
	if ((pid = fork()) < 0)
		return (ft_printf("fork error\n"));
	else if (!pid)
	{
		if (BIT_MIS(sh->mode, SH_MODE_M, SH_MODE_SCMD))
			ft_dup2(sh->sub_pipe[1], STDOUT_FILENO, 1);
		sh_e_redirect(simp_cmd->lst_redir);
		execve(argv[0], argv, envp);
		exit(1);
	}
	wait(&wstat);
	if (BIT_MIS(sh->mode, SH_MODE_M, SH_MODE_SCMD) && !close(sh->sub_pipe[1]))
		ft_read_fd_in(sh->sub_pipe[0], sh->sub_out);
	return (WEXITSTATUS(wstat));
}
