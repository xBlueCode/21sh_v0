/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_edit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 17:01:17 by abbesbes          #+#    #+#             */
/*   Updated: 2019/03/23 18:17:10 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_rl.h"
#include "ftsh.h"

extern t_rl		g_rl;

int				rl_insert_ch(int c)
{
	char	*line;
	//ssize_t	i;

	line = g_rl.txt->a[g_rl.cl]->str;
	if (c != '\n')
		ft_dstrins_ch(g_rl.txt->a[g_rl.cl], g_rl.cc++, c);
	else
	{
		ft_dstrins_ch(g_rl.txt->a[g_rl.cl], -1, c);
		rl_cur_toend();
	}
	ft_putchar(c);
	if (((g_rl.cc + g_rl.prompt_len + 1) % g_rl.wc == 1))
	{
		tputs(tgetstr("cr", NULL), 1, rl_ter_putchar);
		tputs(tgetstr("do", NULL), 1, rl_ter_putchar);
	}
	if (line[g_rl.cc])
	{
		tputs(tgetstr("sc", NULL), 1, rl_ter_putchar);
		ft_putstr(line + g_rl.cc);
		tputs(tgetstr("rc", NULL), 1, rl_ter_putchar);
	}
	return (0);
}

int				rl_del_ch(void)
{

	char	*line;

	line = g_rl.txt->a[g_rl.cl]->str;
	if (!g_rl.cc)
		return (0);
	ft_dstrdel_n(g_rl.txt->a[g_rl.cl], g_rl.cc--, 1);
	return (0);
}

int				rl_cur_toend()
{
	int i;
	ssize_t s;

	s = ft_strlenz(g_rl.txt->a[g_rl.cl]->str) - 1;
	//g_rl.cc = s;
	tputs(tgetstr("cr", NULL), 1, rl_ter_putchar);
	i = (s + g_rl.prompt_len - g_rl.cc + 1) / g_rl.wc;
	while (i-- > 0)
		tputs(tgetstr("do", NULL), 1, rl_ter_putchar);
	i = (s + g_rl.prompt_len) % g_rl.wc;
	while (i-- > 0)
		tputs(tgetstr("nd", NULL), 1, rl_ter_putchar);
	ft_putchar('.');
	return (0);
}
