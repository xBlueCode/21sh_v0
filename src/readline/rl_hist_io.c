/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_hist_io.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 19:31:16 by abbesbes          #+#    #+#             */
/*   Updated: 2019/10/07 19:31:18 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <errno.h>
#include "ftsh.h"

extern t_hist	g_his;

int				rl_hist_upload(void)
{
	int fd;
	int ret;

	if ((fd = open(g_his.filename, O_RDONLY)) < 0)
	{
		return (-1);
	}
	ret = rl_hist_read(fd);
	close(fd);
	return (ret);
}

int				rl_hist_save(void)
{
	int fd;
	int ret;

	if (!g_his.ent)
		return (0);
	if ((fd = open(g_his.filename,
		O_APPEND | O_WRONLY | O_CREAT, S_IRWXU | S_IRWXG)) < 0)
		return (-1);
	ret = rl_hist_write(fd);
	close(fd);
	return (ret);
}

int				rl_hist_read(int fd)
{
	t_dstr		*data;
	int			c;
	int			num;
	int			ret;

	num = 0;
	data = ft_dstrnew_max(1024);
	while (!(c = 0) && read(fd, &c, 1))
	{
		ft_dstrins_ch(data, data->len, c);
		if (c == 0x03)
			num++;
	}
	if (num && (g_his.off = num))
		ret = rl_hist_parse(data->str, num);
	else
		ret = 0;
	ft_dstrfree(&data);
	return (ret);
}

int				rl_hist_write(int fd)
{
	int		i;

	i = g_his.off;
	while (i < g_his.ent->len)
		if (g_his.ent->a[i] && g_his.ent->a[i]->str)
		{
			write(fd, g_his.ent->a[i]->str, g_his.ent->a[i]->len);
			write(fd, "\03", 1);
			i++;
		}
	return (0);
}
