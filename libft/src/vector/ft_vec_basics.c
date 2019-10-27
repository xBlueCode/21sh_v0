/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_basics.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 12:09:46 by abbesbes          #+#    #+#             */
/*   Updated: 2019/06/26 12:09:49 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_vecinit(t_vec *v, size_t max, t_free tfree, t_dup tdup)
{
	if (!v || !tfree || !max)
		return (KO);
	if (!(v->a = ft_memalloc((max + 1) * sizeof(void*))))
		return (KO);
	v->max = max;
	v->len = 0;
	v->tfree = tfree;
	v->tdup = tdup;
	while (max-- > 0)
		v->a[max] = NULL;
	return (OK);
}

int		ft_vecextend(t_vec *v)
{
	size_t	i;
	void	**anew;

	if (!v)
		return (KO);
	if (!(anew = ft_memalloc((2 * v->max + 1) * sizeof(void*))))
		return (KO);
	v->max *= 2;
	i = 0;
	while (i < v->len)
	{
		anew[i] = v->a[i];
		i++;
	}
	while (i <= v->max)
		anew[i++] = NULL;
	ft_memdel((void**)&(v->a));
	v->a = anew;
	return (OK);
}

int		ft_veccpy(t_vec *w, t_vec *v)
{
	size_t	i;

	if (!v || !v->a)
		return (KO);
	if (ft_vecinit(w, v->max, v->tfree, v->tdup) == KO)
		return (KO);
	i = 0;
	while (i < v->len)
	{
		w->a[i] = v->tdup(v->a[i]);
		i++;
	}
	while (i < v->max)
		w->a[i++] = NULL;
	return (OK);
}
