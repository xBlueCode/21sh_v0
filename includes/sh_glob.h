/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_glob.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 19:34:03 by abbesbes          #+#    #+#             */
/*   Updated: 2019/10/07 19:34:05 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_GLOB_H
# define SH_GLOB_H

int		rl_glob_indir(char *base, char *spath, char *pat, t_dastr *res);
int		rl_glob_indir_lin(char *base, char *spath, char *pat, t_dastr *res);

t_list	*sh_glob_scandir(char *base, char *spath);

int		sh_glob_match(char *str, char *pat);
int		sh_glob_match_range(int c, char *ran);

#endif
