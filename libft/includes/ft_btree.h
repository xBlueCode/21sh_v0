/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 19:12:34 by abbesbes          #+#    #+#             */
/*   Updated: 2019/10/21 19:12:36 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BTREE_H
# define FT_BTREE_H

# include <unistd.h>

typedef	struct	s_btree
{
	void			*data;
	size_t			dsize;
	int				op;
	struct s_btree	*root;
	struct s_btree	*left;
	struct s_btree	*right;
}				t_btree;

t_btree			*ft_btreenew(const void *data, size_t dsize);
int				ft_btreeinit(t_btree **btree,
		const void *data, size_t dsize, int op);
int				ft_btreefree_one(t_btree **btree, t_free dfree);
int				ft_btreefree(t_btree **btree, t_free dfree);

int				ft_btreeins(t_btree **root,
	void *data, size_t dsize, t_cmp dcmp);

int				ft_btreetrav_infix(t_btree *root, void (*trav)(void*));
int				ft_btreetrav_prefix(t_btree *root, void (*trav)(void*));
int				ft_btreetrav_postfix(t_btree *root, void (*trav)(void*));

int				ft_btreeapp_infix(t_btree *root, void (*app)(t_btree*));
int				ft_btreeapp_prefix(t_btree *root, void (*app)(t_btree*));
int				ft_btreeapp_postfix(t_btree *root, void (*app)(t_btree*));

int				ft_btreelev(t_btree *root);

#endif
