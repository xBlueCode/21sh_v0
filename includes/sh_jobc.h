#ifndef SH_JOBC_H
#define SH_JOBC_H

#include "ftsh.h"

/**
 * pid			:
 * completed	: true if process has completed
 * stopped		: true if process has stopped
 * status		: reported status value
 */
typedef struct	s_process {
	//struct			s_process *next; /* next process in pipeline */ // --> and_or
	//char			**argv; /* for exec */
	pid_t			pid; /* process ID */
	char			completed; /* true if process has completed */
	char			stopped; /* true if process has stopped */
	int				status; /* reported status value */
}				t_process;

/* A job is a pipeline of processes. */
/**
 * ind			: job index
 * pgid			: process group ID (pgid)
 * notified		: true if user told about stopped job
 */
typedef struct	s_job {
	int				ind;
	pid_t			pgid; /* process group ID */
	char			notified; /* true if user told about stopped job */
	t_termios		tmodes; /* saved terminal modes */
	t_list			process;
//	t_and_or		*andor_list;
	char 			bg;
}				t_job;

/**
** cind			: current index
** jobs			: list of jobs
** cjob			: current job being processed
** sh_pid		: shell PID
** sh_termios	: terminal atts of the shell
*/
typedef struct	s_jcon
{
	int			cind;
	t_list		*jobs;
	t_job		*cjob;
	pid_t 		sh_pid; // it can be moved to the shell dashboard
	t_termios	sh_termios; // it can be moved to shell dashboard
}				t_jcon;

/**
 *
 * @param job
 * @return
 */
int 			sh_jc_launch(t_job *job);

int 			sh_jc_exec(t_job *job);

/**
 *
 * @param job
 * @param info
 * @return
 */
int 			sh_jc_putj_in_forg(t_job *job, int info);

/**
 *
 * @param job
 * @param info
 * @return
 */
int 			sh_jc_putj_in_back(t_job *job, int info);

/**
** Find the active job with the indicated pgid.
** @param pgid
** @return
*/
t_job			*sh_jc_find_job (pid_t pgid);

/**
 *
 * @param job
 * @return
 */
int 			sh_jc_is_stop(t_job *job);

/**
 *
 * @param job
 * @return
 */
int 			sh_jc_is_done(t_job *job);

/**
 *
 * @param job
 * @return
 */
int 			sh_jc_wait(t_job *job);

/**
 *
 * @param job
 * @param info
 * @return
 */
int 			sh_jc_inform(t_job *job, int info);

/**
 *
 * @param job
 * @return
 */
int 			sh_jc_notify(t_job *job);

/**
 *
 * @param job
 * @param pid
 * @param status
 * @return
 */
int 			sh_jc_mark_pstatus(t_job *job, pid_t pid, int status);

/**
 *
 * @param job
 * @return
 */
int				sh_jc_continue(t_job *job);


#endif
