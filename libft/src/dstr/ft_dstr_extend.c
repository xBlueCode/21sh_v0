/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dstr_extend.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 11:59:05 by abbesbes          #+#    #+#             */
/*   Updated: 2019/03/15 14:00:42 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_dstrext_x2(t_dstr *dstr)
{
	char	*tstr;
	int		i;

	if (!dstr || !dstr->max)
		return (-1);
	dstr->max = 2 * dstr->max;
	tstr = dstr->str;
	if (!(dstr->str = (char*)malloc((dstr->max + 1) * sizeof(char))))
		return (-1);
	i = -1;
	while (tstr[++i])
		dstr->str[i] = tstr[i];
	while (i < dstr->max + 1)
		dstr->str[i++] = '\0';
	ft_memdel((void**)&tstr);
	return (0);
}

int		ft_dstrext_n(t_dstr *dstr, ssize_t n)
{
	char	*tstr;
	int		i;

	if (!dstr || !dstr->max || n < 1)
		return (-1);
	dstr->max = dstr->max + n;
	tstr = dstr->str;
	if (!(dstr->str = (char*)malloc((dstr->max + 1) * sizeof(char))))
		return (-1);
	i = -1;
	while (tstr[++i])
		dstr->str[i] = tstr[i];
	while (i < dstr->max + 1)
		dstr->str[i++] = '\0';
	ft_memdel((void**)&tstr);
	return (0);
}
