#include <fcntl.h>
#include "ftsh.h"

t_hist		g_his;

int 		rl_hist_init(char *filename)
{
	DF0
	if (filename)
		g_his.filename = ft_strdup(filename);
	else
		g_his.filename = ft_strdup(RL_HIS_FILENAME);
	g_his.ent = ft_dastrnew_max(1024);
	g_his.back = NULL;
	g_his.cur = 0;
	g_his.off = 0;
	return (OK);
}

t_hist 		rl_hist_get(void)
{
	return (g_his);
}

int 		rl_hist_reset(void)
{
	g_his.back = NULL;
	g_his.cur = g_his.ent->len;
	return (0);
}

int 			rl_hist_free(void)
{
	FT_MEMDEL(g_his.filename);
	ft_dastrfree(&g_his.ent);
	ft_dastrfree(&g_his.back);
	return (0);
}
