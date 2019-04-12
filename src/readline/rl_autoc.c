/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_autoc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 16:12:26 by abbesbes          #+#    #+#             */
/*   Updated: 2019/04/09 11:30:12 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftsh.h"

extern t_rl		g_rl;

int				rl_autoc(int c)
{
	t_dstr	*dline;
	int		cxt;
	char	*cw;
	ssize_t	ilen[2];

	(void)c;
	dline = g_rl.txt->a[g_rl.cl];
	rl_autoc_get_cw(dline->str, g_rl.cc, ilen);
	cw = ft_strndup(dline->str + ilen[0], ilen[1]);
	cxt = rl_autoc_cxt_get(dline->str, ilen[0]);
	//rl_autoc_match(dline->str, ilen[0], ctx);
	ft_printf("\nCW: _%s_\t\tCXT: %d\n", cw, cxt);
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
	if (cxt == RL_CXT_BIN)
		return (rl_autoc_match_bin(w, cxt));
	else if (cxt == RL_CXT_VAR)
		return (rl_autoc_match_var(w, cxt));
	else
		return (rl_autoc_match_glob(w, cxt));
}
