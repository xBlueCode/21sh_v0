/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 19:31:53 by abbesbes          #+#    #+#             */
/*   Updated: 2019/02/27 19:40:32 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BIT_H
# define FT_BIT_H

# define BIT_IS(s, o) ((s & o) == o)
# define BIT_MIS(s, m, o) ((s & m) == o)
# define BIT_SET(s, o) (s = s | o)
# define BIT_USET(s, o) (s = s & ~o)
# define BIT_MSET(s, m, o) (s = (s & ~m) | o)
# define BIT_MUSET(s, m) (s = (s & ~m))

#endif
