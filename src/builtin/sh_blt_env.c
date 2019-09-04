#include "ftsh.h"

int			sh_blt_setenv(t_sh *sh, char **argv, char **envp)
{
	int ac;
	int m;

	(void)envp;
	if (!sh || !argv)
		return (1);
	ac = ft_arr_len((void**)argv);
	if (ac != 3 && ac != 4)
		FT_INST_RET(1,
				ft_dprintf(2, "ftsh: setenv: Bad arguments number !\n"));
	if (!sh_tok_isname_till(argv[1], '\0'))
		FT_INST_RET(1,
				ft_dprintf(2, "ftsh: setenv: %s: Bad var name !\n", argv[1]));
	m = !argv[3] ? 0 : ft_atoi(argv[3]);
	ft_tabins(sh->var, ft_tabrow_set(-1, argv[1], argv[2], SH_VO_GLO), m);
	return (0);
}

int			sh_blt_unsetenv(t_sh *sh, char **argv, char **envp)
{
	int ac;
	int m;

	(void)envp;
	if (!sh || !argv)
		return (1);
	ac = ft_arr_len((void**)argv);
	if (ac < 2)
	FT_INST_RET(1,
				ft_dprintf(2, "ftsh: setenv: Bad arguments number !\n"));
	ac = 0;
	while (argv[++ac])
		ft_tabdel_n(sh->var, argv[ac]);
	return (0);
}

int			sh_blt_env(t_sh *sh, char **argv, char **envp)
{

}
