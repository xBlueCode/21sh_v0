/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_autoc_menu_put.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 22:16:55 by abbesbes          #+#    #+#             */
/*   Updated: 2019/10/10 22:16:57 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftsh.h"

extern t_rl		g_rl;

int				rl_autoc_menu_putlist(t_dstr **list)
{
	int i;
	int slen;

	i = -1;
	if (!list)
		return (1);
	while (list[++i])
	{
		ft_putchar('\n');
		rl_putstr_wrapx(list[i]->str, 0, 0);
	}
	RL_TPUTS("cr");
	while (--i > -1)
	{
		slen = ft_strlenz(list[i]->str);
		rl_cur_move(slen - slen % g_rl.wc, 0, 0);
		if (i)
			RL_TPUTS_GO("UP", 1, 1);
	}
	ft_putstr(T_REV);
	rl_putstr_wrapx(list[0]->str, 0, 0);
	ft_putstr(T_END);
	return (0);
}
