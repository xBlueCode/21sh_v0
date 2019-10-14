#include "ftsh.h"

extern t_rl	g_rl;

int			rl_ctrl_sig_d(int c)
{
	t_dstr	*dline;

	if (c != KCD)
		return (1);
	dline = g_rl.txt->a[g_rl.cl];
	if (!*dline->str)
	{
		ft_printf("exit\n");
		exit(0);
	}
	rl_cur_fromto(g_rl.cc, 0);
	rl_putnchar_wrap(' ', ft_strlenz(dline->str), 0);
	rl_cur_fromto(ft_strlenz(dline->str), 0);
	g_rl.cc = 0;
	ft_dstrdel_n(dline, 0, dline->len);
	return (0);
}
