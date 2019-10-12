/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_xp_tilde.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 19:12:40 by abbesbes          #+#    #+#             */
/*   Updated: 2019/10/07 19:12:42 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftsh.h"

static int	sh_is_tilde_delim(char c)
{
	return (c == '\0' || c == '/' || c == ':');
}

static int	sh_xp_tilde_delim(t_dstr *word, int *k)
{
	while (!sh_is_tilde_delim(word->str[*k]))
	{
		if (word->str[*k] != '_' && !ft_isalnum(word->str[*k]))
			break ;
		k++;
	}
	if (word->str[*k] && !sh_is_tilde_delim(word->str[*k]))
		return (0);
	return (1);
}

static int	sh_xp_tilde_rep(t_dastr *words, int *i, int *j, char *rep)
{
	ft_dstrins_str(words->a[*i], *j, rep);
	*j += ft_strlenz(rep);
	return (1);
}

int			sh_xp_tilde(t_sh *sh, t_dastr *words, int *i, int *j)
{
	t_dstr	*word;
	char	*rep;
	int		k;

	word = words->a[*i];
	if (word->str[*j] != '~')
		return (0);
	k = *j + 1;
	if ((word->str[k] == '+' || word->str[k] == '-')
	&& sh_is_tilde_delim(word->str[k + 1]))
	{
		rep = sh_var_getval(sh->var, word->str[k] == '+' ? "PWD" : "OLDPWD");
		ft_dstrdel_n(words->a[*i], *j, 2);
		sh_xp_tilde_rep(words, i, j, rep);
		return (1);
	}
	if (!sh_xp_tilde_delim(word, &k))
		return (0);
	if (*j + 1 == k)
		rep = sh_var_getval(sh->var, "HOME");
	else
		rep = "USERPATH";
	ft_dstrdel_n(words->a[*i], *j, k - *j);
	sh_xp_tilde_rep(words, i, j, rep);
	return (1);
}
