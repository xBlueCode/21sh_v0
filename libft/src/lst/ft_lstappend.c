/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstappend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 11:45:34 by abbesbes          #+#    #+#             */
/*   Updated: 2019/02/02 11:54:46 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstappend(t_list *head, t_list *last)
{
	t_list *cur;

	cur = head;
	if (!cur)
		return (last);
	while (cur->next)
		cur = cur->next;
	cur->next = last;
	return (head);
}

t_list	*ft_lstdup_one(t_list *lst)
{
	if (!lst)
		return (NULL);
	return (ft_lstnew(lst->content, lst->content_size));
}

t_list	*ft_lstappend_dup(t_list *head, t_list *last)
{
	t_list	*nhead;
	t_list	*nlast;

	nhead = NULL;
	nlast = NULL;
	while (head)
	{
		ft_lst_addlast(&nhead, ft_lstdup_one(head));
		head = head->next;
	}
	while (last)
	{
		ft_lst_addlast(&nlast, ft_lstdup_one(last));
		last = last->next;
	}
	return (ft_lstappend(nhead, nlast));
}
