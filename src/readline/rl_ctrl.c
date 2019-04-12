/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_ctrl.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 17:43:58 by abbesbes          #+#    #+#             */
/*   Updated: 2019/04/01 14:19:37 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftsh.h"

extern t_rl		g_rl;

int				rl_ctrl_perform(int c)
{
	int i;

	i = -1;
	while (g_rl_ctrl_keymap[++i])
		if (g_rl_ctrl_keymap[i] == c)
			return (g_rl_ctrl_action[i](c) + 1);
	//ft_printf("\n%#x", c);
	return (0);
}

int				rl_vim_perform(int c)
{
	int i;
	int c1;

	if (g_rl.mode != RL_MODE_VIM || c == '\n')
		return (0);
	//c = ft_tolower(c);
	i = -1;
	while (g_rl_vim_keymap[++i])
	{
		if (g_rl_vim_keymap[i] == c)
			return (g_rl_vim_action[i](c) + 1);
		else if ((g_rl_vim_keymap[i] & 0xff00) == (c << 8)
				&& !(c1 = '\0') && read(0, &c1, sizeof(int)))
		{
			while ((g_rl_vim_keymap[i] & 0xff00) == (c << 8))
			{
				if ((g_rl_vim_keymap[i++] & 0xff) == c1)
					return (g_rl_vim_action[i - 1]((c << 8) | c1) + 1);
			}
			i--;
		}
	}
	ft_putchar(0x07);
	return (1);
}

int				rl_mode_toggle(int c)
{
	if (c == KESC)
		g_rl.mode = g_rl.mode == RL_MODE_INS ? RL_MODE_VIM : RL_MODE_INS;
	else if (g_rl.mode == RL_MODE_VIM && c == 'i')
		g_rl.mode = RL_MODE_INS;
	return (0);
}
