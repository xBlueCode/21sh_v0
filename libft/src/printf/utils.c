/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/01 17:52:21 by abbesbes          #+#    #+#             */
/*   Updated: 2019/01/15 14:34:37 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <wchar.h>
#include <stdint.h>

size_t	fill_wchar_fd(int fd, wint_t ch, int len)
{
	int i;

	if (fd < 0 || len < 1)
		return (0);
	i = 0;
	while (++i <= len)
		ft_putwchar_fd(ch, fd);
	return (i - 1);
}

int		fill_char_fd(int fd, int ch, int len)
{
	int i;

	if (!ch || fd < 0 || len < 1)
		return (0);
	i = 0;
	while (++i <= len)
		ft_putchar_fd(ch, fd);
	return (i - 1);
}

int		get_uint_len(uintmax_t unum, int base)
{
	if (base < 0)
		return (-1);
	if (unum < (unsigned)base)
		return (1);
	return (1 + get_uint_len(unum / base, base));
}
