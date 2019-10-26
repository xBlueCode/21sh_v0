/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_edit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 17:01:17 by abbesbes          #+#    #+#             */
/*   Updated: 2019/03/27 15:02:30 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_rl.h"
#include "ftsh.h"

#include <fcntl.h>

extern t_rl		g_rl;
extern t_hist	g_his;

int				rl_insert_nl(int c)
{
	if (c != '\n')
		return (1);
	ft_dstrins_ch(g_rl.txt->a[g_rl.cl], -1, c);
	rl_cur_fromto(g_rl.cc, ft_strlenz(g_rl.txt->a[g_rl.cl]->str) - 1);
	ft_putchar('\n');
	return (0);
}

int				rl_insert_ch(int c)
{
	t_dstr	*line;

	rl_hist_reset();
	line = g_rl.txt->a[g_rl.cl];
	if (c == '\n')
		return (rl_insert_nl(c));
	ft_dstrins_ch(line, g_rl.cc++, c);
	ft_putchar(c);
	if (((g_rl.cc + g_rl.plen + 1) % g_rl.wc == 1))
	{
		RL_TPUTS("cr");
		RL_TPUTS("do");
	}
	if (line->str[g_rl.cc])
	{
		rl_putstr_wrap(line->str, g_rl.cc);
		rl_cur_fromto(ft_strlenz(line->str), g_rl.cc);
	}
	return (0);
}

int				rl_ctrl_del_ch(int c)
{
	t_dstr	*line;

	(void)c;
	line = g_rl.txt->a[g_rl.cl];
	if (!g_rl.cc)
		return (0);
	rl_cur_fromto(g_rl.cc, g_rl.cc - 1);
	rl_putnchar_wrap(' ', ft_strlenz(line->str + g_rl.cc - 1), g_rl.cc - 1);
	rl_cur_fromto(ft_strlenz(line->str), g_rl.cc - 1);
	ft_dstrdel_n(g_rl.txt->a[g_rl.cl], --g_rl.cc, 1);
	rl_putstr_wrap(line->str, g_rl.cc);
	rl_cur_fromto(ft_strlenz(line->str), g_rl.cc);
	return (0);
}
