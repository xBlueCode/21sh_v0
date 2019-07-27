#include "ftsh.h"

extern t_rl g_rl;

int			rl_scope_scan_smath(char *line, ssize_t *pos)
{
	ssize_t		i;
	int			start;

	i = *pos;
	start = (ft_dstrget_ch(g_rl.scope, -1) != RL_SCP_SMATH);
	if (start && ft_strncmp("$((", line + i, 3))
		return (0);
	if (!ft_strncmp("$((", line + i, 3) && (i += 3))
		ft_dstrins_ch(g_rl.scope, -1, RL_SCP_SMATH);
	else if (start)
		return (0);
	while (line[i] && ft_strncmp(line + i, "))", 2))
	{
		if (rl_scope_scan_escape(line, &i)
			|| rl_scope_scan_join(line, &i)
			|| rl_scope_scan_bq(line, &i)
			|| rl_scope_scan_param(line, &i)
			|| (!ft_strncmp("$((", line + i, 3) && rl_scope_scan_smath(line, &i))
			|| rl_scope_scan_scmd(line, &i))
			continue;
		i++;
	}
	if (!ft_strncmp("))", line + i, 2) && (i += 2))
		ft_dstrdel_n(g_rl.scope, -1, 1);
	*pos = i;
	return (1);
}

int			rl_scope_scan_scmd(char *line, ssize_t *pos)
{
	ssize_t		i;
	int			start;

	i = *pos;
	if (!ft_strncmp("$((", line + i, 3))
		rl_scope_scan_smath(line, &i);
	start = (ft_dstrget_ch(g_rl.scope, -1) != RL_SCP_SCMD);
	if (start && ft_strncmp("$(", line + i, 2))
		return (0);
	if (!ft_strncmp("$(", line + i, 2) && (i += 2))
		ft_dstrins_ch(g_rl.scope, -1, RL_SCP_SCMD);
	else if (start)
		return (0);
	while (line[i] && ft_strncmp(line + i, ")", 1))
	{
		if (rl_scope_scan_escape(line, &i)
			|| rl_scope_scan_join(line, &i)
			|| rl_scope_scan_pipe(line, &i)
			|| rl_scope_scan_and(line, &i)
			|| rl_scope_scan_or(line, &i)
			|| rl_scope_scan_sq(line, &i)
			|| rl_scope_scan_dq(line, &i)
			|| rl_scope_scan_bq(line, &i)
			|| rl_scope_scan_param(line, &i)
			|| rl_scope_scan_smath(line, &i)
			|| (!ft_strncmp("$(", line + i, 2) && rl_scope_scan_scmd(line, &i)))
			continue;
		i++;
	}
	if (line[i] == ')' && ++i)
		ft_dstrdel_n(g_rl.scope, -1, 1);
	*pos = i;
	return (1);
}

int			rl_scope_scan_param(char *line, ssize_t *pos)
{
	ssize_t		i;
	int			start;

	i = *pos;
	start = (ft_dstrget_ch(g_rl.scope, -1) != RL_SCP_PARAM);
	if (start && ft_strncmp("${", line + i, 2))
		return (0);
	else if (start && (i += 2))
		ft_dstrins_ch(g_rl.scope, -1, RL_SCP_PARAM);
	while (line[i] && line[i] != '}')
	{
		if (rl_scope_scan_escape(line, &i)
			|| rl_scope_scan_join(line, &i)
			|| rl_scope_scan_bq(line, &i)
			|| (!ft_strncmp("${", line + i, 2) && rl_scope_scan_param(line, &i))
			|| rl_scope_scan_smath(line, &i)
			|| rl_scope_scan_scmd(line, &i))
			continue;
		i++;
	}
	if (line[i] == '}' && ++i)
		ft_dstrdel_n(g_rl.scope, -1, 1);
	*pos = i;
	return (1);
}
