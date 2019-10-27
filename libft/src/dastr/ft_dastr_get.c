/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dastr_get.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 12:04:44 by abbesbes          #+#    #+#             */
/*   Updated: 2019/03/15 12:19:18 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dstr		*ft_dastrget_last(t_dastr *dastr)
{
	int i;

	if (!dastr || !dastr->a)
		return (NULL);
	i = -1;
	while (dastr->a[++i])
		;
	if (i)
		return (dastr->a[i - 1]);
	return (NULL);
}

t_dstr		*ft_dastrget_i(t_dastr *dastr, ssize_t i)
{
	if (!dastr || i > dastr->len - 1)
		return (NULL);
	if (i < 0)
		return (dastr->a[dastr->len - 1]);
	return (dastr->a[i]);
}

t_dstr		*ft_dastrget_str(t_dastr *dastr, char *str)
{
	ssize_t i;

	if (!dastr || !str)
		return (NULL);
	i = -1;
	while (dastr->a[++i])
		if (!ft_strcmp(dastr->a[i]->str, str))
			return (dastr->a[i]);
	return (NULL);
}
