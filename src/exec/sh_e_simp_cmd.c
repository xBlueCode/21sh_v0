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
	ft_printf(C_GRN"Assignments:\n");
	ft_dastrprint_all(simp_cmd->lst_assign, "\n");
	ft_printf("\n"T_END);
	if (!(argv = sh_e_get_argv(sh, simp_cmd->lst_words))) // assign to current env
	{
		sh_var_assign(sh->var, simp_cmd->lst_assign);
		return (0);
	}
	envp = sh_e_get_envp(sh, simp_cmd->lst_assign);
	ft_printf(T_END"--------> forking ...\n");
	//sh_e_redirect(simp_cmd->lst_redir);
	if ((pid = fork()) < 0)
		return (ft_printf("fork error\n"));
	else if (!pid)
	{
		sh_e_redirect(simp_cmd->lst_redir);
		execve(argv[0], argv, envp);
		exit(1);
	}
	ft_printf("waiting ....\n");
	wait(&wstat);
	return (WEXITSTATUS(wstat));
}
