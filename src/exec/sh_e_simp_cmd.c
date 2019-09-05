#include "ftsh.h"
#include <sys/wait.h>
//#include <sys/types.h>

int 		sh_e_simp_cmd(t_sh *sh, void *gr)
{
	t_simp_cmd	*simp_cmd;
	//char 		**argv;
	//char 		**envp;
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
	if (!(simp_cmd->argv = sh_e_get_argv(sh, simp_cmd->lst_words))) // assign to current env
	{
		sh_var_assign(sh->var, simp_cmd->lst_assign);
		return (0);
	}
	simp_cmd->envp = sh_e_get_envp(sh, simp_cmd->lst_assign);
	//if (!ft_strcmp(simp_cmd->argv[0], "env"))
	//	return (sh_e_run_env(sh, simp_cmd));
	if (sh_e_check_built(simp_cmd->argv[0]) != -1)
		return (sh_e_run_built(sh, simp_cmd));
	if ((ret = sh_e_check_exec(simp_cmd->argv[0])) == OK)
		return (sh_e_run_exec(sh, simp_cmd));
	return (ret);
}
