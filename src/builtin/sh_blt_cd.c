#include "ftsh.h"
#include <sys/stat.h>

int 	sh_blt_cd(char *bname, char **argv, char **envp)
{
	int		ac;
	char	*dir;

	if (!bname || !argv)
		return (1);
	if ((ac = ft_arr_len((void**)argv)) > 2)
		FT_STDE_RET(-1, "ftsh: cd: Too many arguments !");
	if (ac == 1)
	{
		if (!(dir = sh_env_getval("HOME")))
			FT_STDE_RET(1, "ftsh: cd: HOME not set !");
		// change dir
		return (0);
	}
	else if (ac == 2)
	{
		if (!ft_strcmp(argv[1], "-"))
		{
			if (!(dir = sh_env_getval("OLDPWD")))
				FT_STDE_RET(1, "ftsh: cd: OLDPWD not set !");
			ft_putendl(dir);
			// change dir
			return (0);
		}
		else if (ft_stat_is(argv[1], S_IFDIR) != OK)
		{
			ft_dprintf(2, C_RED"ftsh: cd: %s: not a directory !\n"T_END);
			return (1);
		}
		// change dir
		return (0);
	}
}
