#include "ftsh.h"

extern t_rl		g_rl;

char			*rl_autoc_menu(t_dastr *res)
{
	t_dstr	*dline;
	int		i;

	if (!res)
		return (NULL);
	dline = g_rl.txt->a[g_rl.cl];
	rl_cur_fromto(g_rl.cc, ft_strlenz(dline->str));
	RL_TPUTS("cr");
	RL_TPUTS("do");
	i = -1;
	while (res->a[++i])
		ft_putendl(res->a[i]->str);
	return ("YES");
}