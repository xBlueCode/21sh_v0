/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 14:02:45 by abbesbes          #+#    #+#             */
/*   Updated: 2019/06/26 11:56:51 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*new_str;
	int		s;

	s = 0;
	while (s1[s])
		s++;
	new_str = (char*)malloc((s + 1) * sizeof(char));
	if (!new_str)
		return (NULL);
	new_str[s] = '\0';
	while (--s > -1)
		new_str[s] = s1[s];
	return (new_str);
}

char	*ft_strdup_cond(char *str, int (*cond)(int c))
{
	int		i;

	if (!str)
		return (NULL);
	if (!cond)
		return (ft_strdup(str));
	i = 0;
	while ((*cond)(str[i]))
		i++;
	return (ft_strndup(str, i));
}
