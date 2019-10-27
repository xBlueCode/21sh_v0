/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_htab_hash_str.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 18:46:18 by abbesbes          #+#    #+#             */
/*   Updated: 2019/10/21 18:46:20 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_htab_equals_str(void *ent1, void *ent2)
{
	return (!ft_strcmp((char *)(((t_htabent *)ent1)->key),
		(char *)(((t_htabent *)ent2)->key)));
}

size_t	ft_htab_hcode_str(void *data)
{
	return (ft_hcode_str(((t_htabent*)data)->key));
}

void	ft_htab_free_ent_str(void **ent)
{
	FT_MEMDEL(((t_htabent*)(*ent))->key);
	FT_MEMDEL(((t_htabent*)(*ent))->val);
	FT_MEMDEL(*ent);
}
