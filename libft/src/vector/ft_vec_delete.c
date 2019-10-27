/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_delete.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 12:09:55 by abbesbes          #+#    #+#             */
/*   Updated: 2019/06/26 12:09:57 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_vecdel(t_vec *v, ssize_t i)
{
	if (!v || !v->a || i >= v->len)
		return (KO);
	if (i < 0)
		i = v->len - 1;
	v->tfree(&(v->a[i--]));
	while (++i < v->len - 1)
		v->a[i] = v->a[i + 1];
	v->a[i] = NULL;
	v->len--;
	return (OK);
}

int		ft_vecfree(t_vec *v)
{
	size_t i;

	if (!v || !v->a)
		return (KO);
	i = 0;
	while (i < v->len)
		v->tfree(&(v->a[i++]));
	ft_memdel((void**)&(v->a));
	v->tfree = NULL;
	v->tdup = NULL;
	v->len = 0;
	v->max = 0;
	return (OK);
}
