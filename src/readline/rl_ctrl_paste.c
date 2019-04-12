/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_ctrl_paste.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 15:33:22 by abbesbes          #+#    #+#             */
/*   Updated: 2019/04/02 15:59:11 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftsh.h"

extern t_rl		g_rl;

int				rl_ctrl_xp_after(int c)
{
	t_dstr *dline;

	(void)c;
	if (g_rl.regi < 0 || !g_rl.reg->a[g_rl.regi])
	{
		ft_putchar(0x07);
		return (1);
	}
	dline = g_rl.txt->a[g_rl.cl];
	ft_dstrins_str(dline, g_rl.cc, g_rl.reg->a[g_rl.regi]->str);
	rl_putstr_wrap(dline->str, g_rl.cc);
	rl_cur_fromto(ft_strlenz(dline->str), g_rl.cc);
	ft_dastrdel_n(g_rl.reg, -1, 1);
	g_rl.regi--;
	return (0);
}

int				rl_ctrl_xo_before(int c)
{
	t_dstr *dline;

	(void)c;
	if (g_rl.regi < 0 || !g_rl.reg->a[g_rl.regi])
	{
		ft_putchar(0x07);
		return (1);
	}
	dline = g_rl.txt->a[g_rl.cl];
	ft_dstrins_str(dline, !g_rl.cc ? 0 : g_rl.cc, g_rl.reg->a[g_rl.regi]->str);
	//rl_cur_fromto(g_rl.cc, g_rl.cc);
	rl_putstr_wrap(dline->str, g_rl.cc);
	g_rl.cc += ft_strlenz(g_rl.reg->a[g_rl.regi]->str);
	rl_cur_fromto(ft_strlenz(dline->str), g_rl.cc);
	ft_dastrdel_n(g_rl.reg, -1, 1);
	g_rl.regi--;
	return (0);
}

int				rl_ctrl_x_lend(int c)
{
	t_dstr	*dline;
	ssize_t	cs;

	(void)c;
	if (g_rl.regi < 0 || !g_rl.reg->a[g_rl.regi])
	{
		ft_putchar(0x07);
		return (1);
	}
	dline = g_rl.txt->a[g_rl.cl];
	cs = ft_strlenz(dline->str);
	rl_cur_fromto(g_rl.cc, cs);
	ft_dstrins_str(dline, cs, g_rl.reg->a[g_rl.regi]->str);
	rl_putstr_wrap(dline->str, cs);
	rl_cur_fromto(ft_strlenz(dline->str), g_rl.cc);
	ft_dastrdel_n(g_rl.reg, -1, 1);
	g_rl.regi--;
	return (0);
}

int				rl_ctrl_x_lbeg(int c)
{
	t_dstr	*dline;
	ssize_t	cs;

	(void)c;
	if (g_rl.regi < 0 || !g_rl.reg->a[g_rl.regi])
	{
		ft_putchar(0x07);
		return (1);
	}
	dline = g_rl.txt->a[g_rl.cl];
	rl_cur_fromto(g_rl.cc, 0);
	cs = ft_strlenz(g_rl.reg->a[g_rl.regi]->str);
	ft_dstrins_str(dline, 0, g_rl.reg->a[g_rl.regi]->str);
	rl_putstr_wrap(dline->str, 0);
	rl_cur_fromto(ft_strlenz(dline->str), (g_rl.cc = g_rl.cc + cs));
	ft_dastrdel_n(g_rl.reg, -1, 1);
	g_rl.regi--;
	return (0);
}
