/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 14:56:13 by abbesbes          #+#    #+#             */
/*   Updated: 2019/03/26 15:00:57 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_rl.h"

extern t_rl		g_rl;

int				rl_putstr_wrap(char *str, ssize_t cc)
{
	ssize_t i;

	i = cc - 1;
	while (str[++i])
	{
		ft_putchar(str[i]);
		if (!((i + g_rl.plen + 1) % g_rl.wc))
			ft_putchar('\n');
	}
	return (0);
}

int				rl_putnchar_wrap(char c, int n, ssize_t cc)
{
	ssize_t i;

	i = -1;
	while (++i < n)
	{
		ft_putchar(c);
		if (!((i + cc + g_rl.plen + 1) % g_rl.wc))
			ft_putchar('\n');
	}
	return (0);
}
