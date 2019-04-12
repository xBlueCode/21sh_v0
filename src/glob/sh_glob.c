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
//	ft_printf("--> scandir: path <%s>\n", path->str);
	if (!(dirp = opendir(path->str)))
		return (NULL);
	while ((dent = readdir(dirp)))
		ft_lstadd(&conds, ft_lstnew(dent->d_name, ft_strlenz(dent->d_name) + 1));
//	ft_printf("+++> scanned: %s\n", conds->content);
	return (conds);
}


int				rl_glob_indir_lin(char *base, char *spath, char *pat,
									 t_dastr *res)
{
	t_list	*conds;
	t_list	*cond;
	char	*slash;

	//ft_printf("--> indir_lin: %s, %s, %s\n", base, spath, pat);
	if ((slash = ft_strchr_inv(pat, '/')))
		conds = sh_glob_scandir(base, ft_strndup(pat, slash++ - pat));
	else
		conds = sh_glob_scandir(base, spath);
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
			ft_dastrins_str(res, -1, ft_strconnect(3, spath,
												   *spath ? "/" : "", cond->content));
		else if (slash && !ft_strncmp(cond->content, slash, ft_strlenz(slash)))
			ft_dastrins_str(res, -1, ft_strconnect(3, spath,
												   *spath ? "/" : "", cond->content));
		cond = cond->next;
	}
	return (0);
}

int				rl_glob_indir(char *base, char *spath, char *pat,
								 t_dastr *res)
{
	t_list	*conds;
	t_list	*cond;
	char	*slash;

	//ft_printf("--> indir: %s, %s, %s\n", base, spath, pat);
	conds = sh_glob_scandir(base, spath);
	cond = conds;
	slash = ft_strchr(pat, '/');
	while (cond)
	{
		if ((*(char*)cond->content == '.' && *pat != '.') ||
			(!ft_strcmp(cond->content, "..") && ft_strncmp(pat, "..", 2)))
		{
			cond = cond->next;
			continue ;
		}
		else if (!slash && sh_glob_match(cond->content, pat))
			ft_dastrins_str(res, -1, ft_strconnect(3, spath,
												   *spath ? "/" : "", cond->content));
		else if (slash && sh_glob_match(cond->content,
										ft_strndup(pat, slash - pat)))
			rl_glob_indir(base,
						  ft_strconnect(3, spath, *spath ? "/" : "", cond->content),
						  slash + 1, res);
		cond = cond->next;
	}
	return (0);
}