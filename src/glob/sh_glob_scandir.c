/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_glob_scandir.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 11:14:01 by abbesbes          #+#    #+#             */
/*   Updated: 2019/04/10 12:49:45 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftsh.h"

t_list		*sh_glob_scandir(char *base, char *spath)
{
	t_dstr			*path;
	DIR				*dirp;
	struct dirent	*dent;
	t_list			*conds;

	conds = NULL;
	path = ft_dstrnew_max(PATH_MAX);
	ft_dstrins_str(path, 0, base);
	ft_dstrins_ch(path, -1, '/');
	ft_dstrins_str(path, -1, spath);
	if (!(dirp = opendir(path->str)))
		return (NULL);
	while ((dent = readir(dirp)))
		ft_lstadd(&conds, ft_lstnew(dent->d_name, ft_strlenz(dent->d_name)));
	return (conds);
}
