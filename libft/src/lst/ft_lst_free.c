/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 20:35:56 by abbesbes          #+#    #+#             */
/*   Updated: 2019/02/01 13:59:10 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lst_free(t_list **list, void (*content_free)(void **))
{
	if (!list || !*list || !content_free)
		return ;
	if (!(*list)->next)
	{
		(*content_free)(&((*list)->content));
		ft_memdel((void**)(list));
	}
	else
	{
		ft_lst_free(&((*list)->next), content_free);
		(*content_free)(&((*list)->content));
		ft_memdel((void**)(list));
	}
}

void	ft_lst_free_if(t_list **plst, int (*cond)(void*, void*),
		void *data, void (*c_free)(void**))
{
	t_list *head;

	if (!plst || !*plst || !c_free || !cond || !data)
		return ;
	if ((*cond)(data, (*plst)->content))
	{
		head = (*plst)->next;
		(*c_free)(&(*plst)->content);
		ft_memdel((void**)plst);
		*plst = head;
	}
	else
		ft_lst_free_if(&(*plst)->next, cond, data, c_free);
}

void	ft_lst_freeif(t_list **plst, int (*cond)(void*),
		void (*c_free)(void**))
{
	t_list *head;

	if (!plst || !*plst || !c_free || !cond)
		return ;
	if ((*cond)((*plst)->content))
	{
		head = (*plst)->next;
		(*c_free)(&(*plst)->content);
		ft_memdel((void**)plst);
		*plst = head;
	}
	else
		ft_lst_freeif(&(*plst)->next, cond, c_free);
}
