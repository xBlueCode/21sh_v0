/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 16:56:56 by abbesbes          #+#    #+#             */
/*   Updated: 2019/02/02 12:20:57 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LST_H
# define FT_LST_H

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

typedef int		(*t_ft_lst_cmp)(t_list *elem1, t_list *elem2, int r);
typedef int		(*t_ft_lst_sel)(t_list *elem, int op);

t_list			*ft_lstnew(const void *content, size_t content_size);
t_list			*ft_lstset(void const *content, ssize_t csize);
void			ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void			ft_lstadd(t_list **alst, t_list *n);
t_list			*ft_lstappend_dup(t_list *head, t_list *last);
t_list			*ft_lstdup_one(t_list *lst);
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void			ft_lstiter_option(t_list *lst,
	void (*f)(t_list *elem, int *opt), int *o);
void			ft_lstiterop(t_list *lst,
	void (*f)(t_list *elem, int op), int o);

size_t			ft_lstlen(t_list *head);

t_list			*ft_lstappend(t_list *head, t_list *last);
void			ft_lst_addlast(t_list **head, t_list *last);
void			ft_lst_putone(t_list *elem);
void			ft_lst_putone_nl(t_list *elem);
t_list			*ft_lst_getby_content(t_list *lst, void *content, size_t n);
t_list			*ft_lst_getby_csize(t_list *lst, size_t csize);
t_list			*ft_lst_getby_i(t_list *lst, size_t i);

t_list			*ft_lst_getif(t_list *lst, t_ft_lst_cmp equal);

void			ft_lst_free(t_list **list, void (*content_free)(void **));
void			ft_lst_free_in(t_list **list, void (*content_free)(void **),
	int i, int n);
void			ft_lst_free_head(t_list **plst, int n, void(*c_free)(void**));
void			ft_lst_free_if(t_list **plst,
	int (*cond)(void*, void*), void *data, void (*c_free)(void**));
void			ft_lst_freeif(t_list **plst,
	int (*cond)(void*), void (*c_free)(void**));

#endif
