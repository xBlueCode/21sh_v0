/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_als.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 19:06:49 by abbesbes          #+#    #+#             */
/*   Updated: 2019/10/07 19:06:52 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "sh_alias.h"

t_hset		*g_als;

t_hset		*sh_als(void)
{
	return (g_als);
}

int			sh_als_init(void)
{
	g_als = ft_hset_init(SH_ALS_HTSIZE,
		ft_htab_hcode_str, ft_htab_equals_str, ft_htab_free_ent_str);
	return (OK);
}

int			sh_als_add(t_hset *als, char *key, char *val)
{
	t_htabent	ent;

	if (!als || !key || !val)
		return (KO);
	ent = (t_htabent){
		.key = key, .ksize = ft_strlenz(key) + 1,
		.val = val, .vsize = ft_strlenz(val) + 1};
	return (ft_htab_put(als, &ent));
}

int			sh_als_rem(t_hset *als, char *key)
{
	if (!als || !key)
		return (KO);
	return (ft_htab_rem(als, key, ft_strlen(key) + 1));
}

int			sh_als_reset(void)
{
	ft_hset_free(&g_als);
	return (sh_als_init());
}
