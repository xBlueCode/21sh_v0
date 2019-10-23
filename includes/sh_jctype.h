/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_jctype.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 19:34:10 by abbesbes          #+#    #+#             */
/*   Updated: 2019/10/07 19:34:11 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_JCTYPE_H
# define SH_JCTYPE_H

/*
** pid			:
** done			: true if process has completed
** stopped		: true if process has stopped
** status		: reported status value
*/

typedef struct	s_process {
	pid_t			pid;
	char			done;
	char			stopped;
	int				status;
}				t_process;

/*
** A job is a pipeline of processes.
** ind			: job index
** pgid			: process group ID (pgid)
** notified		: true if user told about stopped job
*/

typedef struct	s_job
{
	int				ind;
	pid_t			pgid;
	char			notified;
	t_termios		*tmodes;
	t_list			*process;
	char			bg;
	int				done;
	int				sep_ao;
}				t_job;

/*
** cind			: current index (init :: -1)
** jobs			: list of jobs (init :: NULL)
** cjob			: current job being processed (init :: NULL)
*/

typedef struct	s_jcon
{
	int			cind;
	t_list		*jobs;
	t_job		*cjob;
}				t_jcon;

#endif
