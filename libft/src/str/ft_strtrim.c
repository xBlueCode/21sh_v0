/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/04 15:43:47 by abbesbes          #+#    #+#             */
/*   Updated: 2018/11/20 22:28:58 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_ws(int c)
{
	return (c == ' ' || c == ',' || c == '\n' || c == '\t');
}

char		*ft_strtrim(char const *s)
{
	int		i;
	int		j;

	if (!s)
		return (NULL);
	i = 0;
	while (is_ws(s[i]))
		i++;
	if (!s[i])
		return (ft_strnew(1));
	j = i - 1;
	while (s[++j])
		;
	while (is_ws(s[--j]))
		;
	return (ft_strsub(s, (unsigned int)i, (size_t)(j - i + 1)));
}
