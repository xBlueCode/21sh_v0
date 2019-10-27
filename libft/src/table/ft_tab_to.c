/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_to.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 12:00:46 by abbesbes          #+#    #+#             */
/*   Updated: 2019/06/26 12:00:48 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_tabto_arr(t_table *table,
	int (*filter)(t_trow), char *(*builder)(t_trow))
{
	int		i;
	int		al;
	ssize_t	*sel;
	char	**arr;

	if (!table)
		return (NULL);
	sel = ft_memalloc((table->len + 1) * sizeof(ssize_t));
	i = -1;
	al = 0;
	while (++i < table->len)
		if (!filter || (*filter)(ft_tabget_i(table, i)))
			sel[al++] = i;
	arr = (char**)ft_memalloc((al + 1) * sizeof(char*));
	i = -1;
	while (++i < al)
		arr[i] = (*builder)(ft_tabget_i(table, sel[i]));
	arr[i] = NULL;
	ft_memdel((void**)&sel);
	return (arr);
}
