/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dstr_insert.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 11:36:33 by abbesbes          #+#    #+#             */
/*   Updated: 2019/03/14 15:05:09 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_dstrins_ch(t_dstr *dstr, ssize_t i, int c)
{
	ssize_t s;
	ssize_t j;

	if (!dstr)
		return (-1);
	if (!dstr->str)
	{
		dstr->str = (char*)malloc(2 * sizeof(char));
		dstr->max = 1;
		dstr->str[0] = c;
		dstr->str[1] = '\0';
		return (0);
	}
	s = ft_strlenz(dstr->str);
	if (i < 0 || i > s - 1)
		i = s;
	if (s + 1 > dstr->max)
		ft_dstrext_x2(dstr);
	j = s + 1;
	while (--j > i)
		dstr->str[j] = dstr->str[j - 1];
	dstr->str[i] = c;
	dstr->len += 1;
	dstr->str[dstr->len] = '\0';
	return (0);
}

static void	ft_dstrins_str_pop(t_dstr *dstr, char *str)
{
	dstr->str = ft_strdup(str);
	dstr->max = ft_strlenz(str) + 1;
	dstr->len = dstr->max;
}

int			ft_dstrins_str(t_dstr *dstr, ssize_t i, char *str)
{
	ssize_t n;
	ssize_t s;
	ssize_t j;

	if (!dstr || !str)
		return (-1);
	if (!dstr->str)
	{
		ft_dstrins_str_pop(dstr, str);
		return (0);
	}
	s = ft_strlenz(dstr->str);
	i = i < 0 || i > s - 1 ? s : i;
	if (s + (n = ft_strlenz(str)) > dstr->max)
		ft_dstrext_n(dstr, n);
	j = s + n;
	dstr->str[j] = '\0';
	while (--j > i - 1)
		dstr->str[j] = dstr->str[j - n];
	j = -1;
	while (++j < n)
		dstr->str[i + j] = str[j];
	dstr->len += ft_strlenz(str);
	dstr->str[dstr->len] = '\0';
	return (0);
}

int			ft_dstrins_str_free(t_dstr *dstr, ssize_t i, char **str)
{
	int ret;

	ret = ft_dstrins_str(dstr, i, *str);
	ft_memdel((void**)str);
	return (ret);
}
