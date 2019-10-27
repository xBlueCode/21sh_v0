/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_manip.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 18:52:25 by abbesbes          #+#    #+#             */
/*   Updated: 2019/10/21 18:52:27 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_btreeins(t_btree **root, void *data, size_t dsize, t_cmp dcmp)
{
	if (!root || !data || !dcmp)
		return (KO);
	if (!*root)
		*root = ft_btreenew(data, dsize);
	else if (dcmp(data, (*root)->data) < 0)
	{
		if ((*root)->left)
			ft_btreeins(&((*root)->left), data, dsize, dcmp);
		else
			(*root)->left = ft_btreenew(data, dsize);
	}
	else
	{
		if ((*root)->right)
			ft_btreeins(&((*root)->right), data, dsize, dcmp);
		else
			(*root)->right = ft_btreenew(data, dsize);
	}
	return (OK);
}
