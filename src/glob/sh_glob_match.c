/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_glob_match.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 22:12:57 by abbesbes          #+#    #+#             */
/*   Updated: 2019/10/08 22:12:58 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftsh.h"

int		sh_glob_match(char *str, char *pat)
{
	int		i;
	int		j;
	char	*ptr;

	i = 0;
	j = 0;
	if (!*str && !ft_strcmp("*", pat))
		return (1);
	while (str[i] && pat[j])
	{
		if (str[i] == pat[j] || pat[j] == '?')
			i += 1 + 0 * j++;
		else if (pat[j] == '*')
			return (sh_glob_match(str + i, pat + j + 1)
					|| sh_glob_match(str + i + 1, pat + j));
		else if (pat[j] == '[' && (ptr = ft_strchr(pat + j, ']'))
			&& sh_glob_match_range(str[i], pat + j))
			j = ptr - pat + 1 + 0 * i++;
		else
			return (0);
	}
	if (pat[i] == '*')
		return (sh_glob_match(str + i, pat + j + 1));
	return ((!pat[j] && !str[i]) || !ft_strcmp(pat + j, "*") ? 1 : 0);
}

int		sh_glob_match_range(int c, char *ran)
{
	int	i;
	int	neg;

	if (*ran != '[')
		return (0);
	neg = ran[1] == '^';
	i = neg ? 1 : 0;
	while (ran[++i] && ran[i] != ']')
	{
		if (c == ran[i])
			return (1 - neg);
		else if (ran[i] == '-' && i - 1 > -1
			&& ran[i + 1] && ran[i + 1] != ']'
			&& c >= ran[i - 1] && c <= ran[i + 1])
			return (1 - neg);
	}
	return (neg);
}
