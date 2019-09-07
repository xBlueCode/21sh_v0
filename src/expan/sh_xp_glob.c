#include "ftsh.h"

t_dastr			*sh_xp_scandir(char *w)
{
	t_dastr	*res;
	char	base[1024];

	if (!w)
		return (NULL);
	if (*w == '/' && w++)
		base[0] = '\0';
	else if (getcwd(base, 1024))
		return (NULL);
	res = ft_dastrnew_max(2);
	if (ft_strchr(w, '[') || ft_strchr(w, '*') || ft_strchr(w, '?'))
		rl_glob_indir(base, "", w, res);
	else
		ft_dastrfree(&res);
	return (res);
}

//int		sh_xp_glob(t_sh *sh, t_dastr *words)
//{
//	int			i;
//	t_dastr		*res;
/*
	if (!sh || !words)
		return (0);
	i = -1;
	while (++i < words->len)
	{
		res = ft_dastrnew_max(2);
		rl_glob_indir()
	}
 */
//	return (0);
//}
