/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_autoc_xmenu.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 01:44:43 by abbesbes          #+#    #+#             */
/*   Updated: 2019/10/09 01:44:45 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftsh.h"

extern t_rl		g_rl;

char			*rl_autoc_xmenu(t_dastr *res)
{
	t_dstr	*dline;
	char	*picked;
	int		slen;

	if (!res || !ft_arr_len((void**)res->a))
		return (NULL);
	if (g_rl.wl - rl_get_header() < 2)
		return (NULL);
	dline = g_rl.txt->a[g_rl.cl];
	rl_cur_fromto(g_rl.cc, ft_strlenz(dline->str));
	ft_putchar('\n');
	if (!(picked = rl_autoc_xmenu_select(res)))
		ft_dastrfree(&res);
	RL_TPUTS("up");
	dline = g_rl.txt->a[g_rl.cl];
	slen = ft_strlenz(dline->str);
	rl_cur_fromto(slen - slen % (g_rl.wc) - g_rl.plen, g_rl.cc);
	return (picked);
}

int				rl_autoc_xmenu_clear(int i)
{
	if (i < 0)
		return (0);
	RL_TPUTS("cr");
	if (i > 0)
		RL_TPUTS_GO("UP", i, i);
	RL_TPUTS("cd");
	return (0);
}

char			*rl_autoc_xmenu_select(t_dastr *res)
{
	int		curl;
	int		c;
	char	*picked;

	if (!res || !ft_arr_len((void**)res->a))
		return (NULL);
	picked = NULL;
	curl = 0;
	rl_autoc_xmenu_putlist(res->a, curl);
	while (!(c = '\0') && read(0, &c, sizeof(int)))
		if (c == KDOWN)
			rl_autoc_xmenu_move_do(res->a, &curl, g_rl.wl - rl_get_header());
		else if (c == KUP)
			rl_autoc_xmenu_move_up(res->a, &curl, g_rl.wl - rl_get_header());
		else if (c == '\n')
		{
			picked = (res->a[curl]->str);
			break ;
		}
		else if (c == KESC)
			break ;
	rl_autoc_xmenu_clear(curl % (g_rl.wl - rl_get_header()));
	return (picked);
}

int				rl_autoc_xmenu_putlist(t_dstr **list, int curl)
{
	int i;
	int nl;
	int page;

	i = -1;
	if (!list)
		return (1);
	nl = g_rl.wl - rl_get_header();
	page = (curl + 1) / nl + ((curl + 1) % nl ? 1 : 0) - 1;
	i = page * nl;
	while (i < ((page + 1) * nl) && list[i])
	{
		rl_putstr_nowrapx(list[i++]->str, 0, 0);
		if (i < ((page + 1) * nl) && list[i])
			ft_putchar('\n');
	}
	RL_TPUTS("cr");
	if (curl + 1 < i && curl % nl == 0)
		RL_TPUTS_GO("UP", (i - curl - 1) % nl, (i - curl - 1) % nl);
	ft_putstr(T_REV);
	rl_putstr_nowrapx(list[curl]->str, 0, 0);
	ft_putstr(T_END);
	return (0);
}
