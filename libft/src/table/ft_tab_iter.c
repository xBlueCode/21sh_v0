/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_iter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 12:00:56 by abbesbes          #+#    #+#             */
/*   Updated: 2019/06/26 12:00:59 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_tabiter(t_table *table, int (*func)(t_trow))
{
	int		i;

	if (!table || !table->len || !func)
		return (-1);
	i = -1;
	while (++i < table->len)
		(*func)(ft_tabget_i(table, i));
	return (0);
}
