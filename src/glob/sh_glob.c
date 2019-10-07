/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_glob.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 19:12:46 by abbesbes          #+#    #+#             */
/*   Updated: 2019/10/07 19:12:47 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftsh.h"
#include <dirent.h>

t_list		*sh_glob_scandir(char *base, char *spath)
{
	t_dstr			*path;
	DIR				*dirp;
	struct dirent	*dent;
	t_list			*conds;

	conds = NULL;
	path = ft_dstrnew_max(200);
	ft_dstrins_str(path, 0, base);
	ft_dstrins_ch(path, -1, '/');
	ft_dstrins_str(path, -1, spath);
	if (!(dirp = opendir(path->str)))
		return (NULL);
	while ((dent = readdir(dirp)))
		ft_lstadd(&conds,
			ft_lstnew(dent->d_name, ft_strlenz(dent->d_name) + 1));
	ft_dstrfree(&path);
	closedir(dirp);
	return (conds);
}

int			rl_glob_indir_lin(char *base, char *spath, char *pat, t_dastr *res)
{
	t_list	*conds;
	t_list	*cond;
	char	*slash;
	char	*tmp;

	tmp = NULL;
	if ((slash = ft_strchr_inv(pat, '/')))
		conds = sh_glob_scandir(base, (tmp = ft_strndup(pat, slash++ - pat))); // TODO: clean after strdup
	else
		conds = sh_glob_scandir(base, spath);
	FT_MEMDEL(tmp);
	cond = conds;
	while (cond)
	{
		if ((*(char*)cond->content == '.' && *pat != '.') ||
			(!ft_strcmp(cond->content, "..") && ft_strncmp(pat, "..", 2)))
		{
			cond = cond->next;
			continue ;
		}
		else if (!slash && !ft_strncmp(cond->content, pat, ft_strlenz(pat)))
			ft_dastrins_str(res, -1, (tmp = ft_strconnect(3, spath,
					*spath ? "/" : "", cond->content)));
		else if (slash && !ft_strncmp(cond->content, slash, ft_strlenz(slash)))
			ft_dastrins_str(res, -1, (tmp = ft_strconnect(3, spath,
					*spath ? "/" : "", cond->content)));
		FT_MEMDEL(tmp);
		cond = cond->next;
	}
	ft_lst_free(&conds, &ft_memdel);
	return (0);
}

// TODO: check memory leaks + Refactoring to ft

int			rl_glob_indir(char *base, char *spath, char *pat, t_dastr *res)
{
	t_list	*conds;
	t_list	*cond;
	char	*slash;
	char	*tmp0;
	char	*tmp1;

	conds = sh_glob_scandir(base, spath);
	cond = conds;
	slash = ft_strchr(pat, '/');
	tmp0 = NULL;
	tmp1 = NULL;
	while (cond)
	{
		if ((*(char*)cond->content == '.' && *pat != '.') ||
			(!ft_strcmp(cond->content, "..") && ft_strncmp(pat, "..", 2)))
		{
			cond = cond->next;
			continue ;
		}
		else if (!slash && sh_glob_match(cond->content, pat))
			ft_dastrins_str(res, -1, (tmp0 = ft_strconnect(3, spath,
					*spath ? "/" : "", cond->content)));
		else if (slash && sh_glob_match(cond->content,
				(tmp1 = ft_strndup(pat, slash - pat))))
			rl_glob_indir(base, (tmp0 = ft_strconnect(3, spath,
					*spath ? "/" : "", cond->content)), slash + 1, res);
		FT_MEMDEL(tmp0);
		FT_MEMDEL(tmp1);
		cond = cond->next;
	}
	ft_lst_free(&conds, &ft_memdel);
	return (0);
}
