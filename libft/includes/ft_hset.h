/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hset.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 12:28:52 by abbesbes          #+#    #+#             */
/*   Updated: 2019/06/26 12:28:54 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HSET_H
# define FT_HSET_H

# include "libft.h"

typedef struct	s_hset
{
	t_list		**arr;
	int			max;
	ssize_t		len;
	t_hcode		hcode;
	t_equals	hequals;
	t_free		hfree;
}				t_hset;

t_hset			*ft_hset_init(int max,
	t_hcode hcode, t_equals hequals, t_free hfree);
int				ft_hset_add(t_hset *hset, void *elem, int esize);
int				ft_hset_rem(t_hset *hset, void *elem);
int				ft_hset_contains(t_hset *hset, void *elem);
int				ft_hset_free(t_hset **p_hset);
t_list			*ft_hset_tolst(t_hset *hset);

#endif
