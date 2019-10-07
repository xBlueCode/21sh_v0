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

int		sh_xp_word(t_sh *sh, t_dastr *words)
{
	int i;
	int j;
	int dql;
	int indq;

	DF0;
	i = -1;
	//indq = BIT_IS(sh->mode, SH_MODE_INDQ);
	//BIT_USET(sh->mode, SH_MODE_INDQ);
	indq = BIT_MIS(sh->nest, SH_NEST_M, SH_NEST_INDQ);
	BIT_MUSET(sh->nest, SH_NEST_M);
	while (++i < words->len)
	{
		j = 0;
		sh_xp_tilde(sh, words, &i, &j);
		while (j < words->a[i]->len)
		{
			if (sh_xp_brace(sh, words, &i, &j)
				|| sh_xp_param(sh, words, &i, &j)
				|| sh_xp_var(sh, words, &i, &j)
				//|| sh_xp_dq(sh, words, &i, &j) // TODO: perform it after splitting
				|| sh_xp_sq(sh, words, &i, &j)
				|| sh_xp_bq(sh, words, &i, &j)
				|| sh_xp_scmd(sh, words, &i, &j)
				|| sh_xp_esc(sh, words, &i, &j))
				continue ;
			else if (words->a[i]->str[j] == '"'
				&& sh_lex_skip(words->a[i]->str + j, &sh_lex_seek_dq, &dql))
				j += dql;
			else
				j++;
		}
	}
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
	//DF_PFWAIT(" >", 8);
	return (1);
}

int		sh_xp_assign(t_sh *sh, t_dastr *assigns)
{
	int i;
	int j;

	i = -1;
	while (++i < assigns->len)
	{
		j = 0;
		while (sh_lex_isinname(assigns->a[i]->str[j]))
			j++;
		if (assigns->a[i]->str[j] != '=')
			return (-1);
		j++;
		sh_xp_tilde(sh, assigns, &i, &j);
		while (j < assigns->a[i]->len)
		{
			if (
				sh_xp_param(sh, assigns, &i, &j)
				|| sh_xp_var(sh, assigns, &i, &j)
				|| sh_xp_dq(sh, assigns, &i, &j)
				|| sh_xp_sq(sh, assigns, &i, &j)
				|| sh_xp_bq(sh, assigns, &i, &j)
				|| sh_xp_scmd(sh, assigns, &i, &j)
				|| sh_xp_esc(sh, assigns, &i, &j)
				|| (assigns->a[i]->str[j] == ':' && ++j
				&& sh_xp_tilde(sh, assigns, &i, &j)))
				continue ;
			j++;
		}
	}
	return (1);
}
