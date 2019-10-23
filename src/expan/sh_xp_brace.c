/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_xp_brace.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 19:12:02 by abbesbes          #+#    #+#             */
/*   Updated: 2019/10/07 19:12:05 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftsh.h"

char		*g_pref;
char		*g_suff;

static int	sh_xp_brace_lex(t_lex *lex, t_dastr *res, t_dstr *dinp, int *off)
{
	if (sh_lex_seek_blank(lex, 0) || sh_lex_seek_brace(lex, 0)
		|| sh_lex_seek_escape(lex, 0) || sh_lex_seek_sq(lex, 0)
		|| sh_lex_seek_dq(lex, 0) || sh_lex_seek_bq(lex, 0)
		|| sh_lex_seek_param(lex, 0) || sh_lex_seek_smath(lex, 0)
		|| sh_lex_seek_scmd(lex, 0))
		return (1);
	if (dinp->str[lex->i] == ',')
	{
		dinp->str[lex->i++] = '\0';
		ft_dastrins_str(res, -1, dinp->str + *off);
		*off = lex->i;
		return (0);
	}
	else
		lex->i++;
	return (0);
}

static int	sh_xp_brace_inner(t_lex *lex, int *j, t_dastr *res)
{
	int		off;
	t_dstr	*dinp;

	off = 0;
	dinp = lex->in;
	res = ft_dastrnew_max(2);
	while (dinp->str[lex->i] && lex->st != TSBLANK && dinp->str[lex->i] != '}')
	{
		*j += lex->i;
		if (sh_xp_brace_lex(lex, res, dinp, &off))
			continue;
	}
	if (lex->st == TSBLANK || dinp->str[lex->i] != '}')
		return (0);
	dinp->str[lex->i++] = '\0';
	ft_dastrins_str(res, -1, dinp->str + off);
	*j = lex->i;
	return (1);
}

static int	sh_xp_brace_inner2(t_dastr *res, t_dastr *words, int *i)
{
	int k;

	if (res->len)
		ft_dastrdel_n(words, *i, 1);
	k = -1;
	while (++k < res->len)
	{
		ft_dstrins_str(res->a[k], 0, g_pref);
		ft_dstrins_str(res->a[k], -1, g_suff);
		ft_dastrins_str(words, *i + k, res->a[k]->str);
	}
	if (res->len)
		*i -= 1;
	return (0);
}

int			sh_xp_brace(t_sh *sh, t_dastr *words, int *i, int *j)
{
	t_dastr	*res;
	t_lex	*lex;

	(void)sh;
	if (words->a[*i]->str[*j] != '{')
		return (0);
	g_pref = ft_strndup(words->a[*i]->str, *j);
	sh_lex_init(&lex, words->a[*i]->str + ++(*j));
	res = ft_dastrnew_max(2);
	if (!sh_xp_brace_inner(lex, j, res))
		return (0);
	g_suff = ft_strdup(lex->in->str + *j);
	sh_xp_brace_inner2(res, words, i);
	sh_lex_free(&lex);
	FT_MEMDEL(g_suff);
	FT_MEMDEL(g_pref);
	ft_dastrfree(&res);
	return (1);
}
