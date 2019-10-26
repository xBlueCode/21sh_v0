#include "ftsh.h"

int			sh_blt_exit(t_sh *sh, char **argv, char **envp)
{
	int	ac;

	(void)envp;
	ac = ft_arr_len((void**)argv);
	if (ac > 2)
		FT_INST_RET(1, ft_printf("ftsh: exit: Too many arguments !\n"));
	if (ac == 2 && !ft_isdigit(*argv[1]))
		FT_INST_RET(1, ft_printf("ftsh: exit: Numeric argument required !\n"));
	if (ac == 2)
	{
		sh->quit_st = ft_atoi(argv[1]);
		sh->quit = 2;
	}
	else
		sh->quit = 1;
	return (0);
}
