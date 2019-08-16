#include "ftsh.h"


t_job 			*sh_jc_new(int ind, int bg)
{
	t_job *job;

	job = ft_memalloc(sizeof(t_job));
	job->ind = ind;
	job->bg = bg;
	job->pgid = -1;
	job->notified = 0;
	job->tmodes = NULL;
	job->process = NULL;
	return (job);
}

int 			sh_jc_add(t_jcon *jc, int bg)
{
	t_job *new_job;
	jc->cind++;
	new_job = sh_jc_new(jc->cind, bg);
	jc->cjob = new_job;
	ft_lst_addlast(&(jc->jobs), ft_lstnew(new_job, sizeof(t_job)));
	return (0);
}
