/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 19:31:25 by abbesbes          #+#    #+#             */
/*   Updated: 2019/10/07 19:31:27 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_rl.h"

extern t_rl		g_rl;

int				rl_putstr_wrap(char *str, ssize_t cc)
{
	ssize_t i;

	if (!str || cc < 0)
		return (1);
	i = cc - 1;
	while (str[++i])
	{
		ft_putchar(str[i]);
		if (!((i + g_rl.plen + 1) % g_rl.wc))
			ft_putchar('\n');
	}
	return (0);
}

int				rl_putstr_wrapx(char *str, ssize_t cc, int plen)
{
	ssize_t i;

	if (!str || cc < 0)
		return (1);
	i = cc - 1;
	while (str[++i])
	{
		ft_putchar(str[i]);
		if (!((i + plen + 1) % g_rl.wc))
			ft_putchar('\n');
	}
	return (0);
}

int				rl_putstr_nowrapx(char *str, ssize_t cc, int plen)
{
	ssize_t	l;

	if (!str || cc < 0)
		return (1);
	l = ft_strlenz(str);
	if (l + plen <= g_rl.wc)
		ft_putstr(str + cc);
	else
	{
		ft_putnstr(str + cc, g_rl.wc - 3);
		ft_putstr(T_BLK"..."T_END);
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

int				rl_putnchar_wrapx(char c, int n, ssize_t cc, int plen)
{
	ssize_t i;

	i = -1;
	while (++i < n)
	{
		ft_putchar(c);
		if (!((i + cc + plen + 1) % g_rl.wc))
			ft_putchar('\n');
	}
	return (0);
}
