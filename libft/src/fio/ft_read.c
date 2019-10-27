/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 18:53:19 by abbesbes          #+#    #+#             */
/*   Updated: 2019/10/21 18:53:21 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <fcntl.h>

t_dstr	*ft_read_file(char *filename)
{
	int		fd;
	int		red;
	char	buff[FT_READ_BUFF_SIZE + 1];
	t_dstr	*res;

	if (!filename)
		return (NULL);
	if ((fd = open(filename, O_RDONLY)) < 0)
		return (NULL);
	res = ft_dstrnew_max(2);
	while ((red = read(fd, buff, FT_READ_BUFF_SIZE)) > 0)
	{
		buff[red] = '\0';
		ft_dstrins_str(res, -1, buff);
	}
	return (res);
}

t_dstr	*ft_read_fd(int fd)
{
	int		red;
	char	buff[FT_READ_BUFF_SIZE + 1];
	t_dstr	*res;

	if (fd < 0)
		return (NULL);
	res = ft_dstrnew_max(2);
	while ((red = read(fd, buff, FT_READ_BUFF_SIZE)) > 0)
	{
		buff[red] = '\0';
		ft_dstrins_str(res, -1, buff);
	}
	return (res);
}

int		ft_read_fd_in(int fd, t_dstr *dstr)
{
	int		red;
	char	buff[FT_READ_BUFF_SIZE + 1];

	if (fd < 0 || !dstr || !dstr->str)
		return (KO);
	while ((red = read(fd, buff, FT_READ_BUFF_SIZE)) > 0)
	{
		buff[red] = '\0';
		ft_dstrins_str(dstr, -1, buff);
	}
	return (OK);
}
