/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/04 14:59:45 by abbesbes          #+#    #+#             */
/*   Updated: 2018/11/22 12:49:11 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*mapped;

	if (!s || !f)
		return (NULL);
	if (!(mapped = ft_strnew(ft_strlen((char*)s))))
		return (NULL);
	i = 0;
	while (s[i])
	{
		mapped[i] = (*f)(i, s[i]);
		i++;
	}
	return (mapped);
}
