#ifndef SH_JOBC_H
#define SH_JOBC_H

#include "ftsh.h"

typedef struct	s_process {
	struct			s_process *next; /* next process in pipeline */ // --> and_or
	char			**argv; /* for exec */
	pid_t			pid; /* process ID */
	char			completed; /* true if process has completed */
	char			stopped; /* true if process has stopped */
	int				status; /* reported status value */
}				t_process;

/* A job is a pipeline of processes. */
typedef struct	s_job {
	struct			job *next; /* next active job */
	char			*command; /* command line, used for messages */
	t_process		*process; /* list of processes in this job */ // and_or
	pid_t			pgid; /* process group ID */
	char			notified; /* true if user told about stopped job */
	struct termios	tmodes; /* saved terminal modes */
//	int 			std_in;
//	int				std_out;
//	int				std_err;
}				t_job;

/**
 *
 * @param job
 * @return
 */
int 			sh_jc_launch(t_job *job);

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
