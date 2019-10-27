/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dstr_del.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 13:27:02 by abbesbes          #+#    #+#             */
/*   Updated: 2019/03/14 17:15:31 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_dstrdel_n(t_dstr *dstr, ssize_t i, ssize_t n)
{
	ssize_t k;
	ssize_t	s;

	if (!dstr || n <= 0)
		return (-1);
	if (i < 0)
	{
		if ((s = ft_strlenz(dstr->str)) >= n)
			return (ft_dstrdel_n(dstr, s - n, n));
		return (ft_dstrdel_n(dstr, 0, ft_strlen(dstr->str)));
	}
	else
	{
		if (i + n > dstr->len)
			n = dstr->len - i;
		s = dstr->len;
		k = -1;
		while (i + n + ++k < s)
			dstr->str[i + k] = dstr->str[i + n + k];
		while (i + k < dstr->max)
			dstr->str[i + k++] = '\0';
		dstr->len -= n;
		dstr->str[dstr->len] = '\0';
		return (0);
	}
}
