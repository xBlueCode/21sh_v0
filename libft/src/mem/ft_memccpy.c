/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 15:56:57 by abbesbes          #+#    #+#             */
/*   Updated: 2018/11/21 21:50:23 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t		i;
	char		*uc_dst;

	uc_dst = dst;
	i = 0;
	while (i < n)
	{
		uc_dst[i] = *((unsigned char *)src + i);
		if (*((unsigned char*)src + i) == (unsigned char)c)
			return ((void*)(uc_dst + i + 1));
		i++;
	}
	return (NULL);
}
