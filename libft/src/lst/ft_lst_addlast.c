/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstinsert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 18:44:49 by abbesbes          #+#    #+#             */
/*   Updated: 2019/02/02 11:38:08 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_lst_addlast(t_list **head, t_list *last)
{
	if (!last || !head)
		return ;
	if (!(*head))
		*head = last;
	else
		ft_lst_addlast(&((*head)->next), last);
}
