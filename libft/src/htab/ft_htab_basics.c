/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_htab_basics.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 19:04:00 by abbesbes          #+#    #+#             */
/*   Updated: 2019/10/21 19:04:01 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_htabent	*ft_htab_entnew(void *key, int ksize, void *value, int vsize)
{
	t_htabent *ent;

	if (!key || !ksize)
		return (NULL);
	ent = (t_htabent*)ft_memalloc(sizeof(t_htabent));
	ent->key = ft_memalloc(ksize);
	ent->ksize = ksize;
	if (value && (ent->vsize = vsize))
		ent->val = ft_memalloc(vsize);
	else
		ent->val = NULL;
	ft_memcpy(ent->key, key, ksize);
	ft_memcpy(ent->val, value, vsize);
	return (ent);
}

int			ft_htab_contains(t_hset *hset, void *key, int ksize)
{
	t_htabent ent;

	ent = (t_htabent){.key = key, .ksize = ksize, .val = NULL, .vsize = 0};
	return (ft_hset_contains(hset, &ent));
}

t_htabent	*ft_htab_get(t_hset *hset, void *key, int ksize)
{
	t_htabent	ent;
	t_list		*lst;
	int			ind;

	ent = (t_htabent){.key = key, .ksize = ksize, .val = NULL, .vsize = 0};
	ind = hset->hcode(&ent) % hset->max;
	if (!hset->arr[ind])
		return (0);
	lst = hset->arr[ind];
	while (lst)
	{
		if (hset->hequals(&ent, lst->content))
			return ((t_htabent*)lst->content);
		lst = lst->next;
	}
	return (NULL);
}

void		*ft_htab_getval(t_hset *hset, void *key, int ksize)
{
	t_htabent	ent;
	t_list		*lst;
	int			ind;

	if (!hset || !key)
		return (NULL);
	ent = (t_htabent){.key = key, .ksize = ksize, .val = NULL, .vsize = 0};
	ind = hset->hcode(&ent) % hset->max;
	if (!hset->arr[ind])
		return (0);
	lst = hset->arr[ind];
	while (lst)
	{
		if (hset->hequals(&ent, lst->content))
			return (((t_htabent*)lst->content)->val);
		lst = lst->next;
	}
	return (NULL);
}
