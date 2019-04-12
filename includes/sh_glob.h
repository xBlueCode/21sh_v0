/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_glob.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 14:03:57 by abbesbes          #+#    #+#             */
/*   Updated: 2019/04/08 14:07:17 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_GLOB_H
# define SH_GLOB_H

int     sh_glob_match(char *str, char *pat);
int     sh_glob_match_range(int c, char *ran);

#endif
