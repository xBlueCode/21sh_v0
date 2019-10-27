/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_option.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 19:25:03 by abbesbes          #+#    #+#             */
/*   Updated: 2019/01/27 14:43:52 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter_option(t_list *lst,
		void (*f)(t_list *elem, int *opt), int *o)
{
	if (!lst || !f)
		return ;
	(*f)(lst, o);
	ft_lstiter_option(lst->next, f, o);
}

void	ft_lstiterop(t_list *lst, void (*f)(t_list *elem, int op), int o)
{
	if (!lst || !f)
		return ;
	(*f)(lst, o);
	ft_lstiterop(lst->next, f, o);
}
