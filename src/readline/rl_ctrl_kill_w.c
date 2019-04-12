/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_ctrl_kill_w.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 12:48:48 by abbesbes          #+#    #+#             */
/*   Updated: 2019/04/01 13:54:22 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftsh.h"

extern t_rl		g_rl;

int				rl_ctrl_kill_w_before(int c)
{
	t_dstr	*dline;
	ssize_t	wbi;

	(void)c;
	dline = g_rl.txt->a[g_rl.cl];
	if (!g_rl.cc || (wbi = ft_strind_w_prev_beg(dline->str, g_rl.cc)) < 0)
	{
		ft_putchar(0x07);
		return (1);
	}
	rl_cur_fromto(g_rl.cc, wbi);
	rl_putnchar_wrap(' ', ft_strlenz(dline->str + wbi), wbi);
	rl_cur_fromto(ft_strlenz(dline->str), wbi);
	ft_dstrdel_n(dline, wbi, g_rl.cc - wbi);
	rl_putstr_wrap(dline->str, wbi);
	rl_cur_fromto(ft_strlenz(dline->str), wbi);
	g_rl.cc = wbi;
	return (0);
}

int				rl_ctrl_kill_w_after(int c)
{
	t_dstr	*dline;
	ssize_t	n;

	(void)c;
	dline = g_rl.txt->a[g_rl.cl];
	if (!dline->str[g_rl.cc] || ft_isspace(dline->str[g_rl.cc]))
	{
		ft_putchar(0x07);
		return (1);
	}
	n = g_rl.cc;
	while (!ft_isspace(dline->str[n]))
		n++;
	rl_putnchar_wrap(' ', ft_strlenz(dline->str + g_rl.cc), g_rl.cc);
	rl_cur_fromto(ft_strlenz(dline->str), g_rl.cc);
	ft_dstrdel_n(dline, g_rl.cc, n - g_rl.cc);
	rl_putstr_wrap(dline->str, g_rl.cc);
	rl_cur_fromto(ft_strlenz(dline->str), g_rl.cc);
	return (0);
}
