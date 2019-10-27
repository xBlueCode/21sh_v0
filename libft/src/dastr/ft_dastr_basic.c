/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dastr_basic.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 11:26:43 by abbesbes          #+#    #+#             */
/*   Updated: 2019/03/15 17:05:21 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dastr		*ft_dastrnew_max(ssize_t max)
{
	t_dastr		*dastr;

	if (!(dastr = (t_dastr*)malloc(sizeof(t_dastr))))
		return (NULL);
	if (!(dastr->a = (t_dstr**)malloc((max + 1) * sizeof(t_dstr*))))
	{
		ft_memdel((void**)&dastr);
		return (NULL);
	}
	dastr->max = max;
	while (max > -1)
		dastr->a[max--] = NULL;
	dastr->len = 0;
	return (dastr);
}

int			ft_dastrfree(t_dastr **dastr)
{
	int i;

	if (!dastr || !*dastr)
		return (0);
	if ((*dastr)->a)
	{
		i = -1;
		while (++i < (*dastr)->max)
			if ((*dastr)->a[i])
				ft_dstrfree(&((*dastr)->a[i]));
		ft_memdel((void**)&(*dastr)->a);
	}
	ft_memdel((void**)dastr);
	return (0);
}

int			ft_dastrclear(t_dastr *dastr)
{
	int i;

	if (!dastr)
		return (0);
	if ((dastr)->a)
	{
		i = -1;
		while (++i < (dastr)->max)
			if ((dastr)->a[i])
				ft_dstrfree(&((dastr)->a[i]));
		ft_memdel((void**)&(dastr)->a);
	}
	dastr->len = -1;
	dastr->max = -1;
	return (0);
}

int			ft_dastrcpy(t_dastr *dastr1, t_dastr *dastr2)
{
	if (!dastr1 || !dastr2)
		return (KO);
	dastr1->a = dastr2->a;
	dastr1->len = dastr2->len;
	dastr1->max = dastr2->max;
	return (OK);
}

t_dastr		*ft_dastrdup(t_dastr *dastr)
{
	t_dastr *ndastr;
	ssize_t i;

	if (!dastr)
		return (NULL);
	ndastr = ft_dastrnew_max(dastr->max);
	i = -1;
	while (++i < dastr->len)
		ft_dastrins_str(ndastr, -1, dastr->a[i]->str);
	return (ndastr);
}
