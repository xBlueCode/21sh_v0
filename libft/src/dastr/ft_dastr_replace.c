/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dastr_replace.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 11:54:21 by abbesbes          #+#    #+#             */
/*   Updated: 2019/06/26 11:54:29 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_dastrrep_str(t_dastr *dastr, ssize_t i, char *str)
{
	if (!dastr || !str || i > dastr->len - 1)
		return (-1);
	if (i < 0)
		return (ft_dastrrep_str(dastr, dastr->len - 1, str));
	ft_memdel((void**)&(dastr->a[i]->str));
	dastr->a[i]->str = ft_strdup(str);
	return (0);
}
