/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dirent.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 19:12:01 by abbesbes          #+#    #+#             */
/*   Updated: 2019/10/21 19:12:03 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DIRENT_H
# define FT_DIRENT_H

# include "libft.h"
# include <dirent.h>

# define FT_DIRENT_FSEP '/'

typedef int	(*t_dirent_filter)(const struct dirent *);

t_dastr		*ft_dirent_lookup(char *base, t_dirent_filter filter);
t_dastr		*ft_dirent_lookup_abs(char *base, t_dirent_filter filter);

#endif
