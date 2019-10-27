/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_basic.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 11:57:13 by abbesbes          #+#    #+#             */
/*   Updated: 2019/06/26 11:57:18 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_table			*ft_tabnew_max(ssize_t max)
{
	t_table		*table;

	if (!(table = (t_table*)ft_memalloc(sizeof(t_table))))
		return (NULL);
	table->name = ft_dastrnew_max(max);
	table->value = ft_dastrnew_max(max);
	table->opt = ft_dstrnew_max(max);
	table->len = 0;
	return (table);
}

int				ft_tabfree(t_table **ptab)
{
	if (!ptab)
		return (0);
	ft_dastrfree(&((*ptab)->name));
	ft_dastrfree(&((*ptab)->value));
	ft_dstrfree(&((*ptab)->opt));
	ft_memdel((void**)ptab);
	return (0);
}

t_table			*ft_tabdup(t_table *table)
{
	t_table *ntab;

	if (!table)
		return (NULL);
	ntab = (t_table*)ft_memalloc(sizeof(t_table));
	ntab->name = ft_dastrdup(table->name);
	ntab->value = ft_dastrdup(table->value);
	ntab->opt = ft_dstrnew_str(table->opt->str);
	ntab->len = table->len;
	return (ntab);
}

t_trow			ft_tabrow_set(ssize_t pos, char *name, char *value, char opt)
{
	t_trow	trow;

	trow.i = pos;
	trow.name = name;
	trow.value = value;
	trow.opt = opt;
	return (trow);
}
