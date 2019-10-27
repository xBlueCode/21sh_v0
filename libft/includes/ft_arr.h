/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arr.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 17:58:48 by abbesbes          #+#    #+#             */
/*   Updated: 2019/02/07 13:13:01 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ARR_H
# define FT_ARR_H

void			**ft_arr_new(size_t n, size_t m);
ssize_t			ft_arr_len(void **arr);
void			ft_arr_print(char **arr, int size);
void			ft_arr_foreachij(void **arr, int i, int j, void (*f)(void *));
void			ft_arr_free(void ***arr, size_t s);

void			ft_arr_iter(void **arr, void (*f)(void *));
char			**ft_arr_strdup(char **arr);
char			**ft_arr_strdup_extend(char **arr, ssize_t e);

#endif
