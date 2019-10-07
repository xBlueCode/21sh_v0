/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_cur.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 19:31:01 by abbesbes          #+#    #+#             */
/*   Updated: 2019/10/07 19:31:03 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_rl.h"

extern t_rl		g_rl;

int				rl_tputsn(char *param, int n)
{
	while (n-- > 0)
		RL_TPUTS(param);
	return (0);
}

int				rl_cur_fromto(int from, int to)
{
	int nl;
	int nc;
	int wc;
	int plen;

	wc = g_rl.wc;
	plen = g_rl.plen;
	nl = (from + plen) / wc + (((from + plen) % wc) ? 1 : 0)
		- (to + plen) / wc - (((to + plen) % wc) ? 1 : 0);
	if (!((from + plen) % wc))
		nl++;
	if (!((to + plen) % wc))
		nl--;
	if (nl > 0)
		RL_TPUTS_GO("UP", nl, nl);
	else if (nl < 0)
		RL_TPUTS_GO("DO", -nl, -nl);
	nc = ((from + plen) % wc) - ((to + plen) % wc);
	if (nc >= 0)
		rl_tputsn("le", nc);
	else
		rl_tputsn("nd", -nc);
	return (0);
}

int				rl_cur_move(int from, int to, int plen)
{
	int nl;
	int nc;
	int wc;

	wc = g_rl.wc;
	nl = (from + plen) / wc + (((from + plen) % wc) ? 1 : 0)
		 - (to + plen) / wc - (((to + plen) % wc) ? 1 : 0);
	if (!((from + plen) % wc))
		nl++;
	if (!((to + plen) % wc))
		nl--;
	if (nl > 0)
		RL_TPUTS_GO("UP", nl, nl);
	else if (nl < 0)
		RL_TPUTS_GO("DO", -nl, -nl);
	nc = ((from + plen) % wc) - ((to + plen) % wc);
	if (nc >= 0)
		rl_tputsn("le", nc);
	else
		rl_tputsn("nd", -nc);
	return (0);
}
