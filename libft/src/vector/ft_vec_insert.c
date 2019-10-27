/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_insert.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 12:10:03 by abbesbes          #+#    #+#             */
/*   Updated: 2019/06/26 12:10:06 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_vecins(t_vec *v, ssize_t i, void *item)
{
	if (!v || !item)
		return (KO);
	if (i < 0)
		i = v->len - 1;
	else if (i > v->len)
		i = v->len;
	if (v->len + 1 > v->max)
		ft_vecextend(v);
	v->a[i] = item;
	v->len++;
	return (OK);
}

int		ft_vecadd(t_vec *v, void *item)
{
	if (!v || !item)
		return (KO);
	if (v->len + 1 > v->max)
		ft_vecextend(v);
	v->a[v->len++] = item;
	return (OK);
}

int		ft_vecset(t_vec *v, ssize_t i, void *item)
{
	if (!v || !item || i >= v->len)
		return (KO);
	if (i < 0)
		i = v->len - 1;
	v->tfree(&(v->a[i]));
	v->a[i] = item;
	return (OK);
}
