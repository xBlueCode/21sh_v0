/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_autoc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 19:29:54 by abbesbes          #+#    #+#             */
/*   Updated: 2019/10/07 19:29:56 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftsh.h"

extern t_rl		g_rl;

static void		rl_autoc_replace(char *picked, ssize_t *ilen)
{
	t_dstr	*dline;

	dline = g_rl.txt->a[g_rl.cl];
	rl_cur_fromto(g_rl.cc, ilen[0]);
	g_rl.cc = ilen[0];
	ft_dstrdel_n(dline, g_rl.cc, ilen[1]);
	ft_dstrins_str(dline, g_rl.cc, picked);
	rl_putstr_wrap(dline->str, g_rl.cc);
	g_rl.cc += ft_strlenz(picked);
	rl_cur_fromto(ft_strlenz(dline->str), g_rl.cc);
}

int				rl_autoc(int c)
{
	int		cxt;
	char	*cw;
	ssize_t	ilen[2];
	char	*picked;
	t_dastr	*res;

	(void)c;
	rl_autoc_get_cw(g_rl.txt->a[g_rl.cl]->str, g_rl.cc, ilen);
	cw = ft_strndup(g_rl.txt->a[g_rl.cl]->str + ilen[0], ilen[1]);
	cxt = rl_autoc_cxt_get(g_rl.txt->a[g_rl.cl]->str, ilen[0]);
	if (!(res = rl_autoc_match(cw, cxt)) || !res->len)
	{
		FT_MEMDEL(cw);
		FT_INST_RET(1, ft_dastrfree(&res));
	}
	if ((picked = rl_autoc_xmenu(res)))
	{
		rl_autoc_replace(picked, ilen);
		ft_dastrfree(&res);
	}
	FT_MEMDEL(cw);
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

t_dastr			*rl_autoc_match(char *w, int cxt)
{
	if (cxt == RL_CXT_VAR)
		return (rl_autoc_match_var(w));
	else if (cxt == RL_CXT_BIN)
		return (rl_autoc_match_bin(w));
	else
		return (rl_autoc_match_glob(w));
}
