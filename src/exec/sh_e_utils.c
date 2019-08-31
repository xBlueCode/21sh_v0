#include "ftsh.h"

char 		*sh_e_get_binpath(t_sh *sh, char *bin_name)
{
	char 	*binpath;
	char 	*cwd;

	DF0
	(void)sh;
	if (!bin_name)
		return (NULL);
	if (!ft_strchr(bin_name, '/'))
		return (sh_bin_getpath(sh->bin_ht, bin_name));
	if (!(cwd = ft_getcwd()))
		return (NULL);
	binpath = ft_strconnect(3, cwd, "/", bin_name);
	return (binpath); // TODO: to be improved
}

char		**sh_e_get_argv(t_sh *sh, t_dastr *words)
{
	char	**argv;
	char 	*bin;
	int 	i;

	DF0
	if (!words || !words->len)
		return (NULL);
	argv = (char**)ft_memalloc((words->len + 1) * sizeof(char*));
	argv[words->len] = NULL;
	i = -1;
	if ((bin = sh_e_get_binpath(sh, words->a[0]->str)))
		argv[++i] = bin;
	while (++i < words->len)
		argv[i] = ft_strdup(words->a[i]->str);
	return (argv);
}

char		**sh_e_get_envp(t_sh *sh, t_dastr *assigns)
{
	t_table		*envt;
	char 		**envp;

	envt = ft_tabdup(sh->var);
	sh_var_assign(envt, assigns);
	envp = ft_tabto_arr(envt, &sh_var_tsel_glo, &sh_var_tbuild_env);
	return (envp);
}
