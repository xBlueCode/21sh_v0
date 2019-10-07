/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_bin_manip.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 19:07:00 by abbesbes          #+#    #+#             */
/*   Updated: 2019/10/07 19:07:03 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftsh.h"

int		sh_bin_update(t_hset *htbin, t_dastr *bin_names, char *paths)
{
	char	**path_arr;
	t_dastr	*bins;
	int		i;
	int		j;

	if (!htbin || !paths || !(path_arr = ft_strsplit(paths, ':')))
		return (KO);
	i = -1;
	while (path_arr[++i])
	{
		if (!(bins = ft_dirent_lookup_abs(path_arr[i], sh_bin_filter)))
			continue;
		j = -1;
		while (++j < bins->len)
			sh_bin_add_abs(htbin, bin_names, ft_dastrget_i(bins, j)->str);
		ft_dastrfree(&bins);
	}
	ft_arr_free((void***)&path_arr, ft_arr_len((void**)path_arr));
	return (OK);
}

int		sh_bin_add_abs(t_hset *htbin, t_dastr *bin_names, char *bin_path)
{
	t_htabent	htent;
	char		*bin_name;

	if (!htbin || !bin_path)
		return (KO);
	if ((bin_name = ft_strchr_inv(bin_path, '/')))
		bin_name++;
	else
		bin_name = bin_path;
	htent = (t_htabent){
		.key = bin_name, .ksize = ft_strlen(bin_name) + 1,
		.val = bin_path, .vsize = ft_strlen(bin_path) + 1};
	if (!ft_dastrins_str(bin_names, -1, bin_name))
		return (ft_htab_put(htbin, &htent));
	return (KO);
}

char	*sh_bin_getpath(t_hset *htbin, char *bin)
{
	char	*path;

	DF0;
	//ft_dprintf(2, "%s %s\n", !htbin? "N":"NN", bin);
	if (!htbin || !bin)
		return (NULL);
	//ft_dprintf(2, "bin: %s\n", bin);
	if (!(path = (char*)ft_htab_getval(htbin, bin, ft_strlenz(bin) + 1)))
		return (NULL);
	//ft_dprintf(2, "path: %s\n", path);
	return (ft_strdup(path)); // check the possibility of skipping strdup
}
