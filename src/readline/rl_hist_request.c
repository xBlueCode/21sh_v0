// header

#include <fcntl.h>
#include "ftsh.h"

extern t_hist	g_his;
extern t_rl		g_rl;

int				rl_hist_req_up(int c)
{
	(void)c;
	if (g_his.cur < 0 || !g_his.ent->len)// || g_his.cur >= g_his.ent->len)
	{
		ft_putchar(0x07);
		return (1);
	}
	if (g_his.cur > g_his.ent->len - 1)
		g_his.cur = g_his.ent->len - 1;
	return (rl_hist_req_cur(g_his.cur--)); // check
}

int			rl_hist_req_do(int c)
{
	(void)c;
	if (g_his.cur >= g_his.ent->len)
	{
		if (g_his.back)
			return (rl_hist_req_cur(-1)); // check
		ft_putchar(0x07);
		return (1);
	}
	if (g_his.cur < 0)
		g_his.cur = 1;
	return (rl_hist_req_cur(g_his.cur++)); // check
}

int 		rl_hist_req_cur(int cur)
{
	if (!g_his.back)
		g_his.back = rl_get().txt;
	rl_reset(rl_hist_get_txt(cur)); // str to dastr
	rl_cur_fromto(g_rl.cc, 0);
	RL_TPUTS("cr");
	RL_TPUTS("cd");
	while (g_rl.txt->a[++g_rl.cl])
	{
		rl_scope_prompt(g_rl.scope->str);
		if (ft_dstrget_ch(g_rl.scope, -1) == RL_SCP_JOIN)
			ft_dstrdel_n(g_rl.scope, -1, 1);
		if (*g_rl.scope->str == RL_SCP_START)
			*g_rl.scope->str = '\0';
		rl_putstr_wrap(g_rl.txt->a[g_rl.cl]->str, 0);
		rl_scope_scan();
	}
	g_rl.cc = g_rl.txt->a[--g_rl.cl]->len;
	return (0); // check
}
