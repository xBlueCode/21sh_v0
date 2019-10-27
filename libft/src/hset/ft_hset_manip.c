/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hset_manip.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 18:45:53 by abbesbes          #+#    #+#             */
/*   Updated: 2019/10/21 18:45:54 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_hset_add(t_hset *hset, void *elem, int esize)
{
	int ind;

	if (!hset || !elem)
		return (-1);
	ind = hset->hcode(elem) % hset->max;
	if (ft_hset_contains(hset, elem))
		return (-1);
	ft_lstadd(&(hset->arr[ind]), ft_lstnew(elem, esize));
	hset->len++;
	return (0);
}

int		ft_hset_rem(t_hset *hset, void *elem)
{
	int		ind;

	if (!hset || !elem)
		return (-1);
	ind = hset->hcode(elem) % hset->max;
	if (!hset->arr[ind])
		return (1);
	ft_lst_free_if(&(hset->arr[ind]), hset->hequals, elem, hset->hfree);
	hset->len--;
	return (0);
}
