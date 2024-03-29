/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_xp_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 19:12:30 by abbesbes          #+#    #+#             */
/*   Updated: 2019/10/07 19:12:39 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftsh.h"

static int	sh_xp_word_split_inner(t_dastr *split, t_dstr *word,
		char *ifs, int *si)
{
	int		new;
	int		off;
	int		j;
	int		dql;

	new = 1;
	j = -1;
	off = 0;
	while (++j < word->len)
	{
		if (ft_strchr(ifs, word->str[j]) && ++off)
			new = 1;
		else
		{
			if (word->str[j] == '"'
				&& sh_lex_skip(word->str + j, &sh_lex_seek_dq, &dql))
				j += dql - 1;
			if (new)
				ft_dastrins_str(split, ++(*si), "");
			while (off <= j)
				ft_dstrins_ch(split->a[*si], -1, word->str[off++]);
			new = 0;
		}
	}
	return (1);
}

int			sh_xp_word_split(t_sh *sh, t_dastr *words)
{
	char	*ifs;
	t_dastr	*split;
	int		si;
	int		i;

	if (!(ifs = sh_var_getval(sh->var, "IFS")) || !*ifs)
		return (0);
	i = -1;
	si = -1;
	split = ft_dastrnew_max(2);
	while (++i < words->len)
		sh_xp_word_split_inner(split, words->a[i], ifs, &si);
	ft_dastrclear(words);
	ft_dastrcpy(words, split);
	FT_MEMDEL(split);
	return (1);
}
