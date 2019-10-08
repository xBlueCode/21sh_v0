/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_ctrl_move.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 13:40:28 by abbesbes          #+#    #+#             */
/*   Updated: 2019/03/27 14:07:47 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftsh.h"

extern t_rl		g_rl;

int				rl_ctrl_move_ri(int c)
{
	if (c == KRIGHT && g_rl.txt->a[g_rl.cl]->str[g_rl.cc] && ++g_rl.cc)
		rl_cur_fromto(g_rl.cc - 1, g_rl.cc);
	return (0);
}

int				rl_ctrl_move_le(int c)
{
	if (c == KLEFT && g_rl.cc && g_rl.cc--)
		rl_cur_fromto(g_rl.cc + 1, g_rl.cc);
	return (0);
}

int				rl_ctrl_move_up(int c)
{
	if (c == KUP && g_rl.cc - g_rl.wc > -1)
	{
		rl_cur_fromto(g_rl.cc, g_rl.cc - g_rl.wc);
		g_rl.cc = g_rl.cc - g_rl.wc;
	}
	return (0);
}

int				rl_ctrl_move_do(int c)
{
	if (c == KDOWN)
	{
		if (ft_strlenz(g_rl.txt->a[g_rl.cl]->str)
				>= (size_t)(g_rl.cc + g_rl.wc))
		{
			rl_cur_fromto(g_rl.cc, g_rl.cc + g_rl.wc);
			g_rl.cc = g_rl.cc + g_rl.wc;
		}
	}
	return (0);
}
