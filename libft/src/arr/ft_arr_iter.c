/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arr_iter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 15:44:16 by abbesbes          #+#    #+#             */
/*   Updated: 2019/02/05 16:05:34 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_arr_iter(void **arr, void (*f)(void *))
{
	int i;

	i = 0;
	while (arr[i])
		(*f)(arr[i++]);
}
