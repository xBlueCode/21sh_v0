/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/24 18:58:14 by abbesbes          #+#    #+#             */
/*   Updated: 2018/12/25 16:18:06 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*pre_append_char(char *str, int s, char c)
{
	char	*dest;

	dest = (char*)malloc((s + 2) * sizeof(char));
	dest[s + 1] = '\0';
	dest[0] = c;
	while (--s > -1)
		dest[s + 1] = str[s];
	return (dest);
}

char	*ft_itoa_base(int value, int base)
{
	int				sign;
	char			*res;
	unsigned int	n;
	int				s;
	char			d;

	res = 0;
	if (base < 2 || base > 16)
		return (0);
	if ((sign = value < 0 ? 1 : 0))
		n = -value;
	else
		n = value;
	if ((s = 0) || n == 0)
		return (pre_append_char(res, 0, '0'));
	while (n)
	{
		d = n % base;
		d = d + 48 * (base < 11 || d < 10) + ('A' - 10) * (base > 10 && d > 9);
		n = n / base;
		res = pre_append_char(res, s++, d);
	}
	if (sign && base == 10)
		res = pre_append_char(res, s, '-');
	return (res);
}
