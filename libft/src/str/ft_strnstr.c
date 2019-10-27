/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 14:06:07 by abbesbes          #+#    #+#             */
/*   Updated: 2018/11/20 22:15:21 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	offset;

	if (!*needle)
		return ((char *)haystack);
	offset = 0;
	while (haystack[offset])
	{
		i = 0;
		while (haystack[offset + i] == needle[i] && offset + i < len)
			if (!needle[++i])
				return ((char *)(haystack + offset));
		offset++;
	}
	return (0);
}
