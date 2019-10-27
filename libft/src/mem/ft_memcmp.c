/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 13:54:05 by abbesbes          #+#    #+#             */
/*   Updated: 2018/11/14 14:40:43 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*offset1;
	unsigned char	*offset2;

	offset1 = (unsigned char*)s1;
	offset2 = (unsigned char*)s2;
	i = 0;
	while (i < n)
	{
		if (offset1[i] != offset2[i])
			return (offset1[i] - offset2[i]);
		i++;
	}
	return (0);
}
