/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_edit_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 01:48:52 by abbesbes          #+#    #+#             */
/*   Updated: 2019/10/09 01:48:54 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftsh.h"

extern t_rl		g_rl;

int				rl_get_header(void)
{
	int slen;

	slen = ft_strlenz(g_rl.txt->a[g_rl.cl]->str);
	return ((slen + g_rl.plen) / g_rl.wc
		+ ((slen + g_rl.plen) % g_rl.wc ? 1 : 0));
}
