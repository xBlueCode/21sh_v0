/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dastr.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 10:56:48 by abbesbes          #+#    #+#             */
/*   Updated: 2019/03/15 15:03:46 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DASTR_H
# define FT_DASTR_H

typedef struct	s_dastr
{
	t_dstr	**a;
	ssize_t len;
	ssize_t	max;
}				t_dastr;

t_dastr			*ft_dastrnew_max(ssize_t max);
int				ft_dastrfree(t_dastr **dastr);
int				ft_dastrclear(t_dastr *dastr);
t_dastr			*ft_dastrdup(t_dastr *dastr);
int				ft_dastrcpy(t_dastr *dastr1, t_dastr *dastr2);

t_dstr			*ft_dastrget_last(t_dastr *dastr);
t_dstr			*ft_dastrget_i(t_dastr *dastr, ssize_t i);
t_dstr			*ft_dastrget_str(t_dastr *dastr, char *str);

int				ft_dastrext_x2(t_dastr *dstr);
int				ft_dastrext_n(t_dastr *dstr, ssize_t n);

int				ft_dastrins_str(t_dastr *dastr, ssize_t i, char *str);
int				ft_dastrins_str_free(t_dastr *dastr, ssize_t i, char **str);
int				ft_dastrins_dstr_free(t_dastr *dastr, ssize_t i, t_dstr *dstr);

int				ft_dastrrep_str(t_dastr *dastr, ssize_t i, char *str);

int				ft_dastrput_dstr(t_dastr *dastr, ssize_t i, t_dstr *dstr);

int				ft_dastrprint_all(t_dastr *dastr, char *sep);

int				ft_dastrdel_n(t_dastr *dastr, ssize_t i, ssize_t n);

#endif
