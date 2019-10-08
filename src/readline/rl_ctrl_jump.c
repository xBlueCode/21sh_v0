/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_ctrl_jump.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 13:53:06 by abbesbes          #+#    #+#             */
/*   Updated: 2019/04/01 14:26:06 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftsh.h"

extern t_rl		g_rl;

int				rl_ctrl_jump_end(int c)
{
	(void)c;
	if (g_rl.cc != (ssize_t)ft_strlenz(g_rl.txt->a[g_rl.cl]->str))
	{
		rl_cur_fromto(g_rl.cc, ft_strlenz(g_rl.txt->a[g_rl.cl]->str));
		g_rl.cc = ft_strlenz(g_rl.txt->a[g_rl.cl]->str);
		return (0);
	}
	return (0);
}

int				rl_ctrl_jump_beg(int c)
{
	(void)c;
	if (g_rl.cc)
	{
		rl_cur_fromto(g_rl.cc, 0);
		g_rl.cc = 0;
		return (0);
	}
	return (0);
}

int				rl_ctrl_jump_w_next_end(int c)
{
	int to;

	(void)c;
	if ((to = ft_strind_w_next_end(g_rl.txt->a[g_rl.cl]->str, g_rl.cc)) < 0)
	{
		ft_putchar(0x07);
		return (0);
	}
	rl_cur_fromto(g_rl.cc, to);
	g_rl.cc = to;
	return (0);
}

int				rl_ctrl_jump_w_next_beg(int c)
{
	int to;

	(void)c;
	if ((to = ft_strind_w_next_beg(g_rl.txt->a[g_rl.cl]->str, g_rl.cc)) < 0)
	{
		ft_putchar(0x07);
		return (0);
	}
	rl_cur_fromto(g_rl.cc, to);
	g_rl.cc = to;
	return (0);
}

int				rl_ctrl_jump_w_prev_beg(int c)
{
	int to;

	(void)c;
	if ((to = ft_strind_w_prev_beg(g_rl.txt->a[g_rl.cl]->str, g_rl.cc)) < 0)
	{
		ft_putchar(0x07);
		return (0);
	}
	rl_cur_fromto(g_rl.cc, to);
	g_rl.cc = to;
	return (0);
}
