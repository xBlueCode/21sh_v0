/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_htab_manip.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 18:54:23 by abbesbes          #+#    #+#             */
/*   Updated: 2019/10/21 18:54:24 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_htab_put(t_hset *hset, t_htabent *ent)
{
	t_htabent *new_ent;

	new_ent = ft_htab_entnew(ent->key, ent->ksize, ent->val, ent->vsize);
	if (!ft_hset_add(hset, new_ent, sizeof(t_htabent)))
	{
		FT_MEMDEL(new_ent);
		return (0);
	}
	hset->hfree((void**)&new_ent);
	return (-1);
}

int		ft_htab_rem(t_hset *hset, void *key, int ksize)
{
	t_htabent ent;

	ent = (t_htabent){.key = key, .ksize = ksize, .val = NULL, .vsize = 0};
	return (ft_hset_rem(hset, &ent));
}
