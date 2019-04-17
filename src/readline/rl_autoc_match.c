#include "ftsh.h"

extern t_rl		g_rl;

/*
t_dastr			*rl_autoc_match_bin(char *w)
{
}

t_dastr			*rl_autoc_match_var(char *w)
{
}
*/

t_dastr			*rl_autoc_match_glob(char *w)
{
	t_dastr	*res;
	t_dastr *res_single;
	char	*base;

	//ft_printf("match_glob\n");
	// if wildcard exist, then match pattern
	// else, search linear
	if (!w)
		return (NULL);
	res = ft_dastrnew_max(2);
	if (*w == '/' && w++)
		base = ft_strdup("");
	else
		base = ft_strdup("."); // get working dir
	if (ft_strchr(w, '[') || ft_strchr(w, '*') || ft_strchr(w, '?'))
	{
		rl_glob_indir(base, "", w, res);
		res_single = ft_dastrnew_max(2);
		res_single->a[0] = ft_dstrjoin_all(res->a, " ");
		ft_dastrfree(&res);
		res = res_single;
	}
	else
		rl_glob_indir_lin(base, "", w, res);
	return (res);
}
