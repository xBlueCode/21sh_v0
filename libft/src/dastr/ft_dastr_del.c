/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dastr_del.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 16:35:01 by abbesbes          #+#    #+#             */
/*   Updated: 2019/03/15 16:48:58 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_dastrdel_n(t_dastr *dastr, ssize_t i, ssize_t n)
{
	ssize_t k;
	ssize_t al;

	if (!dastr || n <= 0)
		return (-1);
	if (i < 0 && (al = ft_arr_len((void**)dastr->a)))
		return (ft_dastrdel_n(dastr, al - n, n));
	else
	{
		al = dastr->len;
		if (i + n > al)
			n = al - i;
		k = -1;
		while (++k < n)
			ft_dstrfree(&(dastr->a[i + k]));
		k = -1;
		while (i + n + ++k < al + 1)
			dastr->a[i + k] = dastr->a[i + n + k];
		dastr->len--;
		return (0);
	}
}
