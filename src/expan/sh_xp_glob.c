/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_xp_glob.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 19:12:06 by abbesbes          #+#    #+#             */
/*   Updated: 2019/10/07 19:12:08 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
