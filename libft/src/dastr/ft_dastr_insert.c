/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dastr_insert.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 12:32:17 by abbesbes          #+#    #+#             */
/*   Updated: 2019/03/15 16:31:15 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_dastrins_str(t_dastr *dastr, ssize_t i, char *str)
{
	ssize_t	al;
	ssize_t	j;
	t_dstr	*dstr;

	if (!dastr || !str)
		return (-1);
	al = ft_arr_len((void**)dastr->a);
	if (i > al || !(dstr = ft_dstrnew_str(str)))
		return (-1);
	if (i < 0)
		i = al;
	if (al + 1 > dastr->max)
		ft_dastrext_x2(dastr);
	j = al + 1;
	while (--j > i)
		dastr->a[j] = dastr->a[j - 1];
	dastr->a[i] = dstr;
	dastr->len++;
	ft_dstrfree(&dastr->a[dastr->len]);
	return (0);
}

int			ft_dastrins_str_free(t_dastr *dastr, ssize_t i, char **str)
{
	int ret;

	ret = ft_dastrins_str(dastr, i, *str);
	ft_memdel((void**)str);
	return (ret);
}
