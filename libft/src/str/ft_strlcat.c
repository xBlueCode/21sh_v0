/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 14:04:28 by abbesbes          #+#    #+#             */
/*   Updated: 2018/11/21 21:54:19 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t		i;
	int			j;
	size_t		dst_len;
	size_t		src_len;

	i = ft_strlen(dst);
	j = 0;
	dst_len = ft_strlen((char*)dst);
	src_len = ft_strlen((char*)src);
	if (dstsize < dst_len)
		return (src_len + dstsize);
	while (i < dstsize - 1 && *(src + j))
		*(dst + i++) = *(src + j++);
	*(dst + i) = '\0';
	return (dst_len + src_len);
}
