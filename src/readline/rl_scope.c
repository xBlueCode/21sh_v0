#include "ftsh.h"

extern t_rl g_rl;

int			rl_scope_prompt(char *str)
{
	int i;

	i = -1;
	g_rl.plen = 0;
	//(void)str;
	while (str[++i])
		g_rl.plen += ft_printf("%s ", g_rl_scope_prompt[(int)str[i]]);
	ft_putstr("> ");
	g_rl.plen += 2;
//	ft_printf("plen: %d\n", g_rl.plen);
	return (0);
}

int			rl_scope_update(void)
{
	char	*line;
	ssize_t	i;

	line = g_rl.txt->a[g_rl.cl]->str;
	i = -1;
	while (line[++i])
	{
		if (ft_dstrget_ch(g_rl.scope, -1) == RL_SCP_ESC)
			ft_dstrdel_n(g_rl.scope, -1, 1);
		else if (ft_dstrget_ch(g_rl.scope, -1) == RL_SCP_SQ && line[i] != '\'')
			continue;
		else if (ft_dstrget_ch(g_rl.scope, -1) == RL_SCP_BQ && line[i] != '`')
			continue;
		else if (line[i] == '"' && ft_dstrget_ch(g_rl.scope, -1) != RL_SCP_SMATH)
		{
			if (ft_dstrget_ch(g_rl.scope, -1) == RL_SCP_DQ)
				ft_dstrdel_n(g_rl.scope, -1, 1);
			else
				ft_dstrins_ch(g_rl.scope, -1, RL_SCP_DQ);
		}
		//else if (line[i] == '"')
		//	rl_scope_match_dq(line, pos);
		else if (line[i] == '\\')
			ft_dstrins_ch(g_rl.scope, -1, RL_SCP_ESC);
		else if (line[i] == '\'')
		{
			if (ft_dstrget_ch(g_rl.scope, -1) == RL_SCP_SQ)
				ft_dstrdel_n(g_rl.scope, -1, 1);
			else
				ft_dstrins_ch(g_rl.scope, -1, RL_SCP_SQ);
		}
		else if (line[i] == '`')
		{
			if (ft_dstrget_ch(g_rl.scope, -1) == RL_SCP_BQ)
				ft_dstrdel_n(g_rl.scope, -1, 1);
			else
				ft_dstrins_ch(g_rl.scope, -1, RL_SCP_BQ);
		}
		else if (line[i] == '$')
		{
			if (!ft_strncmp("$((", line + i, 3))
				ft_dstrins_ch(g_rl.scope, -1, RL_SCP_SMATH);
		}
	}
	return (0);
}
