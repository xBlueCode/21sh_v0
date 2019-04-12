#include "libft.h"
#include "ft_rl.h"

extern t_rl		g_rl;

int				rl_tputsn(char *param, int n)
{
	while (n-- > 0)
		RL_TPUTS(param);
	return (0);
}

int				rl_cur_fromto(int from, int to)
{
	int nl;
	int nc;
	int wc;
	int plen;

	wc = g_rl.wc;
	plen = g_rl.plen;
	nl = (from + plen) / wc + (((from + plen) % wc) ? 1 : 0)
		- (to + plen) / wc - (((to + plen) % wc) ? 1 : 0);
	if (!((from + plen) % wc))
		nl++;
	if (!((to + plen) % wc))
		nl--;
	if (nl > 0)
		RL_TPUTS_GO("UP", nl, nl);
	else if (nl < 0)
		RL_TPUTS_GO("DO", -nl, -nl);
	nc = ((from + plen) % wc) - ((to + plen) % wc);
	if (nc >= 0)
		rl_tputsn("le", nc);
	else
		rl_tputsn("nd", -nc);
	return (0);
}
