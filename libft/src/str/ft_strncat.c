/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 14:04:16 by abbesbes          #+#    #+#             */
/*   Updated: 2018/11/21 21:53:41 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	s;

	s = (size_t)ft_strlen(s1);
	i = 0;
	while (i < n && s2[i])
	{
		s1[s + i] = s2[i];
		i++;
	}
	s1[s + i] = '\0';
	return (s1);
}
