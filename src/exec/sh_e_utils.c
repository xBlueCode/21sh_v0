#include "ftsh.h"

char 		*sh_e_get_binpath(t_sh *sh, char *bin_name)
{
	char 	*binpath;

	DF0
	(void)sh;
	if (!bin_name)
		return (NULL);
	binpath = sh_bin_getpath(sh->bin_ht, bin_name);
	ft_printf(C_RED"bin: %s\t\tbinpath: %s\n"T_END, bin_name, binpath);
	return (binpath); // TODO: to be improved
}

char		**sh_e_get_argv(t_sh *sh, t_dastr *words)
{
	char	**argv;
	char 	*bin;
	int 	i;

	DF0
	if (!words || !words->a)
		return (NULL);
	if (!(bin = sh_e_get_binpath(sh, words->a[0]->str)))
		return (NULL);
	argv = (char**)ft_memalloc((words->len + 1) * sizeof(char*));
	argv[words->len] = NULL;
	argv[0] = bin;
	i = 0;
	while (++i < words->len)
	{
		argv[i] = words->a[i]->str;
	}
	return (argv);
}
