/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnstr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/02 20:28:24 by abbesbes          #+#    #+#             */
/*   Updated: 2019/01/02 20:32:40 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnstr_fd(const char *str, int n, int fd)
{
	int i;

	if (!str || n < 1 || fd < 0)
		return ;
	i = 0;
	while (i < n && str[i])
		ft_putchar_fd(str[i++], fd);
}

void	ft_putnstr(const char *str, int n)
{
	int i;

	if (!str || n < 1)
		return ;
	i = 0;
	while (i < n && str[i])
		write(1, &str[i++], 1);
}
