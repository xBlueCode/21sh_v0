/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 17:48:46 by abbesbes          #+#    #+#             */
/*   Updated: 2018/11/20 22:34:29 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_nbr_len(int n)
{
	int l;

	l = 1 + (n < 0);
	while ((n /= 10))
		l++;
	return (l);
}

char		*ft_itoa(int n)
{
	char			*arr;
	unsigned int	un;
	int				l;

	l = count_nbr_len(n);
	if (!(arr = ft_strnew(l)))
		return (NULL);
	un = n < 0 ? -n : n;
	arr[--l] = un % 10 + '0';
	while ((un /= 10))
		arr[--l] = un % 10 + '0';
	if (n < 0)
		arr[0] = '-';
	return (arr);
}
