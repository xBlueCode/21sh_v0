#include "ftsh.h"

extern t_rl		g_rl;

int				rl_get_header(void)
{
	int slen;

	slen = ft_strlenz(g_rl.txt->a[g_rl.cl]->str);
	return ((slen + g_rl.plen) / g_rl.wc + ((slen + g_rl.plen) % g_rl.wc ? 1 : 0));
}
