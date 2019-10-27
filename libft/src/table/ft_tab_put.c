/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_put.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 12:01:06 by abbesbes          #+#    #+#             */
/*   Updated: 2019/06/26 12:01:09 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_tabput(t_table *table, char *sep)
{
	int		i;
	t_trow	trow;

	if (!table || !table->len)
		return (-1);
	i = -1;
	while (++i < table->len)
	{
		trow = ft_tabget_i(table, i);
		ft_putstr(trow.name ? trow.name : "");
		ft_putstr(sep ? sep : "");
		ft_putendl(trow.value ? trow.value : "");
	}
	return (0);
}
