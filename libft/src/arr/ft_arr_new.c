/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arr_new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 19:19:24 by abbesbes          #+#    #+#             */
/*   Updated: 2019/02/07 13:12:28 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	**ft_arr_new(size_t n, size_t m)
{
	void	**arr;
	size_t	i;

	if (!(arr = (void **)ft_memalloc(n * sizeof(void *))))
		return (NULL);
	i = 0;
	while (i < n)
		if (!(arr[i++] = ft_memalloc(m)))
			return (NULL);
	return (arr);
}

ssize_t	ft_arr_len(void **arr)
{
	ssize_t i;

	if (!arr)
		return (-1);
	i = -1;
	while (arr[++i])
		;
	return (i);
}
