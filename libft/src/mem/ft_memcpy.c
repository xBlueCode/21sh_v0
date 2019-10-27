/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 13:11:08 by abbesbes          #+#    #+#             */
/*   Updated: 2018/11/21 20:43:24 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		i;
	char		*src_offset;
	char		*dst_offset;

	i = 0;
	src_offset = (char*)src;
	dst_offset = dst;
	while (++i - 1 < n)
		dst_offset[i - 1] = src_offset[i - 1];
	return (dst);
}
