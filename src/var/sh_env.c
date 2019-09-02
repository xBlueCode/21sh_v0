#include "ftsh.h"

char 	*sh_env_getval(char **envp, char *name)
{
	int		i;
	int		eqi;

	if (!envp || !name)
		return (NULL);
	i = -1;
	while (envp[++i])
	{
		if ((eqi = ft_strichr(envp[i], '=')) < 0)
			eqi = ft_strlen(envp[i]);
		if (ft_strncmp(envp[i], name, eqi))
			continue;
		if (envp[i][eqi] == '=')
			return (envp[i] + eqi + 1);
		else
			return (envp[i] + eqi);
	}
	return (NULL);
}
