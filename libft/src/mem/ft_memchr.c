/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 13:45:42 by abbesbes          #+#    #+#             */
/*   Updated: 2018/11/14 14:39:29 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*offset;

	offset = (unsigned char*)s;
	i = 0;
	while (i < n)
		if (offset[i++] == (unsigned char)c)
			return (void*)(s + i - 1);
	return (NULL);
}
