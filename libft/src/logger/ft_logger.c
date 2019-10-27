/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_logger.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 15:57:36 by abbesbes          #+#    #+#             */
/*   Updated: 2019/02/28 16:27:12 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <sys/stat.h>
#include <fcntl.h>

t_ft_log	g_ft_log;

int		ft_log_open(char *logdir, char *logprefix)
{
	char	logname[FT_LOG_NAME_MAX];

	if (getcwd(logname, FT_LOG_NAME_MAX) == NULL)
		return (g_ft_log.fd = -1);
	ft_strcat(logname, "/");
	ft_strcpy(logname, logdir);
	ft_strcat(logname, "/");
	ft_strcat(logname, logprefix);
	ft_strcat(logname, "_log_");
	ft_strcat(logname, __DATE__);
	ft_strcat(logname, "__");
	ft_strcat(logname, __TIME__);
	ft_strcat(logname, ".log");
	if ((g_ft_log.fd = open(logname, O_WRONLY | O_CREAT, S_IRWXU)) > -1)
	{
		write(g_ft_log.fd, logname, ft_strlenz(logname));
		write(g_ft_log.fd, "\n\n", 2);
	}
	return (g_ft_log.fd);
}

int		ft_log_close(void)
{
	return (close(g_ft_log.fd));
}

int		ft_log(int lev, int form, char *mess, ...)
{
	va_list	args;

	if (g_ft_log.fd < 0)
		return (-1);
	if (lev > FT_LOG_LEV)
		return (0);
	va_start(args, mess);
	if (BIT_IS(form, FT_LOG_FDATE))
		ft_dprintf(FT_LOG_VFD, " %-*s  |", FT_LOG_WDATE, FT_LOG_VDATE);
	if (BIT_IS(form, FT_LOG_FTIME))
		ft_dprintf(FT_LOG_VFD, " %-*s  |", FT_LOG_WTIME, FT_LOG_VTIME);
	if (BIT_IS(form, FT_LOG_FLEV))
		ft_dprintf(FT_LOG_VFD, " %-*d  |", FT_LOG_WLEV, lev);
	if (BIT_IS(form, FT_LOG_FFILE))
		ft_dprintf(FT_LOG_VFD, " %-*s  |", FT_LOG_WFILE, FT_LOG_VFILE);
	if (BIT_IS(form, FT_LOG_FLINE))
		ft_dprintf(FT_LOG_VFD, " %-*d  |", FT_LOG_WLINE, FT_LOG_VLINE);
	if (BIT_IS(form, FT_LOG_FFUNC))
		ft_dprintf(FT_LOG_VFD, " %-*s  |", FT_LOG_WFUNC, FT_LOG_VFUNC);
	if (BIT_IS(form, FT_LOG_FMESS) && mess)
		ft_vdprintf(FT_LOG_VFD, mess, args);
	va_end(args);
	return (0);
}
