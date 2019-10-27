/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_getby_content.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 14:38:43 by abbesbes          #+#    #+#             */
/*   Updated: 2018/11/22 15:45:11 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lst_getby_content(t_list *lst, void *content, size_t n)
{
	if (!lst || !content)
		return (NULL);
	if (ft_memcmp((const void *)lst->content, (const void *)content, n) == 0)
		return (lst);
	return (ft_lst_getby_content(lst->next, content, n));
}
