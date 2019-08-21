#include "ftsh.h"
#include <signal.h>

//t_sh			*g_sh;

/*
t_sh 			*sh_sh(void)
{
	return (g_sh);
}
*/

int 			sh_sh_init(t_sh **sh) // init mode (subsh ...)
{
	if (!sh)
		return (KO);
	DF0
	*sh = ft_memalloc(sizeof(t_sh));
	(*sh)->jc = NULL;
	(*sh)->pgid = -1;
//	(*sh)->tmodes = NULL;
	(*sh)->term = STDIN_FILENO;
	(*sh)->inter = isatty((*sh)->term);
//	(*sh)->stdi = dup(STDIN_FILENO);
//	(*sh)->stdo = dup(STDOUT_FILENO);

	if ((*sh)->inter)
	{
		while (tcgetpgrp ((*sh)->term) != ((*sh)->pgid = getpgrp ()))
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
		tcsetpgrp((*sh)->term, (*sh)->pgid);
		tcgetattr((*sh)->term, &(*sh)->tmodes);
		(*sh)->jc = sh_jc_new();
		ft_printf(C_GRN"Interactive Term initialized ^ ^\n"T_END);
	}
	return (OK);
}
