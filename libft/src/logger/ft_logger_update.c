/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_logger_update.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 18:41:00 by abbesbes          #+#    #+#             */
/*   Updated: 2019/02/28 14:08:08 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/includes/libft.h"

extern t_ft_log	g_ft_log;

int		ft_log_up_file(char *file)
{
	g_ft_log.file = file;
	return (0);
}

int		ft_log_up_line(int line)
{
	g_ft_log.line = line;
	return (0);
}

int		ft_log_up_date(char *date)
{
	g_ft_log.date = date;
	return (0);
}

int		ft_log_up_time(char *time)
{
	g_ft_log.time = time;
	return (0);
}

int		ft_log_up_func(char *func)
{
	g_ft_log.func = func;
	return (0);
}
