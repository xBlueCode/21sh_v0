/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_getby_i.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 15:01:25 by abbesbes          #+#    #+#             */
/*   Updated: 2018/11/22 15:10:55 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lst_getby_i(t_list *lst, size_t i)
{
	if (!lst)
		return (NULL);
	if (i == 0)
		return (lst);
	return (ft_lst_getby_i(lst->next, --i));
}
