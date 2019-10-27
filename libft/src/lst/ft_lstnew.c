/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 11:39:06 by abbesbes          #+#    #+#             */
/*   Updated: 2018/11/20 22:32:13 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list *new;

	if (!(new = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	if (!content)
	{
		new->content = NULL;
		new->content_size = 0;
	}
	else
	{
		if (!(new->content = malloc(content_size)))
			return (NULL);
		ft_memcpy(new->content, content, content_size);
		new->content_size = content_size;
	}
	new->next = NULL;
	return (new);
}

t_list		*ft_lstset(void const *content, ssize_t csize)
{
	t_list *new;

	if (!(new = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	new->content = content ? (void*)content : NULL;
	new->content_size = content ? csize : 0;
	new->next = NULL;
	return (new);
}
