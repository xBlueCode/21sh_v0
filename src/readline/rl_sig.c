/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_sig.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 17:21:55 by abbesbes          #+#    #+#             */
/*   Updated: 2019/10/14 17:22:00 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftsh.h"

extern t_rl	g_rl;

void		rl_sighand_parent(int sn)
{
	if (sn == SIGINT)
	{
		ft_putchar_fd('\n', 1);
		rl_sigint();
		//prompt_display();
		//rl_free();
		//rl_start();
		signal(SIGINT, rl_sighand_parent);
	}
}

void		rl_sighand_child(int sn)
{
	(void)sn;
	if (sn == SIGINT)
	{
		ft_putchar_fd('\n', 1);
		rl_free();
		signal(SIGINT, rl_sighand_parent);
	}
	//exit(0);
}
