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
	g_rl.hd = ft_dastrnew_max(1);
	rl_update_win();
	//ft_printf("win %dx%d\n", g_rl.wc, g_rl.wl);
}

void		rl_free(void)
{
	ft_dastrfree(&g_rl.txt);
	ft_dastrfree(&g_rl.reg);
	ft_dstrfree(&g_rl.scope);
	ft_dastrfree(&g_rl.hd);
}

void		rl_reset(t_dastr *txt)
{
	if (!txt)
		return;
	ft_dastrfree(&g_rl.txt);
	g_rl.txt = txt; //? ent; // : ft_dastrnew_max(1);
	g_rl.cl = -1;
	ft_dstrdel_n(g_rl.scope, 0, g_rl.scope->max);
	ft_dstrins_ch(g_rl.scope, 0, RL_SCP_START);
}

t_rl		rl_get(void)
{
	return (g_rl);
}
