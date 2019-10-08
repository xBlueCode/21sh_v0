/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_autoc_menu.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 19:29:58 by abbesbes          #+#    #+#             */
/*   Updated: 2019/10/07 19:29:59 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftsh.h"

extern t_rl		g_rl;

char			*rl_autoc_menu(t_dastr *res)
{
	t_dstr	*dline;
	char	*picked;

	if (!res || !ft_arr_len((void**)res->a))
		return (NULL);
	dline = g_rl.txt->a[g_rl.cl];
	rl_cur_fromto(g_rl.cc, ft_strlenz(dline->str));
	picked = rl_autoc_menu_select(res);
	return (picked);
}

int				rl_autoc_menu_clear(t_dstr **list, int i)
{
	t_dstr	*dline;
	int		slen;

	if (i < 0)
		return (0);
	dline = g_rl.txt->a[g_rl.cl];
	RL_TPUTS("cr");
	while (i > -1)
	{
		slen = ft_strlenz(list[i]->str);
		rl_cur_move(slen - slen % g_rl.wc, 0, 0);
		if (i)
			RL_TPUTS_GO("UP", 1, 1);
		i--;
	}
	RL_TPUTS("cd");
	RL_TPUTS_GO("UP", 1, 1);
	slen = ft_strlenz(dline->str);
	rl_cur_fromto(slen - slen % (g_rl.wc) - g_rl.plen, g_rl.cc);
	return (0);
}

char			*rl_autoc_menu_select(t_dastr *res)
{
	int		curl;
	int		c;
	char	*picked;

	if (!res || !ft_arr_len((void**)res->a))
		return (NULL);
	picked = NULL;
	curl = 0;
	rl_autoc_menu_putlist(res->a);
	while (!(c = '\0') && read(0, &c, sizeof(int)))
		if (c == KUP || c == KDOWN)
			rl_autoc_menu_move(res->a,
				&curl, 1 * (c == KDOWN) - 1 * (c == KUP));
		else if (c == '\n')
		{
			picked = (res->a[curl]->str);
			break ;
		}
		else if (c == KESC)
			break ;
	rl_autoc_menu_clear(res->a, curl);
	return (picked);
}

int				rl_autoc_menu_putlist(t_dstr **list)
{
	int i;
	int slen;

	i = -1;
	if (!list)
		return (1);
	while (list[++i])
	{
		ft_putchar('\n');
		rl_putstr_wrapx(list[i]->str, 0, 0);
	}
	RL_TPUTS("cr");
	while (--i > -1)
	{
		slen = ft_strlenz(list[i]->str);
		rl_cur_move(slen - slen % g_rl.wc, 0, 0);
		if (i)
			RL_TPUTS_GO("UP", 1, 1);
	}
	ft_putstr(T_REV);
	rl_putstr_wrapx(list[0]->str, 0, 0);
	ft_putstr(T_END);
	return (0);
}

int				rl_autoc_menu_move(t_dstr **list, int *curl, int action)
{
	ssize_t	slen;

	if ((action == 1 && *curl < ft_arr_len((void**)list) - 1)
		|| (action == -1 && *curl > 0))
	{
		rl_cur_move(ft_strlenz(list[*curl]->str), 0, 0);
		rl_putstr_wrapx(list[*curl]->str, 0, 0);
		if (action == 1)
		{
			ft_putstr("\n"T_REV);
			rl_putstr_wrapx(list[++(*curl)]->str, 0, 0);
			ft_putstr(T_END);
		}
		else if ((slen = ft_strlenz(list[*curl]->str)) || !slen)
		{
			rl_cur_move(slen, 0, 0);
			RL_TPUTS_GO("UP", 1, 1);
			slen = ft_strlenz(list[--(*curl)]->str);
			rl_cur_move(slen - slen % g_rl.wc, 0, 0);
			ft_putstr(T_REV);
			rl_putstr_wrapx(list[*curl]->str, 0, 0);
			ft_putstr(T_END);
		}
	}
	return (0);
}
