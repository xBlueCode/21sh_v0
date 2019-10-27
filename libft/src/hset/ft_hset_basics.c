/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hset_basics.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 18:54:45 by abbesbes          #+#    #+#             */
/*   Updated: 2019/10/21 18:54:46 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_hset		*ft_hset_init(int max, t_hcode hcode,
		t_equals hequals, t_free hfree)
{
	t_hset	*hset;

	hset = (t_hset*)ft_memalloc(sizeof(t_hset));
	hset->max = max;
	hset->len = 0;
	hset->arr = (t_list**)ft_memalloc((max + 1) * sizeof(t_list*));
	while (max > -1)
		hset->arr[max--] = NULL;
	hset->hcode = hcode;
	hset->hequals = hequals;
	hset->hfree = hfree;
	return (hset);
}

int			ft_hset_contains(t_hset *hset, void *elem)
{
	t_list	*lst;
	int		ind;

	if (!hset || !elem)
		return (0);
	ind = hset->hcode(elem) % hset->max;
	if (!hset->arr[ind])
		return (0);
	lst = hset->arr[ind];
	while (lst)
	{
		if (hset->hequals(elem, lst->content))
			return (1);
		else
			lst = lst->next;
	}
	return (0);
}

int			ft_hset_free(t_hset **p_hset)
{
	int i;

	i = -1;
	while (++i < (*p_hset)->max)
		ft_lst_free(&((*p_hset)->arr[i]), (*p_hset)->hfree);
	FT_MEMDEL((*p_hset)->arr);
	FT_MEMDEL(*p_hset);
	return (0);
}

t_list		*ft_hset_tolst(t_hset *hset)
{
	int		i;
	t_list	*res;

	if (!hset)
		return (NULL);
	i = -1;
	res = NULL;
	while (++i < hset->max)
	{
		if (!(hset->arr[i]))
			continue;
		res = ft_lstappend_dup(res, hset->arr[i]);
	}
	return (res);
}
