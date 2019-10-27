/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dastr_extend.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 12:48:42 by abbesbes          #+#    #+#             */
/*   Updated: 2019/03/15 16:26:16 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_dastrext_x2(t_dastr *dastr)
{
	if (!dastr || !dastr->max)
		return (-1);
	return (ft_dastrext_n(dastr, dastr->max));
}

int			ft_dastrext_n(t_dastr *dastr, ssize_t n)
{
	t_dstr	**ta;
	ssize_t	i;

	if (!dastr || !dastr->max)
		return (-1);
	dastr->max += n;
	ta = dastr->a;
	if (!(dastr->a = (t_dstr**)malloc((dastr->max + 1) * sizeof(t_dstr*))))
		return (-1);
	i = -1;
	while (ta[++i])
		dastr->a[i] = ta[i];
	while (i < dastr->max + 1)
		dastr->a[i++] = NULL;
	ft_memdel((void**)&ta);
	return (0);
}
