/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 19:03:28 by abbesbes          #+#    #+#             */
/*   Updated: 2018/11/20 22:06:57 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t i;

	i = -1;
	if ((char*)dst > (char*)src)
		while ((int)--len > -1)
			*((char*)dst + len) = *((char*)src + len);
	else
		while (++i < len)
			*((char*)dst + i) = *((char*)src + i);
	return (dst);
}
