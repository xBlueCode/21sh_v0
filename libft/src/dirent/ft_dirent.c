/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dirent.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 19:02:45 by abbesbes          #+#    #+#             */
/*   Updated: 2019/10/21 19:02:46 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dastr		*ft_dirent_lookup(char *base, t_dirent_filter filter)
{
	t_dastr			*names;
	DIR				*dirp;
	struct dirent	*dent;

	if (!base || !filter)
		return (NULL);
	if (!(dirp = opendir(base)))
		return (NULL);
	names = ft_dastrnew_max(2);
	while ((dent = readdir(dirp)))
		if (filter(dent))
			ft_dastrins_str(names, names->len, dent->d_name);
	return (names);
}

t_dastr		*ft_dirent_lookup_abs(char *base, t_dirent_filter filter)
{
	t_dastr			*names;
	DIR				*dirp;
	struct dirent	*dent;

	if (!base || !filter)
		return (NULL);
	if (!(dirp = opendir(base)))
		return (NULL);
	names = ft_dastrnew_max(2);
	while ((dent = readdir(dirp)))
	{
		if (filter(dent))
		{
			ft_dastrins_str(names, names->len, base);
			ft_dstrins_ch(ft_dastrget_last(names), -1, FT_DIRENT_FSEP);
			ft_dstrins_str(ft_dastrget_last(names), -1, dent->d_name);
		}
	}
	closedir(dirp);
	return (names);
}
