/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_logger.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 14:41:47 by abbesbes          #+#    #+#             */
/*   Updated: 2019/02/28 16:56:58 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LOGGER_H
# define FT_LOGGER_H

# define FT_LOG_NAME_MAX 255

# define FT_LOG_LOFF	0x00
# define FT_LOG_LFAT	0x01
# define FT_LOG_LERR	0x02
# define FT_LOG_LWRN	0x04
# define FT_LOG_LINF	0x08
# define FT_LOG_LDEB	0x10
# define FT_LOG_LTRC	0x20
# define FT_LOG_LALL	0x40

# define FT_LOG_LEV	FT_LOG_LDEB

# define FT_LOG_FDATE	0x01
# define FT_LOG_FTIME	0x02
# define FT_LOG_FLEV	0x04
# define FT_LOG_FFILE	0x08
# define FT_LOG_FLINE	0x10
# define FT_LOG_FFUNC	0x20
# define FT_LOG_FMESS	0x40

# define FT_LOG_FALL	0x7f

# define FT_LOG_WDATE	10
# define FT_LOG_WTIME	12
# define FT_LOG_WLEV	4
# define FT_LOG_WFILE	16
# define FT_LOG_WLINE	4
# define FT_LOG_WFUNC	32

# define D ft_log_up_date(__DATE__);
# define T ft_log_up_time(__TIME__);
# define F ft_log_up_file(__FILE__);
# define L ft_log_up_line(__LINE__);
# define FN ft_log_up_func((char*)__func__);

# define FT_LOG(l, f, m, ...) {D; T; F; L; FN; ft_log(l, f, m, __VA_ARGS__);}

# define FT_LOG_VFD		(g_ft_log.fd)
# define FT_LOG_VDATE	(g_ft_log.date)
# define FT_LOG_VTIME	(g_ft_log.time)
# define FT_LOG_VFILE	(g_ft_log.file)
# define FT_LOG_VLINE	(g_ft_log.line)
# define FT_LOG_VFUNC	(g_ft_log.func)

# define FT_LOG_FUNC FT_LOG(FT_LOG_LINF,FT_LOG_FFUNC | FT_LOG_FMESS, "%c", '\n')

typedef struct	s_ft_log
{
	int		fd;
	char	*file;
	int		line;
	char	*date;
	char	*time;
	char	*func;
}				t_ft_log;

int				ft_log(int lev, int form, char *mess, ...);
int				ft_log_open(char *logdir, char *logprefix);
int				ft_log_close(void);

int				ft_log_up_date(char *date);
int				ft_log_up_time(char *time);
int				ft_log_up_file(char *file);
int				ft_log_up_line(int line);
int				ft_log_up_func(char *func);

#endif
