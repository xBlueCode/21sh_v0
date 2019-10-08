/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_jc_state.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 19:13:56 by abbesbes          #+#    #+#             */
/*   Updated: 2019/10/07 19:13:58 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftsh.h"

int 			sh_jc_is_stop(t_job *job)
{
	t_list		*plist;
	t_process	*process;

	DF0;
	ft_printf(C_RED"job in %s is %s\n"T_END, __FUNCTION__, !job ? "0" : "1");
	if (!job || !job->process)
		return (1);
	plist = job->process;
	ft_printf(C_RED"job [%d](%d) ==> plist %s\n"T_END, job->ind, job->pgid,
			!plist ? "NULL" : "NOT-NULL");
	while (plist)
	{
		process = (t_process*) plist->content;
		sh_jcp_print(process);
		if (!process->done && !process->stopped)
			return (0);
		plist = plist->next;
	}
//	job->stopped = 1;
	return (1);
}

int 			sh_jc_is_done(t_job *job)
{
	t_list		*plist;
	t_process	*process;

	DF0;
	ft_printf(C_RED"job in %s is %s\n"T_END, __FUNCTION__, !job ? "0" : "1");
	if (!job)
		return (1);
	plist = job->process;
	ft_printf(C_RED"job [%d](%d) ==> plist %s\n"T_END, job->ind, job->pgid,
			  !plist ? "NULL" : "NOT-NULL");
	while (plist)
	{
		process = (t_process*) plist->content;
		sh_jcp_print(process);
		if (!process->done)
			return (0);
		plist = plist->next;
	}
	job->done = 1;
	return (1);
}

int 			sh_jc_mark_status(t_jcon *jc, pid_t pid, int status)
{
	t_list		*jlist;
	t_job		*j;
	t_list		*plist;
	t_process	*p;

	DF0;
	if (!jc || !jc->jobs)
		return (-1);
	jlist = jc->jobs;
	while (jlist)
	{
		if (!(j = (t_job*)jlist->content))
			continue;
		plist = j->process;
		ft_printf("_____ Updating processes for %d | p %d\n",
				j->ind, !plist ? 0 : 1);
		while (plist)
		{
			//if (!(p = (t_process*)plist->content) || p->pid != pid)
			p = (t_process*)plist->content;
			ft_printf("p->pid=%d || pid=%d\n", p->pid, pid);
			if (p->pid != pid)
			{
				plist = plist->next;
				continue;
			}
			else if (WIFSTOPPED(status))
				p->stopped = 1;
			else
			{
				ft_printf(C_MGN"Marking process as done !\n"T_END);
				p->done = 1;
				if (WIFSIGNALED(status))
					ft_printf("%d: Terminated by signal %d.\n",
							(int) pid, WTERMSIG (p->status));
			}
			p->status = status;
			ft_printf(C_RED"process marked !"T_END);
			sh_jcp_print(p);
			return (0);
		}
		jlist = jlist->next;
	}
	return (-1);
}

int				sh_jc_get_done(t_job *job)
{
	if (!job)
		return (-1);
	return (job->done);
}
