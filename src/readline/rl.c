/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 19:29:52 by abbesbes          #+#    #+#             */
/*   Updated: 2019/10/07 19:29:54 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftsh.h"

t_rl		g_rl;

void		rl_init(void)
{
	rl_free();
	g_rl.txt = ft_dastrnew_max(2);
	g_rl.reg = ft_dastrnew_max(2);
	g_rl.regi = -1;
	g_rl.cl = -1;
	g_rl.scope = ft_dstrnew_max(RL_SCP_SIZE);
	ft_dstrins_ch(g_rl.scope, 0, RL_SCP_START);
	g_rl.hd = ft_dastrnew_max(2);
	rl_update_win();
}

void		rl_free(void)
{
	ft_dastrfree(&g_rl.txt);
	ft_dastrfree(&g_rl.reg);
	ft_dstrfree(&g_rl.scope);
	ft_dastrfree(&g_rl.hd);
}

void		rl_update(t_dastr *txt)
{
	if (!txt)
		return ;
	g_rl.txt = txt;
	g_rl.cl = -1;
	g_rl.cc = 0;
	ft_dstrdel_n(g_rl.scope, 0, g_rl.scope->max);
	ft_dstrins_ch(g_rl.scope, 0, RL_SCP_START);
}

void		rl_sigint(void)
{
	rl_free();
	rl_init();
	g_rl.mode = RL_MODE_INS;
	g_rl.cl++;
	g_rl.cc = 0;
	rl_scope_prompt(g_rl.scope->str);
	ft_dastrins_str(g_rl.txt, 0, "");
	if (*g_rl.scope->str == RL_SCP_START)
		*g_rl.scope->str = '\0';
}

t_rl		rl_get(void)
{
	return (g_rl);
}
