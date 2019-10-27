/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/04 14:40:42 by abbesbes          #+#    #+#             */
/*   Updated: 2018/11/22 12:48:54 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*mapped;

	if (!s || !f)
		return (NULL);
	if (!(mapped = ft_strnew(ft_strlen((char*)s))))
		return (NULL);
	i = -1;
	while (s[++i])
		mapped[i] = (*f)(s[i]);
	return (mapped);
}
