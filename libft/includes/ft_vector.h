/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 12:19:23 by abbesbes          #+#    #+#             */
/*   Updated: 2019/06/26 12:19:26 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VECTOR_H
# define FT_VECTOR_H

typedef struct	s_vec
{
	void	**a;
	size_t	max;
	size_t	len;
	t_free	tfree;
	t_dup	tdup;
}				t_vec;

int				ft_vecinit(t_vec *v, size_t max, t_free tfree, t_dup tdup);
t_vec			ft_vecnew(size_t max, t_free tfree);
int				ft_vecfree(t_vec *pv);

int				ft_vecextend(t_vec *v);
int				ft_vecadd(t_vec *v, void *item);
int				ft_vecins(t_vec *v, ssize_t i, void *item);
int				ft_vecset(t_vec *v, ssize_t i, void *item);

int				ft_vecdel(t_vec *v, ssize_t i);

t_vec			ft_vecdup(t_vec *v);
int				ft_veccpy(t_vec *w, t_vec *v);

#endif
