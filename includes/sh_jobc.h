#ifndef SH_JOBC_H
#define SH_JOBC_H

#include "sh_jctype.h"
#include "sh_sh.h"
//#include "ftsh.h"

//int 			sh_jc_launch(t_job *job);
//int 			sh_jc_exec(t_job *job);

t_job 			*sh_jc_new_job(int ind, int bg);
void			sh_jc_free_job(void **pjob);
int				sh_jc_get_done(t_job *job);

int				sh_jc_mark_as_running(t_job *job);

int 			sh_jc_add(t_jcon *jc, int bg);

int 			sh_jc_init(t_jcon *jc);
t_jcon 			*sh_jc_new(void);

/**
 *
 * @param job
 * @param info
 * @return
 */
int 			sh_jc_put_in_forg(t_sh *sh, int cont);

/**
 *
 * @param job
 * @param info
 * @return
 */
int 			sh_jc_put_in_back(t_sh *sh, int cont);

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
int 			sh_jc_wait(t_jcon *jc, t_job *job);

/**
 *
 * @param job
 * @param info
 * @return
 */
int 			sh_jc_inform(t_job *job, int info);

int 			sh_jc_update_status(t_jcon *jc);

/**
 *
 * @param job
 * @return
 */
int 			sh_jc_notify(t_jcon *jc);

/**
 *
 * @param job
 * @param pid
 * @param status
 * @return
 */
int 			sh_jc_mark_status(t_jcon *jc, pid_t pid, int status);

/**
 *
 * @param job
 * @return
 */
int				sh_jc_continue(t_sh *sh, t_job *job);

void			sh_jcp_print(t_process *p);
void			sh_jcp_lstput(t_list *plist);

#endif
