/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 17:13:19 by abbesbes          #+#    #+#             */
/*   Updated: 2019/02/05 12:55:24 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, size_t n)
{
	char	*new_str;

	if (!(new_str = ft_strnew(n)))
		return (NULL);
	ft_strncpy(new_str, s1, n);
	return (new_str);
}

char	*ft_strndup_free(char **s1, size_t n)
{
	char	*new;

	new = ft_strndup(*s1, n);
	ft_memdel((void**)s1);
	return (new);
}
