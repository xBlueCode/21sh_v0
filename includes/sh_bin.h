/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_bin.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 19:33:54 by abbesbes          #+#    #+#             */
/*   Updated: 2019/10/07 19:33:56 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_BIN_H
# define SH_BIN_H

# include "libft.h"

# define SH_BIN_HTSIZE 2048

t_dastr	*sh_bin_names(void);

int		sh_bin_init(t_hset **phtbin, t_dastr **bin_names);
int		sh_bin_reset(t_hset **phtbin, t_dastr **bin_names);
int		sh_bin_update(t_hset *phtbin, t_dastr *bin_names, char *paths);

char	*sh_bin_getpath(t_hset *htbin, char *bin);

int		sh_bin_add_abs(t_hset *htbin, t_dastr *bin_names, char *binpath);

int		sh_bin_filter(const struct dirent *dirent);

#endif
