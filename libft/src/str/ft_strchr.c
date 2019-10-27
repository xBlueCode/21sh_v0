/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 14:04:53 by abbesbes          #+#    #+#             */
/*   Updated: 2019/04/11 14:02:05 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strchr(const char *s, int c)
{
	int		i;
	char	*ss;

	ss = (char*)s;
	i = -1;
	while (ss[++i])
		if (ss[i] == c)
			return (ss + i);
	if (c == '\0')
		return (ss + i);
	else
		return (NULL);
}

char		*ft_strchr_inv(const char *s, int c)
{
	ssize_t	l;
	char	*ss;

	if (!s)
		return (NULL);
	ss = (char*)s;
	l = ft_strlenz(ss);
	while (--l > -1)
		if (ss[l] == c)
			return (ss + l);
	return (NULL);
}

ssize_t		ft_strichr(const char *s, int c)
{
	int i;

	i = -1;
	while (s[++i])
		if (s[i] == c)
			return (i);
	return (-1);
}
