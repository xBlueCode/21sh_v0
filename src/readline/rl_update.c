#include "ftsh.h"

extern t_rl		g_rl;

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
