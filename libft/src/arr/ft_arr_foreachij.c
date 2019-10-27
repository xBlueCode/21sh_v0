/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arr_foreachij.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 14:19:05 by abbesbes          #+#    #+#             */
/*   Updated: 2018/11/20 21:59:47 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_arr_foreachij(void **arr, int i, int j, void (*f)(void *))
{
	if (j < 0)
	{
		j = 0;
		while (arr[j])
			j++;
	}
	if (i < 0 || i >= j)
		return ;
	while (i < j && arr[i])
		(*f)(arr[i++]);
}
