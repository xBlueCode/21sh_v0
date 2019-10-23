/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 19:31:28 by abbesbes          #+#    #+#             */
/*   Updated: 2019/10/07 19:31:29 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftsh.h"

t_rl		g_rl;

void		rl_read(void)
{
	t_dstr	*dline;
	int		c;

	dline = g_rl.txt->a[g_rl.cl];
	g_rl.txt->a[g_rl.cl] = ft_dstrnew_max(100);
	if (*g_rl.scope->str == RL_SCP_START)
		*g_rl.scope->str = '\0';
	while (!(c = '\0') && read(0, &c, sizeof(int)))
	{
		if (!rl_ctrl_perform(c) && !rl_vim_perform(c) && ft_isascii(c))
			rl_insert_ch(c);
		if (c == '\n')
		{
			rl_scope_scan();
			break ;
		}
	}
}

void		xrl_read(void)
{
	int		c;
	t_dstr	*rows;
	t_lex	*lex;

	g_rl.txt->a[g_rl.cl] = ft_dstrnew_max(100);
	if (*g_rl.scope->str == RL_SCP_START)
		*g_rl.scope->str = '\0';
	while (!(c = '\0') && read(0, &c, sizeof(int)))
	{
		if (!rl_ctrl_perform(c) && !rl_vim_perform(c)
			&& (ft_isprint(c) || c == '\n'))
			rl_insert_ch(c);
		if (c == '\n')
		{
			rows = ft_dstrjoin_all(g_rl.txt->a, "");
			ft_dstrdel_n(g_rl.scope, 0, g_rl.scope->len);
			if (!rows || !rows->str)
				continue;
			sh_lex_init(&lex, rows->str);
			ft_dstrfree(&rows);
			if (sh_lex_seek_start(lex, 1) == OK)
				ft_dstrins_str(g_rl.scope, 0, lex->scope->str);
			sh_lex_free(&lex);
			break ;
		}
	}
}

char		*rl_start(void)
{
	t_dstr	*dline;
	char	*line;

	DF0;
	rl_init();
	while (*g_rl.scope->str)
	{
		g_rl.mode = RL_MODE_INS;
		g_rl.cl++;
		g_rl.cc = 0;
		if (g_rl.txt->max < g_rl.cl + 1)
			ft_dastrext_x2(g_rl.txt);
		rl_scope_prompt(g_rl.scope->str);
		if (ft_dstrget_ch(g_rl.scope, -1) == RL_SCP_JOIN)
			ft_dstrdel_n(g_rl.scope, -1, 1);
		xrl_read();
		if (!g_rl.txt->a[g_rl.cl]->str)
			ft_putendl("NULL line");
	}
	dline = ft_dstrjoin_all(g_rl.txt->a, "");
	line = !dline ? NULL : dline->str;
	FT_MEMDEL(dline);
	rl_free();
	return (line);
}
