/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_table.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 12:23:00 by abbesbes          #+#    #+#             */
/*   Updated: 2019/06/26 12:23:02 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TABLE_H
# define FT_TABLE_H

# include "libft.h"

typedef struct	s_table
{
	t_dastr		*name;
	t_dastr		*value;
	t_dstr		*opt;
	ssize_t		len;
}				t_table;

typedef struct	s_trow
{
	ssize_t		i;
	char		*name;
	char		*value;
	char		opt;
}				t_trow;

t_table			*ft_tabnew_max(ssize_t max);

t_trow			ft_tabrow_set(ssize_t pos, char *name, char *value, char opt);

int				ft_tabins(t_table *table, t_trow trow, int mode);
t_trow			ft_tabget_i(t_table *table, ssize_t i);
t_trow			ft_tabget_n(t_table *table, char *name);
t_trow			ft_tabget_v(t_table *table, char *val);
t_table			*ft_tabsel(t_table *table, int (*selector)(t_trow));

t_table			*ft_tabdup(t_table *table);
int				ft_tabfree(t_table **ptab);

int				ft_tabdel_i(t_table *table, ssize_t i);
int				ft_tabdel_n(t_table *table, char *name);
char			**ft_tabto_arr(t_table *table,
	int (*filter)(t_trow), char *(*builder)(t_trow));

int				ft_tabput(t_table *table, char *sep);

int				ft_tabiter(t_table *table, int (*func)(t_trow));

#endif
