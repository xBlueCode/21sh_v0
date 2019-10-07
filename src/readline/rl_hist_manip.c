/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_hist_manip.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 19:31:19 by abbesbes          #+#    #+#             */
/*   Updated: 2019/10/07 19:31:20 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftsh.h"

extern t_hist	g_his;

int				rl_hist_parse(char *str, int num)
{
	t_dastr		*ent;
	char 		*line;
	ssize_t		etx;

	//ft_printf("hist_parsing str: <%s>, num <%d>\n", str, num);
	if (!str || num < 1)
		return (-1);
	//ent = ft_dastrnew_max(num);
	ent = g_his.ent;
	while (--num > -1)
	{
		if ((etx = ft_strichr(str, 0x03)) < 0)
			break;
		line = ft_strndup(str, etx);
		str = str + etx + 1;
		ft_dastrins_str(ent, -1, line);
		ft_memdel((void**)&line);
	}
	g_his.cur = g_his.ent->len - 1;
	return (0);
}

t_dastr			*rl_hist_get_txt(int cur)
{
	t_dstr		*cmd;
	char 		*cmdstr;
	char		*nl;
	char 		*tmp;
	t_dastr		*txt;

	if (cur < 0 && (txt = g_his.back))
	{
		g_his.back = NULL;
		return (txt);
	}
	if (!(cmd = g_his.ent->a[cur]))
		return (NULL);
	cmdstr = cmd->str;
	txt = ft_dastrnew_max(1);
	while ((nl = ft_strchr(cmdstr, '\n')))
	{
		ft_dastrins_str(txt, -1, (tmp = ft_strndup(cmdstr, nl - cmdstr + 1)));
		cmdstr = nl + 1;
		ft_memdel((void**)&tmp);
	}
	if (txt)
		ft_dstrdel_n(txt->a[txt->len - 1], -1, 1);
	return (txt);
}

int 			rl_hist_add(char *line)
{
	if (!line)
		return (-1);
	while (ft_isspace(*line))
		line++;
	if (!*line || *line == '\n')
		return (-1);
	ft_dastrins_str(g_his.ent, g_his.ent->len, line);
	rl_hist_reset();
	return (0);
}

int				rl_hist_print(void)
{
	int i;

	ft_printf("FTSH History, Total: %d\n", g_his.ent->len);
	if (!g_his.ent || !g_his.ent->a)
		return (-1);
	i = -1;
	while (g_his.ent->a[++i])
		if (g_his.ent->a[i]->str)
		{
			ft_putnbr(i);
			ft_putchar('\t');
			ft_putstr(g_his.ent->a[i]->str);
		}
	return (0);
}
