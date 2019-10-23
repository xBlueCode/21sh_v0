/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_e_pipe_kwait.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 19:17:29 by abbesbes          #+#    #+#             */
/*   Updated: 2019/10/20 19:17:36 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftsh.h"

int			sh_e_cmd_wait(t_sh *sh, void *gr, int op, int *state)
{
	t_cmd	*cmd;

	DF0;
	if (!gr || !sh)
		return (0);
	cmd = (t_cmd*)gr;
	return (cmd->wait(sh, cmd->core, op, state));
}

int			sh_e_cmd_kill(t_sh *sh, void *gr, int sig)
{
	t_cmd	*cmd;

	DF0;
	if (!gr)
		return (0);
	cmd = (t_cmd*)gr;
	return (cmd->kill(sh, cmd->core, sig));
}
