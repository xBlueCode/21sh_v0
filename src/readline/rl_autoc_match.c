/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_autoc_match.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 11:31:53 by abbesbes          #+#    #+#             */
/*   Updated: 2019/04/10 13:48:25 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftsh.h"

extern t_rl		g_rl;

t_dastr			*rl_autoc_match_bin(char *w)
{
}

t_dastr			*rl_autoc_match_var(char *w)
{
}

t_dastr			*rl_autoc_match_glob(char *w)
{
	t_dastr	*res;
	t_dstr	*base;

	res = ft_dastrnew_max(1);
	if (*w == '/' && w++)
		base = ft_strnew("");
	else
		base = "."; // get working dir
	rl_glob_match_indir(base, NULL, w, res);
}

int				rl_glob_match_indir(char *base, char *spath, char *pat,
		t_dastr *res)
{
	t_lsit	*conds;
	t_list	*cond;
	char	*slash;

	conds = sh_glob_scandir(base, spath);
	cond = conds;
	slash = ft_strchr(pat, '/');
	while (cond)
	{
		if (!slash && sh_glob_match(cond->content, pat))
			ft_dastrins_str(res, ft_strjoin(spath, cond->content), -1);
		else if (sh_glob_match(cond->content,
					ft_strndup(pat, slash - pat)))
			rl_glob_match_indir(base,
					ft_strjoin(spath, cond->content), slash + 1);
		cond = cond->next;
	}

	// match to next slash or \0
	// add to res
	// if exist next slash
	// rl_glob_match_indir with each res[i]
}
