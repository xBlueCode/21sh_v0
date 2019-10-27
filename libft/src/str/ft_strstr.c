/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 14:05:42 by abbesbes          #+#    #+#             */
/*   Updated: 2018/11/20 22:15:01 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int offset;
	int i;

	if (!(*needle))
		return ((char*)haystack);
	offset = 0;
	i = 0;
	while (needle[i] && haystack[offset + i])
		if (haystack[offset + i] != needle[i])
			i = 0 * offset++;
		else
			i++;
	if (!needle[i])
		return ((char*)(haystack + offset));
	return (NULL);
}
