/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_jc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 19:13:42 by abbesbes          #+#    #+#             */
/*   Updated: 2019/10/07 19:13:43 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

	DF0;
	job = ft_memalloc(sizeof(t_job));
	job->ind = ind;
	job->bg = bg;
	job->pgid = 0;
	job->notified = 0;
	job->tmodes = NULL;
	job->process = NULL;
	job->done = 0;
	job->sep_ao = 0;
	return (job);
}

void			sh_jc_free_job(void **pjob) // TODO: intern free
{
	DF0;
	ft_memdel(pjob);
}

int 			sh_jc_add(t_jcon *jc, int bg)
{
	t_job	*new_job;
	t_list	*jlast;

	DF0;
	if (!jc && ft_printf("JC NULL\n"))
		return (KO);
	if (!jc->jobs)
		jc->cind = 1;
	else
		jc->cind++;
	new_job = sh_jc_new_job(jc->cind, bg);
	jlast = ft_lstnew(new_job, sizeof(t_job));
	ft_lst_addlast(&(jc->jobs), jlast);
	jc->cjob = (t_job*)jlast->content;
	FT_MEMDEL(new_job);
	return (0);
}

int 			sh_jc_wait(t_jcon *jc, t_job *job)
{
	int wstatus;
	pid_t pid;

	DF0;
	pid = waitpid(WAIT_ANY, &wstatus, WUNTRACED); // TODO: WAIT_ANY
	ft_printf("----> pid got from wait: %d\n", pid);
	while (!sh_jc_mark_status(jc, pid, wstatus)
		   && !sh_jc_is_stop(job)
		   && !sh_jc_is_done(job))
		pid = waitpid (WAIT_ANY, &wstatus, WUNTRACED);
	return (OK);
}
