/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_jc_notify.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 19:13:48 by abbesbes          #+#    #+#             */
/*   Updated: 2019/10/07 19:13:50 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftsh.h"


int 			sh_jc_notify(t_jcon *jc)
{
	t_list	*jlist;
	t_list	*jnext;
	t_job	*cjob;

	DF0;
	sh_jc_update_status(jc);
	jlist = jc->jobs;
	while (jlist)
	{
		jnext = jlist->next;
		cjob = (t_job*)jlist->content;
		if (sh_jc_is_done(cjob))
		{
			if (cjob->bg)
				sh_jc_inform(cjob, 2);
			ft_lst_freeif(&jc->jobs, (int(*)(void*))&sh_jc_is_done, &sh_jc_free_job);
		}
		else if (sh_jc_is_stop(cjob) && !cjob->notified)
		{
			sh_jc_inform(cjob, 1);
			cjob->notified = 1;
		}
		jlist = jnext;
	}
	return (OK);
}

int 			sh_jc_inform(t_job *job, int info)
{
	if (!job)
		return (KO);
	ft_dprintf(2, C_MGN"JOB[%d] (%d) : %d\n"T_END, job->ind, job->pgid, info);
	ft_lstiter(job->process, &sh_jcp_lstput);
	return (OK);
}

int 			sh_jc_update_status(t_jcon *jc)
{
	int		wstatus;
	pid_t 	pid;

	DF0;
	pid = waitpid(WAIT_ANY, &wstatus, WUNTRACED | WNOHANG);
	ft_printf("-------> update status: %d\n", pid);
	while (!sh_jc_mark_status(jc, pid, wstatus))
		pid = waitpid(WAIT_ANY, &wstatus, WUNTRACED | WNOHANG);
	return (OK);
}
