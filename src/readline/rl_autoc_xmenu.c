#include "ftsh.h"

extern t_rl		g_rl;

char			*rl_autoc_xmenu(t_dastr *res)
{
	t_dstr	*dline;
	char	*picked;
//	int		nl;
	int		slen;

	//ft_printf("\nxmenu\n");
	if (!res || !ft_arr_len((void**)res->a))
		return (NULL);
	if (g_rl.wl - rl_get_header() < 2)
		return (NULL);
	dline = g_rl.txt->a[g_rl.cl];
	rl_cur_fromto(g_rl.cc, ft_strlenz(dline->str));
	ft_putchar('\n');
	picked = rl_autoc_xmenu_select(res);
	RL_TPUTS("up");
	slen = ft_strlenz(dline->str);
	rl_cur_fromto(slen- slen % (g_rl.wc) - g_rl.plen, g_rl.cc);
	return (picked);
}

int				rl_autoc_xmenu_clear(int i)
{
//	int		slen;

	if (i < 0)
		return (0);
	RL_TPUTS("cr");
	if (i > 0)
		RL_TPUTS_GO("UP", i, i);
	RL_TPUTS("cd");
	//RL_TPUTS_GO("UP", 1, 1);
	return (0);
}

char			*rl_autoc_xmenu_select(t_dastr *res)
{
	int		curl;
	int		c;
	char	*picked;

	//ft_printf("\nxmenu_select\n");
	if (!res || !ft_arr_len((void**)res->a))
		return (NULL);
	picked = NULL;
	curl = 0;
	rl_autoc_xmenu_putlist(res->a, curl);
	while (!(c = '\0') && read(0, &c, sizeof(int)))
		if (c == KDOWN)
				rl_autoc_xmenu_move_do(res->a, &curl, g_rl.wl - rl_get_header());
		else if (c == KUP)
		rl_autoc_xmenu_move_up(res->a, &curl, g_rl.wl - rl_get_header());
		else if (c == '\n')
		{
			picked = (res->a[curl]->str);
			break ;
		}
		else if (c == KESC)
			break ;
	rl_autoc_xmenu_clear(curl % (g_rl.wl - rl_get_header()));
	return (picked);
}

int				rl_autoc_xmenu_putlist(t_dstr **list, int curl)
{
	int i;
	int nl;
	//int llen;
	int page;

	//ft_printf("\nxmenu_putlist\n");
	i = -1;
	if (!list)
		return (1);
	//llen = ft_arr_len((void**)list);
	nl = g_rl.wl - rl_get_header();
	page = (curl + 1) / nl + ((curl + 1) % nl ? 1 : 0) - 1;
	i = page * nl;
	while (i < ((page + 1) * nl) && list[i])
	{
		rl_putstr_nowrapx(list[i++]->str, 0, 0);
		if (i < ((page + 1) * nl) && list[i])
			ft_putchar('\n');
	}
	RL_TPUTS("cr");
	if (curl + 1 < i && curl % nl == 0)
		RL_TPUTS_GO("UP", (i - curl - 1) % nl, (i - curl - 1) % nl);
	ft_putstr(T_REV);
	rl_putstr_nowrapx(list[curl]->str, 0, 0);
	ft_putstr(T_END);
	return (0);
}

