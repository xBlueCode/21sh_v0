/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuint_base_fd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 20:40:35 by abbesbes          #+#    #+#             */
/*   Updated: 2019/01/07 19:09:19 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdint.h>

void	ft_putuint_base_fd(uintmax_t n, int base, int ch, int fd)
{
	if (base < 0 || fd < 0)
		return ;
	if (n >= (unsigned)base)
	{
		ft_putuint_base_fd(n / base, base, ch, fd);
		ft_putuint_base_fd(n % base, base, ch, fd);
	}
	else
		ft_putchar_fd((n + '0') * (base <= 10 || n < 10)
				+ (n % 10 + ch) * (n >= 10), fd);
}
