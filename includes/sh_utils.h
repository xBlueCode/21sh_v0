/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 16:45:13 by abbesbes          #+#    #+#             */
/*   Updated: 2019/03/29 14:14:32 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_UTILS_H
# define SH_UTILS_H

ssize_t		ft_strind_wordend(char *str, ssize_t cc);
ssize_t		ft_strind_wordend(char *str, ssize_t cc);
ssize_t		ft_strind_w_next_end(char *str, ssize_t cc);
ssize_t		ft_strind_w_next_beg(char *str, ssize_t cc);
ssize_t		ft_strind_w_prev_beg(char *str, ssize_t cc);
int			ft_strind_w_get_ilen(char *str, ssize_t cc, ssize_t *il);
int			ft_strind_w_next_get_ilen(char *str, ssize_t cc, ssize_t *il);

#endif
