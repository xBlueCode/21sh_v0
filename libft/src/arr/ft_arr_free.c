/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arr_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 12:50:23 by abbesbes          #+#    #+#             */
/*   Updated: 2018/12/12 19:45:00 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_arr_free(void ***arr, size_t s)
{
	size_t i;

	if (!arr || !*arr)
		return ;
	i = 0;
	while (i < s)
		if ((*arr)[i])
			ft_memdel(&((*arr)[i++]));
	free(*arr);
	*arr = NULL;
}
