#include "ftsh.h"

t_jcon 			*sh_jc_new(void)
{
	t_jcon *jc;

	jc = ft_memalloc(sizeof(t_jcon));
	jc->cind = 0;
	jc->cjob = NULL;
	jc->jobs = NULL;
	return (jc);
}

t_job 			*sh_jc_new_job(int ind, int bg)
{
	t_job *job;

	DE0
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

	DE0
	if (!jc && ft_printf("JC NULL\n"))
		return (KO);
	jc->cind++;
	new_job = sh_jc_new_job(jc->cind, bg);
	jc->cjob = new_job;
	ft_printf("--- > job added \n");
	ft_lst_addlast(&(jc->jobs), ft_lstnew(new_job, sizeof(t_job)));
	return (0);
}
