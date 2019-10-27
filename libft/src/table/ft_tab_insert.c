/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_insert.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 12:01:16 by abbesbes          #+#    #+#             */
/*   Updated: 2019/06/26 12:01:18 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_tabins(t_table *table, t_trow trow, int mode)
{
	ssize_t i;

	if (!table || !trow.name)
		return (KO);
	if (!trow.value)
		trow.value = "";
	i = 0;
	while (i < table->len && ft_strcmp(trow.name, table->name->a[i]->str))
		i++;
	if (i < table->len && mode == 0)
		return (OK);
	if (i < table->len)
	{
		ft_dastrrep_str(table->value, i, trow.value);
		table->opt->str[i] = trow.opt;
	}
	else
	{
		ft_dastrins_str(table->name, i, trow.name);
		ft_dastrins_str(table->value, i, trow.value);
		ft_dstrins_ch(table->opt, i, trow.opt);
		table->len++;
	}
	return (OK);
}
