#include "ftsh.h"

extern t_rl g_rl;

int			rl_scope_scan_ssh(char *line, ssize_t *pos)
{
    ssize_t		i;
    int			start;

    i = *pos;
    start = (ft_dstrget_ch(g_rl.scope, -1) != RL_SCP_SUBSH);
    if (start && ft_strncmp("(", line + i, 1))
        return (0);
    if (!ft_strncmp("(", line + i, 1) && (i += 1))
        ft_dstrins_ch(g_rl.scope, -1, RL_SCP_SUBSH);
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
            || (!ft_strncmp("(", line + i, 1) && rl_scope_scan_ssh(line, &i)))
            continue;
        i++;
    }
    if (line[i] == ')' && ++i)
        ft_dstrdel_n(g_rl.scope, -1, 1);
    *pos = i;
    return (1);
}
