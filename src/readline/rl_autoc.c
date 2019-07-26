#include "ftsh.h"

extern t_rl		g_rl;

int				rl_autoc(int c)
{
	t_dstr	*dline;
	int		cxt;
	char	*cw;
	ssize_t	ilen[2];
	char	*picked;

	(void)c;
	dline = g_rl.txt->a[g_rl.cl];
	rl_autoc_get_cw(dline->str, g_rl.cc, ilen);
	cw = ft_strndup(dline->str + ilen[0], ilen[1]);
	cxt = rl_autoc_cxt_get(dline->str, ilen[0]);
	if ((picked = rl_autoc_xmenu(rl_autoc_match(cw, cxt))))
	{
		rl_cur_fromto(g_rl.cc, ilen[0]);
		g_rl.cc = ilen[0];
		ft_dstrdel_n(dline, g_rl.cc, ilen[1]);
		ft_dstrins_str(dline, g_rl.cc, picked);
		rl_putstr_wrap(dline->str, g_rl.cc);
		g_rl.cc += ft_strlenz(picked);
		rl_cur_fromto(ft_strlenz(dline->str), g_rl.cc);
	}
	//ft_printf("\nCW: _%s_\t\tCXT: %d\n", cw, cxt);
	return (1);
}

int				rl_autoc_cxt_get(const char *line, ssize_t pos)
{
	int		cxt;

	if (!pos || rl_autoc_cxt_isbin(line[pos - 1])
			|| (pos > 1 && !ft_strncmp(line + pos - 2, "$(", 2)))
		cxt = RL_CXT_BIN;
	else if (line[pos - 1] == '$'
			|| (pos > 1 && !ft_strncmp("${", line + pos - 2, 2)))
		cxt = RL_CXT_VAR;
	else if (ft_isspace(line[--pos]))
	{
		while (pos > -1 && ft_isspace(line[pos]))
			pos--;
		if (pos < 0 || rl_autoc_cxt_isbin(line[pos])
			|| (--pos && !ft_strncmp("$(", line + pos, 2)))
			cxt = RL_CXT_BIN;
		else
			cxt = RL_CXT_GLOB;
	}
	else
		cxt = RL_CXT_GLOB;
	return (cxt);
}

t_dastr		*rl_autoc_match(char *w, int cxt) // replace by array
{
	//(void)cxt;
	//ft_printf("autoc_match\n");
	if (cxt == RL_CXT_VAR)
		return (rl_autoc_match_var(w));
	else if (cxt == RL_CXT_BIN)
		return (rl_autoc_match_bin(w));
	else
		return (rl_autoc_match_glob(w));
}
