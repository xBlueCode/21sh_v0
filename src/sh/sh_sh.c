#include "ftsh.h"
#include <signal.h>

extern t_sh		*g_sh;

t_sh 			*sh_sh(void)
{
	return (g_sh);
}

int 			sh_sh_init(t_sh **sh, char **envp, int mode) // init mode (subsh ...)
{
	if (!sh)
		return (KO);
	DF0
	*sh = ft_memalloc(sizeof(t_sh));
	(*sh)->jc = NULL;
	(*sh)->pgid = -1;
//	(*sh)->tmodes = NULL;
	(*sh)->term_std = STDIN_FILENO;
	(*sh)->inter = isatty((*sh)->term_std);
	sh_var_start(&(*sh)->var, envp);
	//(*sh)->stdi = dup(STDIN_FILENO);
	//(*sh)->stdo = dup(STDOUT_FILENO);
	sh_bin_init(&(*sh)->bin_ht, &(*sh)->bin_nl);
	sh_bin_update((*sh)->bin_ht, (*sh)->bin_nl, sh_var_getval((*sh)->var, "PATH"));
	if (!mode && (*sh)->inter)
	{
		while (tcgetpgrp ((*sh)->term_std) != ((*sh)->pgid = getpgrp ()))
			kill (- (*sh)->pgid, SIGTTIN);
		//signal (SIGINT, SIG_IGN);
		//signal (SIGQUIT, SIG_IGN);
		//signal (SIGTSTP, SIG_IGN);
		//signal (SIGTTIN, SIG_IGN);
		//signal (SIGTTOU, SIG_IGN);
		//signal (SIGCHLD, SIG_IGN);
		(*sh)->pgid = getpid();
		if (setpgid((*sh)->pgid, (*sh)->pgid) < 0)
		{
			ft_printf("Couldn't put the shell in its own process group !\n");
			exit(1);
		}
		tcsetpgrp((*sh)->term_std, (*sh)->pgid);
		//tcgetattr((*sh)->term_std, &(*sh)->tmodes);
		sh_termconfig_init(&(*sh)->term);
		(*sh)->jc = sh_jc_new();
		ft_printf(C_GRN"Interactive Term initialized ^ ^\n"T_END);
	}
	return (OK);
}
