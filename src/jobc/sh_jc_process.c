/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_jc_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 19:13:50 by abbesbes          #+#    #+#             */
/*   Updated: 2019/10/07 19:13:52 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftsh.h"

void			sh_jcp_print(t_process *p)
{
	if (!p)
		return;
	ft_printf(C_YLW"-> process: pid=%d | stat=%d | d(%d) s(%d)\n"T_END,
			p->pid, p->status, p->done, p->stopped);
}


void			sh_jcp_lstput(t_list *plist)
{
	if (!plist)
		return ;
	ft_putchar('\n');
	sh_jcp_print((t_process*)plist->content);
}
