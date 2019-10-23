/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_g_cmd_core.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 19:13:13 by abbesbes          #+#    #+#             */
/*   Updated: 2019/10/07 19:13:16 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftsh.h"

extern int	g_g_putlev;

static int	g_cmd_core_types[] = {
	SH_GR_SIMP_CMD,
	SH_GR_SUBSH,
	SH_GR_CB_GROUP,
	SH_GR_DO_GROUP,
	SH_GR_FOR_CLAUSE,
	SH_GR_WHILE_CLAUSE,
	SH_GR_UNTIL_CLAUSE,
	SH_GR_FUNC_DEF,
	-1
};

static void	*g_cmd_core_new[] = {
	&sh_g_simp_cmd_new,
	NULL
};

static void	*g_cmd_core[] = {
	&sh_g_simp_cmd,
	&sh_g_group,
	&sh_g_group,
	&sh_g_group,
	&sh_g_for,
	&sh_g_loop,
	&sh_g_loop,
	NULL
};

static void	*g_cmd_core_put[] = {
	&sh_g_simp_cmd_put,
	sh_g_com_cmd_put,
	sh_g_com_cmd_put,
	sh_g_com_cmd_put,
	sh_g_for_put,
	sh_g_loop_put,
	sh_g_loop_put,
	NULL
};

int		sh_g_cmd_core_type(int gr_enum)
{
	int i;

	i = -1;
	while (g_cmd_core_types[++i] > -1)
		if (g_cmd_core_types[i] == gr_enum)
			return (i);
	return (-1);
}

void	*sh_g_cmd_core_new(int t)
{
	int type;

	if ((type = sh_g_cmd_core_type(t)) < 0)
		return (NULL);
	return (g_cmd_core_new[type]);
}

void	*sh_g_cmd_core(int t)
{
	int type;

	if ((type = sh_g_cmd_core_type(t)) < 0)
		return (NULL);
	return (g_cmd_core[type]);
}

void	*sh_g_cmd_core_put(int t)
{
	int type;

	if ((type = sh_g_cmd_core_type(t)) < 0)
		return (NULL);
	return (g_cmd_core_put[type]);
}
