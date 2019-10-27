/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_app.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 18:54:04 by abbesbes          #+#    #+#             */
/*   Updated: 2019/10/21 18:54:07 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		g_btreeapp_lev = 0;

int		ft_btreeapp_infix(t_btree *root, void (*app)(t_btree*))
{
	if (!root || !app)
		return (KO);
	g_btreeapp_lev++;
	ft_btreeapp_infix(root->left, app);
	g_btreeapp_lev--;
	(*app)(root);
	g_btreeapp_lev++;
	ft_btreeapp_infix(root->right, app);
	g_btreeapp_lev--;
	return (OK);
}

int		ft_btreeapp_prefix(t_btree *root, void (*app)(t_btree*))
{
	if (!root || !app)
		return (KO);
	(*app)(root);
	g_btreeapp_lev++;
	ft_btreeapp_prefix(root->left, app);
	ft_btreeapp_prefix(root->right, app);
	g_btreeapp_lev--;
	return (OK);
}

int		ft_btreeapp_postfix(t_btree *root, void (*app)(t_btree*))
{
	if (!root || !app)
		return (KO);
	g_btreeapp_lev++;
	ft_btreeapp_postfix(root->left, app);
	ft_btreeapp_postfix(root->right, app);
	g_btreeapp_lev--;
	(*app)(root);
	return (OK);
}
