#include "ftsh.h"

extern t_rl g_rl;

int			rl_scope_scan(void)
{
	char	*line;
	ssize_t	i;

	line = g_rl.txt->a[g_rl.cl]->str;
	i = -1;
	while(line[++i])
	{
		//ft_printf("scope_scanner: %d\n", ft_dstrget_ch(g_rl.scope, -1));
		g_rl_scope_scanner[ft_dstrget_ch(g_rl.scope, -1)](line, &i);
		if (i > -1 && !line[i])
			break;
		//rl_heredoc_scan(linem &i);
	}
	return (0);
}

int			rl_scope_scan_start(void)
{
	char	*line;
	ssize_t	i;
	int		iline;

	ft_dstrdel_n(g_rl.scope, 0, g_rl.scope->len);
	ft_dstrins_ch(g_rl.scope, 0, RL_SCP_NONE);
	iline = -1;
	while (++iline <= g_rl.cl)
	{
		line = g_rl.txt->a[iline]->str;
		i = -1;
		while(line[++i])
		{
			//ft_printf("scope_scanner: %d\n", ft_dstrget_ch(g_rl.scope, -1));
			g_rl_scope_scanner[ft_dstrget_ch(g_rl.scope, -1)](line, &i);
			if (i > -1 && !line[i])
				break;
			//rl_heredoc_scan(linem &i);
		}
	}
	return (0);
}


int			rl_scope_scan_none(char *line, ssize_t *pos)
{
	ssize_t	i;

	//ft_printf("\nnone -> %s\n", line + *pos);
	i = *pos;
	line = g_rl.txt->a[g_rl.cl]->str;
	while(line[i])
	{
		if (rl_scope_scan_escape(line, &i)
			|| rl_scope_scan_hd(line, &i)
			|| rl_scope_scan_join(line, &i)
			|| rl_scope_scan_pipe(line, &i)
			|| rl_scope_scan_and(line, &i)
			|| rl_scope_scan_or(line, &i)
			|| rl_scope_scan_sq(line, &i)
			|| rl_scope_scan_dq(line, &i)
			|| rl_scope_scan_bq(line, &i)
			|| rl_scope_scan_param(line, &i)
			|| rl_scope_scan_smath(line, &i)
			|| rl_scope_scan_scmd(line, &i)
			|| rl_scope_scan_ssh(line, &i)
			)
			continue;
		//rl_heredoc_scan(linem &i);
		i++;
	}
	*pos = i;
	return (0);
}

int			rl_scope_scan_escape(char *line, ssize_t *pos)
{
	ssize_t		i;

	i = *pos;
	//ft_printf("\nescape %d-> %s\n", (int)i, line + *pos);
	if (line[i] == '\\' && line[i + 1] != '\n')
	{
		*pos = i + 2;
		return (1);
	}
	return (0);
}

int			rl_scope_scan_join(char *line, ssize_t *pos)
{
	ssize_t		i;

	i = *pos;
	//ft_printf("\njoin %d-> %s\n", (int)i, line + *pos);
	if (line[i] == '\\' && line[i + 1] == '\n')
	{
		ft_dstrins_ch(g_rl.scope, -1, RL_SCP_JOIN);
		*pos = i + 2;
		return (1);
	}
	return (0);
}
