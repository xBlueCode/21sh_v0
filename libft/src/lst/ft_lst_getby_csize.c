/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_getby_csize.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 14:54:30 by abbesbes          #+#    #+#             */
/*   Updated: 2018/11/22 15:00:58 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lst_getby_csize(t_list *lst, size_t csize)
{
	if (!lst)
		return (NULL);
	if (lst->content_size == csize)
		return (lst);
	return (ft_lst_getby_csize(lst->next, csize));
}
