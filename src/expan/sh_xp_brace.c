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

int		sh_xp_brace(t_sh *sh, t_dastr *words, int *i, int *j)
{
	t_dastr	*res;
	char	*word;
	t_dstr	*dinp;
	t_lex	*lex;
	int		off;
	int		k;
	char	*pref;
	char	*suff;

	(void)sh;
	word = words->a[*i]->str;
	if (word[*j] != '{')
		return (0);
	off = *j + 1;
	*j += 1;
	pref = ft_strndup(words->a[*i]->str, *j - 1);
	sh_lex_init(&lex, word + off);
	off = 0;
	dinp = lex->in;
	res = ft_dastrnew_max(2);
	while (dinp->str[lex->i] && lex->st != TSBLANK && dinp->str[lex->i] != '}')
	{
		*j += lex->i;
		if (sh_lex_seek_blank(lex, 0) || sh_lex_seek_brace(lex, 0)
			|| sh_lex_seek_escape(lex, 0) || sh_lex_seek_sq(lex, 0)
			|| sh_lex_seek_dq(lex, 0) || sh_lex_seek_bq(lex, 0)
			|| sh_lex_seek_param(lex, 0) || sh_lex_seek_smath(lex, 0)
			|| sh_lex_seek_scmd(lex, 0))
			continue;
		if (dinp->str[lex->i] == ',')
		{
			dinp->str[lex->i++] = '\0';
			ft_dastrins_str(res, -1, dinp->str + off);
			off = lex->i;
		}
		else
			lex->i++;
	}
	if (lex->st == TSBLANK || dinp->str[lex->i] != '}')
		return (0);
	dinp->str[lex->i++] = '\0';
	ft_dastrins_str(res, -1, dinp->str + off);
	*j = lex->i;
	suff = ft_strdup(lex->in->str + *j);
	sh_lex_free(&lex);
	if (res->len)
		ft_dastrdel_n(words, *i, 1);
	k = -1;
	while (++k < res->len)
	{
		ft_dstrins_str(res->a[k], 0, pref);
		ft_dstrins_str(res->a[k], -1, suff);
		ft_dastrins_str(words, *i + k, res->a[k]->str);
	}
	if (res->len)
		*i -= 1;
	FT_MEMDEL(pref);
	FT_MEMDEL(suff);
	ft_dastrfree(&res);
	return (1);
}
