/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_g_cmd_core2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 21:40:58 by abbesbes          #+#    #+#             */
/*   Updated: 2019/10/20 21:40:59 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftsh.h"

static void	*g_cmd_core_exec[] = {
	&sh_e_simp_cmd,
	sh_e_com_cmd,
	sh_e_com_cmd,
	sh_e_com_cmd,
	NULL
};

static void	*g_cmd_core_wait[] = {
	&sh_e_simp_cmd_wait,
	sh_e_com_cmd_wait,
	sh_e_com_cmd_wait,
	sh_e_com_cmd_wait,
	NULL
};

static void	*g_cmd_core_kill[] = {
	&sh_e_simp_cmd_kill,
	sh_e_com_cmd_kill,
	sh_e_com_cmd_kill,
	sh_e_com_cmd_kill,
	NULL
};

static void	*g_cmd_core_free[] = {
	&sh_g_simp_cmd_free,
	sh_g_com_cmd_free,
	sh_g_com_cmd_free,
	sh_g_com_cmd_free,
	NULL
};

t_exec	*sh_g_cmd_core_get_exec(int grt)
{
	int type;

	if ((type = sh_g_cmd_core_type(grt)) < 0)
		return (NULL);
	return (g_cmd_core_exec[type]);
}

t_wait	*sh_g_cmd_core_get_wait(int grt)
{
	int type;

	if ((type = sh_g_cmd_core_type(grt)) < 0)
		return (NULL);
	return (g_cmd_core_wait[type]);
}

t_kill	*sh_g_cmd_core_get_kill(int grt)
{
	int type;

	if ((type = sh_g_cmd_core_type(grt)) < 0)
		return (NULL);
	return (g_cmd_core_kill[type]);
}

t_free	sh_g_cmd_core_get_free(int grt)
{
	int type;

	if ((type = sh_g_cmd_core_type(grt)) < 0)
		return (NULL);
	return (g_cmd_core_free[type]);
}
