#ifndef SH_JOBC_H
#define SH_JOBC_H

#include "ftsh.h"

/**
 * pid			:
 * done			: true if process has completed
 * stopped		: true if process has stopped
 * status		: reported status value
 */
typedef struct	s_process {
	pid_t			pid; /* process ID */
	char			done; /* true if process has completed */
	char			stopped; /* true if process has stopped */
	int				status; /* reported status value */
}				t_process;

/* A job is a pipeline of processes. */
/**
 * ind			: job index
 * pgid			: process group ID (pgid)
 * notified		: true if user told about stopped job
 */
typedef struct	s_job
{
	int				ind;
	pid_t			pgid;
	char			notified;
	t_termios		tmodes;
	t_list			*process;
	char 			bg;
	int 			lev;
}				t_job;

/**
** cind			: current index (init :: -1)
** jobs			: list of jobs (init :: NULL)
** cjob			: current job being processed (init :: NULL)
** jlev			: level of background jobs (init :: 0)
*/
typedef struct	s_jcon
{
	int 		cind;
	t_list		*jobs;
	t_job		*cjob;
//	int 		jlev;
}				t_jcon;

//int 			sh_jc_launch(t_job *job);
//int 			sh_jc_exec(t_job *job);

t_job 			*sh_jc_new(int bg);
int 			sh_jc_add(t_jcon *jc, t_job *job);

/**
 *
 * @param job
 * @param info
 * @return
 */
int 			sh_jc_put_in_forg(t_job *job, int info);

/**
 *
 * @param job
 * @param info
 * @return
 */
int 			sh_jc_put_in_back(t_job *job, int info);

/**
** Find the active job with the indicated pgid.
** @param pgid
** @return
*/
t_job			*sh_jc_find_job (t_jcon *jc, pid_t pgid);

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
int 			sh_jc_mark_status(t_job *job, pid_t pid, int status);

/**
 *
 * @param job
 * @return
 */
int				sh_jc_continue(t_job *job);


#endif
