#include "ftsh.h"
#include <sys/wait.h>
//#include <sys/types.h>

int 		sh_e_simp_cmd(t_sh *sh, void *gr)
{
	t_simp_cmd	*simp_cmd;
	char 		**argv;
	int 	ret;
	pid_t		pid;
	int 		wstat;

	DF0
	if ((ret = 0) || !sh || !gr)
		return (0);
	simp_cmd = (t_simp_cmd*)gr;
	sh_xp_start(sh, simp_cmd->lst_words);
	if (!(argv = sh_e_get_argv(sh, simp_cmd->lst_words)))
		return (-1);
	ft_printf("--------> forking ...\n");
	//sh_e_redirect(simp_cmd->lst_redir);
	if ((pid = fork()) < 0)
		return (ft_printf("fork error\n"));
	else if (!pid)
	{
		sh_e_redirect(simp_cmd->lst_redir);
		execve(argv[0], argv, NULL);
		exit(1);
	}
	ft_printf("waiting ....\n");
	wait(&wstat);
	return (WEXITSTATUS(wstat));
}
