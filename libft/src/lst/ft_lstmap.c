/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 11:39:56 by abbesbes          #+#    #+#             */
/*   Updated: 2018/11/20 22:33:44 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new;

	if (!lst || !f)
		return (NULL);
	if (!(new = ft_lstnew(NULL, 0)))
		return (NULL);
	new = (*f)(lst);
	new->next = ft_lstmap(lst->next, f);
	return (new);
}
