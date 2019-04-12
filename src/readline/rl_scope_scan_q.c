/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_scope_scan_q.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 16:37:10 by abbesbes          #+#    #+#             */
/*   Updated: 2019/03/19 17:19:25 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftsh.h"

extern t_rl g_rl;

int			rl_scope_scan_sq(char *line, ssize_t *pos)
{
	ssize_t		i;
	int			start;

	i = *pos;
	start = (ft_dstrget_ch(g_rl.scope, -1) != RL_SCP_SQ);
	if (start && line[i] != '\'')
		return (0);
	if (start && ++i)
		ft_dstrins_ch(g_rl.scope, -1, RL_SCP_SQ);
	while (line[i] && line[i] != '\'')
		i++;
	if (line[i] && ++i)
		ft_dstrdel_n(g_rl.scope, -1, 1);
	*pos = i;
	return (1);
}

int			rl_scope_scan_dq(char *line, ssize_t *pos)
{
	ssize_t		i;
	int			start;

	i = *pos;
	//ft_printf("\ndq %d-> %s\n", (int)i, line + *pos);
	start = (ft_dstrget_ch(g_rl.scope, -1) != RL_SCP_DQ);
	if (start && line[i] != '"')
		return (0);
	if (start && ++i)
		ft_dstrins_ch(g_rl.scope, -1, RL_SCP_DQ);
	while (line[i] && line[i] != '"')
	{
		if (rl_scope_scan_escape(line, &i)
			|| rl_scope_scan_join(line, &i)
			|| rl_scope_scan_bq(line, &i)
			|| rl_scope_scan_param(line, &i)
			|| rl_scope_scan_smath(line, &i)
			|| rl_scope_scan_scmd(line, &i))
			continue;
		i++;
	}
	if (line[i] && ++i)
		ft_dstrdel_n(g_rl.scope, -1, 1);
	*pos = i;
	return (1);
}

int			rl_scope_scan_bq(char *line, ssize_t *pos)
{
	ssize_t		i;
	int			start;

	i = *pos;
	start = (ft_dstrget_ch(g_rl.scope, -1) != RL_SCP_BQ);
	if (start && line[i] != '`')
		return (0);
	if (start && ++i)
		ft_dstrins_ch(g_rl.scope, -1, RL_SCP_BQ);
	while (line[i] && line[i] != '`')
	{
		if (line[i] == '\\' && line[i + 1] == '`')
			i += 2;
		else if (!rl_scope_scan_join(line, &i))
			i++;
	}
	if (line[i] && ++i)
		ft_dstrdel_n(g_rl.scope, -1, 1);
	*pos = i;
	return (1);
}
