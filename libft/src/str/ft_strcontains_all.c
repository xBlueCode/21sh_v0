/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcontains_all.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 12:20:10 by abbesbes          #+#    #+#             */
/*   Updated: 2018/12/04 12:24:03 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

size_t	ft_strcontains_all(char *str, int c)
{
	int n;

	if (!str || c == '\0')
		return (0);
	n = 0;
	while (*str)
	{
		if (*str == c)
			n++;
		str++;
	}
	return (n);
}
