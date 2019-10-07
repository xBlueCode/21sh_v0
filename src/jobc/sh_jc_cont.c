/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_jc_cont.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 19:13:44 by abbesbes          #+#    #+#             */
/*   Updated: 2019/10/07 19:13:47 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftsh.h"

int				sh_jc_mark_as_running(t_job *job)
{
	t_list		*plist;
	t_process	*p;

	DF0
	if (!job)
		return (KO);
	plist = job->process;
	while (plist)
	{
		p = (t_process*)plist->content;
		if (!p)
			continue;
		p->stopped = 0;
	}
	job->notified = 0;
	return (OK);
}

int				sh_jc_continue(t_sh *sh, t_job *job)
{
	sh_jc_mark_as_running(job);
	if (job->bg)
		sh_jc_put_in_back(sh, 1);
	else
		sh_jc_put_in_forg(sh, 1);
}
