/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_scope_scan_h.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 19:31:45 by abbesbes          #+#    #+#             */
/*   Updated: 2019/10/07 19:31:47 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// Created by xbluecode on 21.05.19.
//

#include "ft_rl.h"
#include "libft.h"

extern t_rl	g_rl;

int 		rl_scope_scan_hd(char *line, ssize_t *pos)
{
	ssize_t	i;
	int 	start;
	char 	*hddelim;

	i = *pos;
	start = (ft_dstrget_ch(g_rl.scope, -1) != RL_SCP_HD);
	if (start)
	{
		if (ft_strncmp(line + i, "<<", 2))
			return (0);
		else if ((i += 2))
		{
			while (ft_isalnum(line[i]))
				i++;
			hddelim = ft_strndup(line + *pos + 2, i - *pos - 2);
			ft_dastrins_str(g_rl.hd, -1, hddelim);
			ft_memdel((void**)&hddelim);
			ft_dstrins_ch(g_rl.scope, -1, RL_SCP_HD);
			*pos = i - 1;
			return (1);
		}
	}
	else if (!*pos)
	{
		if (!ft_strncmp(line, ft_dastrget_i(g_rl.hd, -1)->str, ft_strlenz(line) - 1))
		{
			ft_dastrdel_n(g_rl.hd, -1, 1);
			ft_dstrdel_n(g_rl.scope, -1, 1);
		}
		*pos = ft_strlenz(line);
		return (1);
	}
	else if (!ft_strncmp(line + i, "<<", 2) && (i += 2))
	{
		while (ft_isalnum(line[i]))
			i++;
		hddelim = ft_strndup(line + *pos + 2, i - *pos - 2);
		ft_dastrins_str(g_rl.hd, -1, hddelim);
		ft_memdel((void**)&hddelim);
		ft_dstrins_ch(g_rl.scope, -1, RL_SCP_HD);
		*pos = i - 1;
		return (1);
	}
	return (0);
}
