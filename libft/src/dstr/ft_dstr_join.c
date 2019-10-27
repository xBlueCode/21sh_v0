/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dstr_join.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 11:55:20 by abbesbes          #+#    #+#             */
/*   Updated: 2019/06/26 11:55:23 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dstr		*ft_dstrjoin_all(t_dstr **arr, char *link)
{
	int			alen;
	t_dstr		*res;

	if (!arr || !*arr)
		return (NULL);
	if (!link)
		link = "";
	res = ft_dstrnew_max(2);
	alen = -1;
	while (arr[++alen])
	{
		if (!arr[alen + 1])
			break ;
		ft_dstrins_str(res, -1, arr[alen]->str);
		ft_dstrins_str(res, -1, link);
	}
	ft_dstrins_str(res, -1, arr[alen]->str);
	return (res);
}

t_dstr		*ft_dstrjoin_n(t_dstr **arr, int n, char *link)
{
	int			alen;
	t_dstr		*res;

	if (!arr || !*arr || n < 1)
		return (NULL);
	if (!link)
		link = "";
	res = ft_dstrnew_max(2);
	alen = -1;
	while (++alen < n && arr[alen])
	{
		if (!arr[alen + 1])
			break ;
		ft_dstrins_str(res, -1, arr[alen]->str);
		ft_dstrins_str(res, -1, link);
	}
	ft_dstrins_str(res, -1, arr[alen]->str);
	return (res);
}
