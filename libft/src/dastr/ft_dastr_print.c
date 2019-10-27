/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dastr_print.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 11:54:46 by abbesbes          #+#    #+#             */
/*   Updated: 2019/06/26 11:54:50 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_dastrprint_all(t_dastr *dastr, char *sep)
{
	int i;

	if (!dastr || dastr->max < 0 || dastr->len < 0)
		return (-1);
	i = -1;
	while (dastr->a[++i])
	{
		if (dastr->a[i]->str)
		{
			ft_putstr(dastr->a[i]->str);
			if (sep && dastr->a[i + 1])
				ft_putstr(sep);
		}
	}
	return (i);
}
