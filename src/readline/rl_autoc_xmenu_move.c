#include "ftsh.h"

extern t_rl		g_rl;

int				rl_autoc_xmenu_move_do(t_dstr **list, int *curl, int nl)
{
	int i;
	int llen;

	i = -1;
	if (!list)
		return (1);
	llen = ft_arr_len((void**)list);
	if ((!*curl || (*curl + 1) % (nl)) && *curl < llen - 1)
	{
		RL_TPUTS("cr");
		rl_putstr_nowrapx(list[*curl]->str, 0, 0);
		ft_putchar('\n');
		RL_PUTSTR_STY(T_REV, rl_putstr_nowrapx(list[++(*curl)]->str, 0, 0));
		//ft_putstr("DOWN");
	}
	else
	{
		rl_autoc_xmenu_clear(*curl % nl);
		*curl = (*curl + 1) % llen;
		rl_autoc_xmenu_putlist(list, *curl);
	}
	return (0);
}

int				rl_autoc_xmenu_move_up(t_dstr **list, int *curl, int nl)
{
	int i;
	int llen;

	i = -1;
	if (!list)
		return (1);
	llen = ft_arr_len((void**)list);
	if (*curl && ((*curl) % nl != 0))
	{
		RL_TPUTS("cr");
		rl_putstr_nowrapx(list[*curl]->str, 0, 0);
		RL_TPUTS("cr");
		RL_TPUTS("up");
		RL_PUTSTR_STY(T_REV, rl_putstr_nowrapx(list[--(*curl)]->str, 0, 0));
		//ft_putstr("DOWN");
	}
	else
	{
		rl_autoc_xmenu_clear(0);
		*curl = !*curl ? llen - 1 : (*curl - 1);
		rl_autoc_xmenu_putlist(list, *curl);
	}
	return (0);
}
