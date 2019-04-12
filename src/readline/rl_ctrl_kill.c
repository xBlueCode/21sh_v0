/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_kill.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 11:16:28 by abbesbes          #+#    #+#             */
/*   Updated: 2019/03/29 14:30:13 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftsh.h"

extern t_rl		g_rl;

int				rl_ctrl_kill_before(int c)
{
	t_dstr	*dline;

	(void)c;
	if (!g_rl.cc)
	{
		ft_putchar(0x07);
		return (1);
	}
	dline = g_rl.txt->a[g_rl.cl];
	rl_cur_fromto(g_rl.cc, 0);
	rl_putnchar_wrap(' ', ft_strlenz(dline->str), 0);
	rl_cur_fromto(ft_strlenz(dline->str), 0);
	ft_dstrdel_n(dline, 0, g_rl.cc);
	rl_putstr_wrap(dline->str, 0);
	rl_cur_fromto(ft_strlenz(dline->str), (g_rl.cc = 0));
	return (0);
}

int				rl_ctrl_kill_after(int c)
{
	t_dstr	*dline;

	(void)c;
	dline = g_rl.txt->a[g_rl.cl];
	if (!dline->str[g_rl.cc])
	{
		ft_putchar(0x07);
		return (1);
	}
	rl_putnchar_wrap(' ', ft_strlenz(dline->str + g_rl.cc), g_rl.cc);
	rl_cur_fromto(ft_strlenz(dline->str), g_rl.cc);
	ft_dstrdel_n(dline, -1, ft_strlenz(dline->str + g_rl.cc));
	return (0);
}

int				rl_ctrl_kill_w(int c)
{
	t_dstr		*dline;
	ssize_t		ilen[2];

	(void)c;
	dline = g_rl.txt->a[g_rl.cl];
	if (!dline->str[g_rl.cc]
			|| ft_strind_w_get_ilen(dline->str, g_rl.cc, ilen) < 0)
	{
		ft_putchar(0x07);
		return (1);
	}
	rl_cur_fromto(g_rl.cc, ilen[0]);	
	rl_putnchar_wrap(' ', ft_strlenz(dline->str + ilen[0]), ilen[0]);
	rl_cur_fromto(ft_strlenz(dline->str), (g_rl.cc = ilen[0]));
	ft_dstrdel_n(dline, g_rl.cc, ilen[1]);
	rl_putstr_wrap(dline->str, g_rl.cc);
	rl_cur_fromto(ft_strlenz(dline->str), g_rl.cc);
	return (0);
}

int				rl_ctrl_kill_wf(int c)
{
	t_dstr		*dline;
	ssize_t		ilen[2];

	(void)c;
	dline = g_rl.txt->a[g_rl.cl];
	if (!dline->str[g_rl.cc]
			|| ft_strind_w_next_get_ilen(dline->str, g_rl.cc, ilen) < 0)
	{
		ft_putchar(0x07);
		return (1);
	}
	rl_putnchar_wrap(' ', ft_strlenz(dline->str + g_rl.cc), g_rl.cc);
	rl_cur_fromto(ft_strlenz(dline->str), g_rl.cc);
	ft_dstrdel_n(dline, ilen[0], ilen[1]);
	rl_putstr_wrap(dline->str, g_rl.cc);
	rl_cur_fromto(ft_strlenz(dline->str), g_rl.cc);
	return (0);
}
