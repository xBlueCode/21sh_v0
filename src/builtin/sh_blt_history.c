/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_blt_history.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 19:59:16 by abbesbes          #+#    #+#             */
/*   Updated: 2019/10/27 19:59:17 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftsh.h"

int			sh_blt_history(t_sh *sh, char **argv, char **envp)
{
	(void)(sh);
	(void)argv;
	(void)envp;
	rl_hist_print();
	return (OK);
}
