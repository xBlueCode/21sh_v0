#include "libft.h"
#include "sh_bin.h"

int 	sh_bin_update(t_hset *htbin, char *paths)
{
	char 	**path_arr;
	t_dastr	*bins;
	int 	i;
	int 	j;

	if (!htbin || !paths || !(path_arr = ft_strsplit(paths, ':')))
		return (KO);
	i = -1;
	while (path_arr[++i])
	{
		if (!(bins = ft_dirent_lookup_abs(path_arr[i], sh_bin_filter)))
			continue;
		j = -1;
		while (++j < bins->len)
			sh_bin_add_abs(htbin, ft_dastrget_i(bins, j)->str);
	}
	return (OK);
}

int		sh_bin_add_abs(t_hset *htbin, char *bin_path)
{
	t_htabent	htent;
	char 		*bin_name;

	if (!htbin || !bin_path)
		return (KO);
	if ((bin_name = ft_strchr_inv(bin_path, '/')))
		bin_name++;
	else
		bin_name = bin_path;
	htent = (t_htabent){
		.key = bin_name, .ksize = ft_strlen(bin_name) + 1,
		.val = bin_path, .vsize = ft_strlen(bin_path) + 1};
	ft_printf("Adding: ");
	ft_printf("<%s :: %s>\n", bin_name, bin_path);
	if (ft_dastrins_str(sh_bin_names(), -1, bin_name))
		return (ft_htab_put(htbin, &htent));
	return (KO);
}

char	*sh_bin_getpath(t_hset *htbin, char *bin)
{
	char 	*path;

	if (!htbin || !bin)
		return (NULL);
	if (!(path = (char*)ft_htab_getval(htbin, bin, ft_strlen(bin) + 1)))
		return (NULL);
	return (ft_strdup(path)); // check the possibility of skipping strdup
}
