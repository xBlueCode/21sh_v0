/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_edit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 17:01:17 by abbesbes          #+#    #+#             */
/*   Updated: 2019/03/25 17:53:13 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_rl.h"
#include "ftsh.h"

extern t_rl		g_rl;

int				rl_putstr_wrap(char *str, ssize_t cc, int plen, int wc)
{
	ssize_t i;

	i = cc - 1;
	while (str[++i])
	{
		ft_putchar(str[i]);
		if (!((i + plen + 1) % wc))
			ft_putchar('\n');
	}
	return (0);
}

int				rl_cur_backward(int from, int to, int plen, int wc)
{
	int nl;
	int nc;

	nl = (from + plen) / wc + (((from + plen) % wc) ? 1 : 0)
		- (to + plen) / wc - (((to + plen) % wc) ? 1 : 0);
	if (!((from + plen) % wc))
		nl++;
	if (!((to + plen) % wc))
		nl--;
	while (nl-- > 0)
		TPUTS("up");
	nc = ((from + plen) % wc) - ((to + plen) % wc);
	if (nc > 0)
	{
		while (nc-- > 0)
			TPUTS("le");
	}
	else if ((nc = -nc) > 0)
		while (nc-- > 0)
			TPUTS("nd");
	return (0);
}

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
		ft_putchar('\n');
		return (0);
	}
	ft_putchar(c);
	if (((g_rl.cc + g_rl.prompt_len + 1) % g_rl.wc == 1))
	{
		tputs(tgetstr("cr", NULL), 1, rl_ter_putchar);
		tputs(tgetstr("do", NULL), 1, rl_ter_putchar);
	}
	if (line[g_rl.cc])
	{
		//tputs(tgetstr("sc", NULL), 1, rl_ter_putchar);
		//ft_putstr(line + g_rl.cc);
		rl_putstr_wrap(line, g_rl.cc, g_rl.prompt_len, g_rl.wc);
		//tputs(tgetstr("rc", NULL), 1, rl_ter_putchar);
		rl_cur_backward(ft_strlenz(line), g_rl.cc, g_rl.prompt_len, g_rl.wc);
	}
	//fflush(NULL);
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
