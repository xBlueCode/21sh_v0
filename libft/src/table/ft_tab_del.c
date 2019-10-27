/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_del.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 12:01:32 by abbesbes          #+#    #+#             */
/*   Updated: 2019/06/26 12:01:37 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_tabdel_i(t_table *table, ssize_t i)
{
	if (!table)
		return (-1);
	if (i < -1)
		return (ft_tabdel_i(table, table->len - 1));
	ft_dastrdel_n(table->name, i, 1);
	ft_dastrdel_n(table->value, i, 1);
	ft_dstrdel_n(table->opt, i, 1);
	table->len--;
	return (1);
}

int		ft_tabdel_n(t_table *table, char *name)
{
	ssize_t i;

	if (!name || !table)
		return (-1);
	i = -1;
	while (++i < table->len)
	{
		if (!ft_strcmp(name, table->name->a[i]->str))
			return (ft_tabdel_i(table, i));
	}
	return (0);
}
