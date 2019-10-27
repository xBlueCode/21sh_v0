/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hash.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 12:31:20 by abbesbes          #+#    #+#             */
/*   Updated: 2019/06/26 12:31:23 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HASH_H
# define FT_HASH_H

# include <unistd.h>

typedef size_t	(*t_hcode)(void*);
typedef int	(*t_equals)(void*, void*);

size_t		ft_hcode_str(void *data);
size_t		ft_hcode_stric(void *data);
int			ft_hequals_str(void *h1, void *h2);

#endif
