/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_als_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 19:58:57 by abbesbes          #+#    #+#             */
/*   Updated: 2019/10/07 19:58:58 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "sh_alias.h"

int			sh_als_print(t_hset *als)
{
	int i;

	i = -1;
	while (++i < als->max)
		ft_lstiter(als->arr[i], &sh_als_print_ent);
	return (OK);
}

void		sh_als_print_ent(t_list *entlst)
{
	ft_putstr("Alias: ");
	ft_putstr((char*)((t_htabent*)entlst->content)->key);
	ft_putchar('=');
	ft_putstr((char*)((t_htabent*)entlst->content)->val);
}
