/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dstr.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 16:18:34 by abbesbes          #+#    #+#             */
/*   Updated: 2019/03/28 10:59:03 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DSTR_H
# define FT_DSTR_H

typedef struct	s_dstr
{
	char	*str;
	ssize_t len;
	ssize_t	max;
}				t_dstr;

t_dstr			*ft_dstrnew_str(char *str);
t_dstr			*ft_dstrset_str(char *str);
t_dstr			*ft_dstrnew_str_free(char **str);
t_dstr			*ft_dstrnew_max(ssize_t max);
int				ft_dstrfree(t_dstr **dstr);

int				ft_dstrext_x2(t_dstr *dstr);
int				ft_dstrext_n(t_dstr *dstr, ssize_t n);

int				ft_dstrins_ch(t_dstr *dstr, ssize_t i, int c);
int				ft_dstrins_str(t_dstr *dstr, ssize_t i, char *str);
int				ft_dstrins_str_free(t_dstr *dstr, ssize_t i, char **str);

int				ft_dstrrep_ch(t_dstr *dstr, ssize_t i, int c);

t_dstr			*ft_dstrjoin_all(t_dstr **arr, char *link);
t_dstr			*ft_dstrjoin_n(t_dstr **arr, int n, char *link);

int				ft_dstrget_ch(t_dstr *dstr, ssize_t i);

int				ft_dstrdel_n(t_dstr *dstr, ssize_t i, ssize_t n);

#endif
