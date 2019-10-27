/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 17:36:13 by abbesbes          #+#    #+#             */
/*   Updated: 2018/12/03 16:53:49 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*get_curr_data(t_list **data, int fd)
{
	t_list *elem;

	if ((elem = ft_lst_getby_csize(*data, fd)))
		return (elem);
	if (!(elem = ft_lstnew("\0", 1)))
		return (NULL);
	elem->content_size = fd;
	ft_lstadd(data, elem);
	return (*data);
}

static int		update_data(t_list **data_curr, char **line)
{
	char	*nl;
	char	*tmp;

	if ((nl = ft_strchr((*data_curr)->content, '\n')))
		*nl = '\0';
	if (!(*line = ft_strdup((*data_curr)->content)))
		return (MSG_ERROR);
	tmp = (*data_curr)->content;
	if (nl)
		(*data_curr)->content = ft_strdup(nl + 1);
	else
		(*data_curr)->content = ft_strnew(1);
	free(tmp);
	return (MSG_OK);
}

int				get_next_line(const int fd, char **line)
{
	static t_list	*data;
	char			buff[BUFF_SIZE + 1];
	t_list			*data_curr;
	int				red;
	char			*tmp;

	if (BUFF_SIZE < 1 || fd < 0 || !line || read(fd, buff, 0) < 0)
		return (MSG_ERROR);
	if (!(data_curr = get_curr_data(&data, fd)))
		return (MSG_ERROR);
	while (!(ft_strchr(data_curr->content, '\n'))
		&& (red = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[red] = '\0';
		tmp = data_curr->content;
		data_curr->content = ft_strjoin(data_curr->content, buff);
		free(tmp);
		if (ft_strchr(buff, '\n'))
			break ;
	}
	if (red < 0)
		return (MSG_ERROR);
	if (red < BUFF_SIZE && (!ft_strlen(data_curr->content)))
		return (MSG_END);
	return (update_data(&data_curr, line));
}
