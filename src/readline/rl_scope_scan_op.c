#include "ftsh.h"

extern t_rl	g_rl;

int			rl_scope_scan_pipe(char *line, ssize_t *pos)
{
	ssize_t		i;

	i = *pos;
	if (ft_dstrget_ch(g_rl.scope, -1) == RL_SCP_PIPE)
	{
		while (ft_isspace(line[i]))
			i++;
		if (line[i])
			ft_dstrdel_n(g_rl.scope, -1, 1 + 0 * i--);
		*pos = i;
		return (1);
	}
	else if (line[i++] == '|' && line[i] != '|')
	{
		while (line[i] != '\n' && ft_isspace(line[i]))
			i++;
		if (line[i] == '\n')
			ft_dstrins_ch(g_rl.scope, -1, RL_SCP_PIPE);
		else
			return (0);
		*pos = i + 1;
		return (1);
	}
	return (0);
}

int			rl_scope_scan_and(char *line, ssize_t *pos)
{
	ssize_t		i;

	i = *pos;
	if (ft_dstrget_ch(g_rl.scope, -1) == RL_SCP_AND)
	{
		while (ft_isspace(line[i]))
			i++;
		if (line[i])
			ft_dstrdel_n(g_rl.scope, -1, 1 + 0 * i--);
		*pos = i;
		return (1);
	}
	if (line[i++] == '&' && line[i++] == '&')
	{
		while (line[i] != '\n' && ft_isspace(line[i]))
			i++;
		if (line[i] == '\n')
			ft_dstrins_ch(g_rl.scope, -1, RL_SCP_AND);
		else
			return (0);
		*pos = i + 1;
		return (1);
	}
	return (0);
}

int			rl_scope_scan_or(char *line, ssize_t *pos)
{
	ssize_t		i;

	i = *pos;
	if (ft_dstrget_ch(g_rl.scope, -1) == RL_SCP_OR)
	{
		while (ft_isspace(line[i]))
			i++;
		if (line[i])
			ft_dstrdel_n(g_rl.scope, -1, 1 + 0 * i--);
		*pos = i;
		return (1);
	}
	if (line[i++] == '|' && line[i++] == '|')
	{
		while (line[i] != '\n' && ft_isspace(line[i]))
			i++;
		if (line[i] == '\n')
			ft_dstrins_ch(g_rl.scope, -1, RL_SCP_OR);
		else
			return (0);
		*pos = i + 1;
		return (1);
	}
	return (0);
}
