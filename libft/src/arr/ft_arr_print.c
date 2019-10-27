/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_arr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 14:50:57 by abbesbes          #+#    #+#             */
/*   Updated: 2018/11/20 21:56:30 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	print(void *ar)
{
	ft_putendl((char *)ar);
}

void		ft_arr_print(char **arr, int size)
{
	ft_arr_foreachij((void*)arr, 0, size, &print);
}
