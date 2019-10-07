/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_xp_q.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 19:12:12 by abbesbes          #+#    #+#             */
/*   Updated: 2019/10/07 19:12:14 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftsh.h"

int		sh_xp_dq(t_sh *sh, t_dastr *words, int *i, int *j)
{
	t_dstr *word;

	word = words->a[*i];
	if (word->str[*j] != '"')
		return (0);
	//BIT_SET(sh->mode, SH_MODE_INDQ);
	sh->nest = SH_NEST_INDQ;
	ft_dstrdel_n(words->a[*i], *j, 1);
	while (word->str[*j] && word->str[*j] != '"')
	{
		if (
			sh_xp_param(sh, words, i, j) || sh_xp_var(sh, words, i, j)
			|| sh_xp_bq(sh, words, i, j) || sh_xp_scmd(sh, words, i, j)
			|| sh_xp_esc(sh, words, i, j)
			)
			continue;
		(*j)++;
	}
	//BIT_USET(sh->mode, SH_MODE_INDQ);
	sh->nest = 0;
	if (word->str[*j] != '"')
		return (-1);
	ft_dstrdel_n(words->a[*i], *j, 1);
	return (1);
}

int		sh_xp_sq(t_sh *sh, t_dastr *words, int *i, int *j)
{
	char *word;

	(void)sh;
	word = words->a[*i]->str;
	if (word[*j] != '\'')
		return (0);
	ft_dstrdel_n(words->a[*i], *j, 1);
	while (word[*j] && word[*j] != '\'')
		(*j)++;
	if (word[*j] != '\'')
		return (-1);
	ft_dstrdel_n(words->a[*i], *j, 1);
	return (1);
}

int		sh_xp_esc(t_sh *sh, t_dastr *words, int *i, int *j)
{
	char *word;

	(void)sh;
	word = words->a[*i]->str;
	if (word[*j] != '\\')
		return (0);
	ft_dstrdel_n(words->a[*i], *j, 1);
	(*j)++;
	return (1);
}
