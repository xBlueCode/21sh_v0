/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_basics.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 19:24:22 by abbesbes          #+#    #+#             */
/*   Updated: 2019/10/21 19:24:23 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_btree	*ft_btreenew(const void *data, size_t dsize)
{
	t_btree		*new_btree;

	if (!(new_btree = (t_btree*)ft_memalloc(sizeof(t_btree))))
		return (NULL);
	if (!data)
	{
		new_btree->data = NULL;
		new_btree->dsize = 0;
	}
	else
	{
		new_btree->data = ft_memalloc(sizeof(dsize));
		new_btree->dsize = dsize;
		ft_memcpy(new_btree->data, data, dsize);
	}
	new_btree->left = NULL;
	new_btree->right = NULL;
	new_btree->root = NULL;
	return (new_btree);
}

int		ft_btreeinit(t_btree **btree, const void *data, size_t dsize, int op)
{
	if (!btree)
		return (KO);
	*btree = ft_btreenew(data, dsize);
	if (!*btree)
		return (KO);
	(*btree)->op = op;
	return (OK);
}

int		ft_btreefree_one(t_btree **btree, t_free dfree)
{
	if (!btree || !*btree || !dfree)
		return (KO);
	dfree(&((*btree)->data));
	FT_MEMDEL(*btree);
	return (OK);
}

int		ft_btreefree(t_btree **btree, t_free dfree)
{
	if (!btree || !*btree || !dfree)
		return (KO);
	ft_btreefree(&(*btree)->left, dfree);
	ft_btreefree(&((*btree)->right), dfree);
	dfree(&((*btree)->data));
	ft_memdel((void**)btree);
	return (OK);
}
