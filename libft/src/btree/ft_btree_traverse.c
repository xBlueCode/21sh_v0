/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_traverse.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 19:03:14 by abbesbes          #+#    #+#             */
/*   Updated: 2019/10/21 19:03:15 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_btreetrav_infix(t_btree *root, void (*trav)(void*))
{
	if (!root || !trav)
		return (KO);
	ft_btreetrav_infix(root->left, trav);
	if (root->data)
		(*trav)(root->data);
	ft_btreetrav_infix(root->right, trav);
	return (OK);
}

int		ft_btreetrav_prefix(t_btree *root, void (*trav)(void*))
{
	if (!root || !trav)
		return (KO);
	if (root->data)
		(*trav)(root->data);
	ft_btreetrav_prefix(root->left, trav);
	ft_btreetrav_prefix(root->right, trav);
	return (OK);
}

int		ft_btreetrav_postfix(t_btree *root, void (*trav)(void*))
{
	if (!root || !trav)
		return (KO);
	ft_btreetrav_postfix(root->left, trav);
	ft_btreetrav_postfix(root->right, trav);
	if (root->data)
		(*trav)(root->data);
	return (OK);
}

int		ft_btreelev(t_btree *root)
{
	int	llev;
	int rlev;

	if (!root)
		return (0);
	llev = ft_btreelev(root->left);
	rlev = ft_btreelev(root->right);
	return (1 + (llev > rlev ? llev : rlev));
}
