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
	return (0);
}
