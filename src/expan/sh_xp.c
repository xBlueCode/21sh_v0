/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_xp.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 19:07:48 by abbesbes          #+#    #+#             */
/*   Updated: 2019/10/07 19:07:52 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftsh.h"

static int	sh_xp_word_split_dq(t_sh *sh, t_dastr *words)
{
	int i;
	int j;
	int indq;

	indq = BIT_MIS(sh->nest, SH_NEST_M, SH_NEST_INDQ);
	if (!indq)
		sh_xp_word_split(sh, words);
	i = -1;
	while (++i < words->len)
	{
		j = 0;
		while (j < words->a[i]->len)
			if (!sh_xp_dq(sh, words, &i, &j))
				j++;
	}
	return (1);
}

int			sh_xp_word(t_sh *sh, t_dastr *words)
{
	int i;
	int j;
	int dql;

	DF0;
	i = -1;
	BIT_MUSET(sh->nest, SH_NEST_M);
	while (++i < words->len && !(j = 0))
	{
		sh_xp_tilde(sh, words, &i, &j);
		while (j < words->a[i]->len)
		{
			if (sh_xp_param(sh, words, &i, &j)
				|| sh_xp_var(sh, words, &i, &j) || sh_xp_sq(sh, words, &i, &j)
				|| sh_xp_bq(sh, words, &i, &j) || sh_xp_scmd(sh, words, &i, &j)
				|| sh_xp_esc(sh, words, &i, &j))
				continue ;
			else if (words->a[i]->str[j] == '"'
				&& sh_lex_skip(words->a[i]->str + j, &sh_lex_seek_dq, &dql))
				j += dql;
			else
				j++;
		}
	}
	return (sh_xp_word_split_dq(sh, words));
}

int			sh_xp_assign(t_sh *sh, t_dastr *ass)
{
	int i;
	int j;

	i = -1;
	while (++i < ass->len && !(j = 0))
	{
		while (sh_lex_isinname(ass->a[i]->str[j]))
			j++;
		if (ass->a[i]->str[j] != '=')
			return (-1);
		j++;
		sh_xp_tilde(sh, ass, &i, &j);
		while (j < ass->a[i]->len)
		{
			if (
				sh_xp_param(sh, ass, &i, &j) || sh_xp_var(sh, ass, &i, &j)
				|| sh_xp_dq(sh, ass, &i, &j) || sh_xp_sq(sh, ass, &i, &j)
				|| sh_xp_bq(sh, ass, &i, &j) || sh_xp_scmd(sh, ass, &i, &j)
				|| sh_xp_esc(sh, ass, &i, &j) || (ass->a[i]->str[j] == ':'
				&& ++j && sh_xp_tilde(sh, ass, &i, &j)))
				continue ;
			j++;
		}
	}
	return (1);
}
