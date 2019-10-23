/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_hist_request.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 19:31:23 by abbesbes          #+#    #+#             */
/*   Updated: 2019/10/07 19:31:24 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "ftsh.h"

extern t_hist	g_his;
extern t_rl		g_rl;

int				rl_hist_req_up(int c)
{
	(void)c;
	if (g_his.cur < 0 || !g_his.ent->len)
	{
		ft_putchar(0x07);
		return (1);
	}
	if (g_his.cur > g_his.ent->len - 1)
		g_his.cur = g_his.ent->len - 1;
	return (rl_hist_req_cur(g_his.cur--));
}

int				rl_hist_req_do(int c)
{
	(void)c;
	if (g_his.cur >= g_his.ent->len - 1)
	{
		if (g_his.back)
			return (rl_hist_req_cur(-1));
		ft_putchar(0x07);
		return (1);
	}
	if (g_his.cur < 0)
		g_his.cur = 0;
	return (rl_hist_req_cur(g_his.cur++));
}

static void		rl_hist_req_cur_inner(t_dstr *rows)
{
	t_lex	*lex;

	sh_lex_init(&lex, rows->str);
	if (sh_lex_seek_start(lex, 1) == OK)
		ft_dstrins_str(g_rl.scope, 0, lex->scope->str);
	sh_lex_free(&lex);
}

int				rl_hist_req_cur(int cur)
{
	t_dstr	*rows;
	t_dastr	*ntxt;

	if (!g_his.back)
		g_his.back = rl_get().txt;
	ntxt = rl_hist_get_txt(cur);
	rl_update(ntxt);
	rl_cur_fromto(g_rl.cc, 0);
	RL_TPUTS("cr");
	RL_TPUTS("cd");
	ft_dstrdel_n(g_rl.scope, 0, g_rl.scope->len);
	ft_dstrins_ch(g_rl.scope, -1, RL_SCP_START);
	while (g_rl.txt->a[++g_rl.cl])
	{
		rl_scope_prompt(g_rl.scope->str);
		rl_putstr_wrap(g_rl.txt->a[g_rl.cl]->str, 0);
		ft_dstrdel_n(g_rl.scope, 0, g_rl.scope->len);
		rows = ft_dstrjoin_n(g_rl.txt->a, g_rl.cl + 1, NULL);
		if (!rows || !rows->str)
			continue;
		rl_hist_req_cur_inner(rows);
		ft_dstrfree(&rows);
	}
	ft_dastrfree(&ntxt);
	g_rl.cc = g_rl.txt->a[--g_rl.cl]->len;
	return (0);
}
