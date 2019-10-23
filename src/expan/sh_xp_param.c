/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_xp_param.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 19:12:09 by abbesbes          #+#    #+#             */
/*   Updated: 2019/10/07 19:12:11 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftsh.h"

int		sh_xp_var(t_sh *sh, t_dastr *words, int *i, int *j)
{
	t_dstr	*word;
	char	*key;
	char	*val;
	int		off;

	word = words->a[*i];
	if (word->str[*j] != '$' || ft_strchr("{(", word->str[*j + 1]))
		return (0);
	off = ++(*j);
	if (!sh_lex_isinname(word->str[*j]))
		return (1);
	while (sh_lex_isinname(word->str[*j]))
		(*j)++;
	key = ft_strndup(word->str + off, *j - off);
	ft_dstrdel_n(word, off - 1, *j - off + 1);
	val = sh_var_getval(sh->var, key);
	(*j) = off - 1 + ft_strlenz(val);
	ft_dstrins_str(word, off - 1, val);
	FT_MEMDEL(key);
	return (1);
}

int		sh_xp_param(t_sh *sh, t_dastr *words, int *i, int *j)
{
	char	*word;
	char	*param;
	char	*val;
	int		off;

	word = words->a[*i]->str;
	if (ft_strncmp("${", word + *j, 2))
		return (0);
	ft_dstrdel_n(words->a[*i], (off = *j), 2);
	while (word[*j] && word[*j] != '}')
	{
		if (!sh_lex_isinname(word[*j]))
			break ;
		(*j)++;
	}
	if (word[*j] != '}')
		return (-1);
	param = ft_strndup(word + off, *j - off);
	ft_dstrdel_n(words->a[*i], off, *j - off + 1);
	val = sh_var_getval(sh->var, param);
	ft_dstrins_str(words->a[*i], off, val);
	if (val)
		*j = off + ft_strlenz(val);
	FT_MEMDEL(param);
	return (1);
}
