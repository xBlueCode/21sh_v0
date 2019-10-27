/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dstr_replace.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 10:59:30 by abbesbes          #+#    #+#             */
/*   Updated: 2019/03/28 11:03:04 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_dstrrep_ch(t_dstr *dstr, ssize_t i, int c)
{
	if (!dstr || !dstr->str || i > dstr->max)
		return (-1);
	if (i < 0 && (i = ft_strlenz(dstr->str) - 1) < 0)
		return (-1);
	dstr->str[i] = c;
	return (0);
}
