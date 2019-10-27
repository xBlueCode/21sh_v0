/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_get.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 11:58:10 by abbesbes          #+#    #+#             */
/*   Updated: 2019/06/26 11:58:13 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_trow		ft_tabget_i(t_table *table, ssize_t i)
{
	if (i < -1)
		return (ft_tabget_i(table, table->len - 1));
	if (!table || (i > table->len - 1))
		return (ft_tabrow_set(-1, NULL, NULL, -1));
	return (ft_tabrow_set(i, table->name->a[i]->str,
		table->value->a[i]->str, table->opt->str[i]));
}

t_trow		ft_tabget_n(t_table *table, char *name)
{
	ssize_t i;

	if (!table || !name || !table->len)
		return (ft_tabrow_set(-1, NULL, NULL, -1));
	i = -1;
	while (++i < table->len)
	{
		if (!ft_strcmp(name, table->name->a[i]->str))
			return (ft_tabrow_set(i, table->name->a[i]->str,
				table->value->a[i]->str, table->opt->str[i]));
	}
	return (ft_tabrow_set(-1, NULL, NULL, -1));
}

t_trow		ft_tabget_v(t_table *table, char *val)
{
	ssize_t i;

	if (!table || !val || !table->len)
		return (ft_tabrow_set(-1, NULL, NULL, -1));
	i = -1;
	while (++i < table->len)
	{
		if (!ft_strcmp(val, table->value->a[i]->str))
			return (ft_tabrow_set(i, table->name->a[i]->str,
				table->value->a[i]->str, table->opt->str[i]));
	}
	return (ft_tabrow_set(-1, NULL, NULL, -1));
}
