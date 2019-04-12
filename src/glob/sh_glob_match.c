/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_glob_match.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 14:03:06 by abbesbes          #+#    #+#             */
/*   Updated: 2019/04/08 14:03:08 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftsh.h"

int     sh_glob_match(char *str, char *pat)
{
    int     i;
    int     j;
    char    *ptr;

    i = 0;
    j = 0;
    while(str[i] && pat[j])
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
    return (!pat[j] ? 1 : 0);
}

int     sh_glob_match_range(int c, char *ran)
{
    int i;
    int class;
	int neg;

    if (*ran != '[')
        return (0);
    //if ((class = sh_glob_cget(ran)) > -1)
      //  return (sh_g_caction[class](c));
	neg = ran[1] == '^';
    i = neg ? 1 : 0;
    while(ran[++i] && ran[i] != ']')
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

/*
int     sh_glob_cget(char *class)
{
    int i;

    i = -1;
    while (sh_g_clist[++i])
        if (!ft_strncmp(sh_g_clist[i], class, ft_strlenz(sh_g_clist[i])))
            return (i);
    return (-1);
}
*/
