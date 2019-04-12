/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_ctrl_reg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 16:40:21 by abbesbes          #+#    #+#             */
/*   Updated: 2019/04/02 16:54:50 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftsh.h"

extern t_rl		g_rl;

int				rl_ctrl_reg_d(int c)
{
	(void)c;
	if (g_rl.regi < 0 || !g_rl.reg->a[g_rl.regi])
	{
		ft_putchar(0x07);
		return (1);
	}
	ft_dastrdel_n(g_rl.reg, -1, 1);
	g_rl.regi--;
	return (0);
}

int				rl_ctrl_reg_da(int c)
{
	(void)c;
	if (g_rl.regi < 0 || !g_rl.reg->a[g_rl.regi])
	{
		ft_putchar(0x07);
		return (1);
	}
	while (g_rl.regi-- > 0)
		ft_dastrdel_n(g_rl.reg, -1, 1);
	return (0);
}
