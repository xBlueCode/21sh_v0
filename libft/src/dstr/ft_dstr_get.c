/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dstr_get.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 16:10:25 by abbesbes          #+#    #+#             */
/*   Updated: 2019/03/17 17:49:15 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_dstrget_ch(t_dstr *dstr, ssize_t i)
{
	if (!dstr || !dstr->str || i > dstr->max)
		return ('\0');
	if (i < 0 && (i = ft_strlenz(dstr->str) - 1) < 0)
		return ('\0');
	return (dstr->str[i]);
}
