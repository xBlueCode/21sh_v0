/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mem.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 18:00:05 by abbesbes          #+#    #+#             */
/*   Updated: 2018/12/03 18:02:17 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MEM_H
# define FT_MEM_H

# define FT_MEMDEL(P) {ft_memdel((void**)&(P)); P = NULL;}

typedef void	(*t_free)(void**);
typedef void	*(*t_dup)(void*);
typedef int		(*t_cmp)(void*, void*);

void			*ft_memset(void *b, int c, size_t len);
void			ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);

void			*ft_memalloc(size_t size);
void			ft_memdel(void **ap);

void			ft_swap(unsigned int *a, unsigned int *b);

#endif
