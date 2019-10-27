/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/04 15:32:17 by abbesbes          #+#    #+#             */
/*   Updated: 2019/02/19 16:23:26 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	int		i;
	int		offset;

	if (!s1 || !s2)
		return (NULL);
	if (!(join = ft_strnew(ft_strlen((char*)s1) + ft_strlen((char*)s2))))
		return (NULL);
	offset = 0;
	i = 0;
	while (s1[i])
		join[offset++] = s1[i++];
	i = 0;
	while (s2[i])
		join[offset++] = s2[i++];
	return (join);
}

char	*ft_strjoin_safe(char const *s1, char const *s2)
{
	if (!s1 && !s2)
		return (ft_strdup(""));
	else if (!s1)
		return (ft_strdup(s2));
	else if (!s2)
		return (ft_strdup(s1));
	else
		return (ft_strjoin(s1, s2));
}

char	*ft_strjoin_safe_free(char const **s1, char const **s2)
{
	char		*res;

	res = ft_strjoin_safe(*s1, *s2);
	ft_memdel((void**)s1);
	ft_memdel((void**)s2);
	return (res);
}
