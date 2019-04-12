/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_edit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 17:01:17 by abbesbes          #+#    #+#             */
/*   Updated: 2019/03/23 16:27:29 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_rl.h"
#include "ftsh.h"

extern t_rl		g_rl;

void			rl_putstr_wrap(char *line, ssize_t cc)
{
	while (line[cc])
	{
		ft_putchar(line[cc]);
		if (!((cc + g_rl.prompt_len) % g_rl.wc))
		{
			ft_putchar('\n');
			//tputs(tgetstr("cr", NULL), 1, rl_ter_putchar);
			//tputs(tgetstr("do", NULL), 1, rl_ter_putchar);
		}
		cc++;
	}
}

int				rl_insert_ch(int c)
{
	char	*line;
	ssize_t	i;

	line = g_rl.txt->a[g_rl.cl]->str;
	if (c != '\n')
		ft_dstrins_ch(g_rl.txt->a[g_rl.cl], g_rl.cc++, c);
	else
	{
		ft_dstrins_ch(g_rl.txt->a[g_rl.cl], -1, c);
		rl_cur_toend();
	}
	if (!line[g_rl.cc] || c == '\n')
	{
		ft_putchar(c);
		if (!((g_rl.cc + g_rl.prompt_len) % g_rl.wc))
			{
				//tputs(tgetstr("cr", NULL), 1, rl_ter_putchar);
				//tputs(tgetstr("do", NULL), 1, rl_ter_putchar);
				ft_putchar('\n');
			}
	}
	else
	{
/*
		i = g_rl.cc;
		//while (line[++i])
		//	ft_putchar(' ');
		//while (--i > g_rl.cc)
			//tputs(tgetstr("le", NULL), 1, rl_ter_putchar);
		//	ft_putchar('\b');
		//ft_putstr(line + --i);
		tputs(tgetstr("sc", NULL), 1, rl_ter_putchar);
		rl_putstr_wrap(line, --i);
		tputs(tgetstr("rc", NULL), 1, rl_ter_putchar);
		//while (line[++i])
		//	ft_putchar('\b');
			//tputs(tgetstr("le", NULL), 1, rl_ter_putchar);
*/
		
		i = g_rl.cc;
		tputs(tgetstr("sc", NULL), 1, rl_ter_putchar);
		tputs(tgetstr("ce", NULL), 1, rl_ter_putchar);
		tputs(tgetstr("cr", NULL), 1, rl_ter_putchar);
		tputs(tgetstr("do", NULL), 1, rl_ter_putchar);
		tputs(tgetstr("cd", NULL), 1, rl_ter_putchar);
		tputs(tgetstr("rc", NULL), 1, rl_ter_putchar);
		tputs(tgetstr("sc", NULL), 1, rl_ter_putchar);
		ft_putstr(line + i - 1);
		tputs(tgetstr("rc", NULL), 1, rl_ter_putchar);
		//tputs(tgetstr("nd", NULL), 1, rl_ter_putchar);
		rl_ctrl_perform(KRIGHT);
		g_rl.cc = i;
	}
	//g_rl.txt->a[g_rl.cl]->str[g_rl.cc++] = c;
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
