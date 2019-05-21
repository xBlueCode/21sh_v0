#include "ftsh.h"

t_rl		g_rl;

void		rl_init()
{
	g_rl.txt = ft_dastrnew_max(1);
	g_rl.reg = ft_dastrnew_max(1);
	g_rl.regi = -1;
	g_rl.cl = -1;
	g_rl.scope = ft_dstrnew_max(RL_SCP_SIZE);
	//g_rl.ctx = RL_CTX_BIN;
	ft_dstrins_ch(g_rl.scope, 0, RL_SCP_START);
	rl_update_win();
	ft_printf("win %dx%d\n", g_rl.wc, g_rl.wl);
}

void		rl_reset(t_dastr *txt)
{
	if (!txt)
		return;
	g_rl.txt = txt; //? ent; // : ft_dastrnew_max(1);
	g_rl.cl = -1;
	ft_dstrdel_n(g_rl.scope, 0, g_rl.scope->max);
	ft_dstrins_ch(g_rl.scope, 0, RL_SCP_START);
}

void		rl_read(void)
{
	t_dstr	*line;
	int		c;

	line = g_rl.txt->a[g_rl.cl];
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
			break;
		}
	}
}

char		*rl_start(void)
{
	rl_init();
	while (*g_rl.scope->str) //
	{
		g_rl.mode = RL_MODE_INS;
		g_rl.cl++;
		g_rl.cc = 0;
		if (g_rl.txt->max < g_rl.cl + 1)
			ft_dastrext_x2(g_rl.txt);
		rl_scope_prompt(g_rl.scope->str);
		if (ft_dstrget_ch(g_rl.scope, -1) == RL_SCP_JOIN)
			ft_dstrdel_n(g_rl.scope, -1, 1);
		rl_read();
		if (!g_rl.txt->a[g_rl.cl]->str)
			ft_putendl("NULL line");
		ft_putstr(g_rl.txt->a[g_rl.cl]->str);
	}
	return (ft_dstrjoin_all(g_rl.txt->a, "")->str); // check safety if return NULL
	//return ("no");
}

t_rl		rl_get(void)
{
	return (g_rl);
}