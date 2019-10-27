/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hasht.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 12:30:23 by abbesbes          #+#    #+#             */
/*   Updated: 2019/06/26 12:30:24 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HTAB_H
# define FT_HTAB_H

# include "libft.h"

typedef struct	s_htabent
{
	void	*key;
	int		ksize;
	void	*val;
	int		vsize;
	int		op;
}				t_htabent;

typedef struct	s_htab
{
	t_hset		*hset;
}				t_htab;

t_htabent		*ft_htab_entnew(void *key, int ksize, void *value, int vsize);

int				ft_htab_put(t_hset *hset, t_htabent *ent);
int				ft_htab_rem(t_hset *hset, void *key, int ksize);
int				ft_htab_contains(t_hset *hset, void *key, int ksize);
t_htabent		*ft_htab_get(t_hset *hset, void *key, int ksize);
void			*ft_htab_getval(t_hset *hset, void *key, int ksize);

size_t			ft_htab_hcode_str(void *data);
int				ft_htab_equals_str(void *ent1, void *ent2);
void			ft_htab_free_ent_str(void **ent);

#endif
