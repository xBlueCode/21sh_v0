#include "ftsh.h"

extern t_rl		g_rl;

t_dastr			*rl_autoc_match_bin(char *w)
{
	t_dastr		*res;
	t_dastr		*bin_names;
	int 		i;

	bin_names = sh_bin_names();
	res = ft_dastrnew_max(2);
	i = -1;
	while (++i < bin_names->len)
		if (!ft_strncmp(bin_names->a[i]->str, w, ft_strlen(w)))
			ft_dastrins_str(res, -1, bin_names->a[i]->str);
	return (res);
}

t_dastr			*rl_autoc_match_var(char *w)
{
	t_dastr	*res;
	t_trow	trow;
	t_table	*vars;
	int 	i;

	vars = sh_var();
	res = ft_dastrnew_max(2);
	i = -1;
	while (++i < vars->len)
	{
		trow = ft_tabget_i(vars, i);
		if (!ft_strncmp(trow.name, w, ft_strlenz(w)))
			ft_dastrins_str(res, -1, trow.name);
	}
	return (res);
}

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
