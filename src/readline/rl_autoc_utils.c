#include "ftsh.h"

extern t_rl		g_rl;

int				rl_autoc_isdelim(int c)
{
	if (ft_isspace(c) || c == ';' || c == '\n' || c == '&' || c == '|'
			|| c == '>' || c == '<' || c == '\'' || c == '"'
			|| c == '`' || c == '$' || c == '(' || c == ')')
		return (c);
	return (0);
}

int				rl_autoc_cxt_isbin(int c)
{
	return (c == ';' || c == '&' || c == '|' || c == '\n' || c == '`'
		|| c == '(');
}

int				rl_autoc_get_cw(char *line, ssize_t pos, ssize_t *ilen)
{
	ssize_t i;
	ssize_t j;
	int		d;

	i = pos;
	while (i > -1 && !(d = rl_autoc_isdelim(line[i])))
		i--;
	j = pos;
	while (line[++j] && !rl_autoc_isdelim(line[j]))
		;
	if (!ft_strncmp("$(", line + i, 2) || !ft_strncmp("${", line + i, 2))
		i++;
	ilen[0] = ++i;
	ilen[1] = j - i;
	return (0);
}
