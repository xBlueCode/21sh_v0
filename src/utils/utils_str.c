/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 16:44:55 by abbesbes          #+#    #+#             */
/*   Updated: 2019/04/01 13:24:30 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

ssize_t		ft_strind_w_next_end(char *str, ssize_t cc)
{
	ssize_t i;

	i = cc;
	if (!str || i < 0 || (ssize_t)ft_strlenz(str) < i + 1)
		return (-1);
	if (!ft_isspace(str[i]) && ft_isspace(str[i + 1]))
		return (ft_strind_w_next_end(str, i + 1));
	while (ft_isspace(str[i]))
		i++;
	while (str[i] && !ft_isspace(str[i]))
		i++;
	if (!str)
		return (cc);
	return (i - 1);
}

ssize_t		ft_strind_w_next_beg(char *str, ssize_t cc)
{
	ssize_t i;

	i = cc;
	if (!str || i < 0 || (ssize_t)ft_strlenz(str) < i + 1)
		return (-1);
	while (str[i] && !ft_isspace(str[i]))
		i++;
	while (str[i] && ft_isspace(str[i]))
		i++;
	if (!str[i])
		return (cc);
	else
		return (i);
}

ssize_t		ft_strind_w_prev_beg(char *str, ssize_t cc)
{
	ssize_t i;
	ssize_t s;

	i = cc;
	if (!str || i <= 0 || (s = (ssize_t)ft_strlenz(str)) < i)
		return (-1);
	i = i - (s == i ? 1 : 0);
	if (!ft_isspace(str[i]) && ft_isspace(str[i - 1]))
		return (ft_strind_w_prev_beg(str, cc - 1));
	while (i > -1 && ft_isspace(str[i]))
		i--;
	while (i > -1 && !ft_isspace(str[i]))
		i--;
	return (i + 1);
}

int			ft_strind_w_get_ilen(char *str, ssize_t cc, ssize_t *il)
{
	if (!str || cc < 0 || (ssize_t)ft_strlenz(str) < cc + 1)
		return (-1);
	if (!str[cc] || ft_isspace(str[cc]))
		return (-1);
	il[0] = cc;
	while (il[0] > -1 && !ft_isspace(str[il[0]]))
		il[0]--;
	il[1] = ++il[0];
	while (str[il[1]] && !ft_isspace(str[il[1]]))
		il[1]++;
	il[1] = il[1] - il[0];
	return (0);
}

int			ft_strind_w_next_get_ilen(char *str, ssize_t cc, ssize_t *il)
{
	if (!str || cc < 0 || (ssize_t)ft_strlenz(str) < cc + 1)
		return (-1);
	if ((il[0] = ft_strind_w_next_beg(str, cc)) < 0 || il[0] == cc)
		return (-1);
	il[1] = il[0];
	while (str[il[1]] && !ft_isspace(str[il[1]]))
		il[1]++;
	il[1] = il[1] - il[0];
	return (0);
}
