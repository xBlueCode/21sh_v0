/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_e_simp_cmd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 19:07:41 by abbesbes          #+#    #+#             */
/*   Updated: 2019/10/07 19:07:44 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftsh.h"
#include <sys/wait.h>

int		sh_e_simp_cmd(t_sh *sh, void *gr)
{
	t_simp_cmd	*simp_cmd;
	int			ret;

	DF0;
	if ((ret = 0) || !sh || !gr)
		return (0);
	simp_cmd = (t_simp_cmd*)gr;
	sh_xp_word(sh, simp_cmd->lst_words);
	sh_xp_assign(sh, simp_cmd->lst_assign);
	if (!(simp_cmd->argv = sh_e_get_argv(sh, simp_cmd->lst_words)))
	{
		sh_var_assign(sh->var, simp_cmd->lst_assign);
		return (0);
	}
	simp_cmd->envp = sh_e_get_envp(sh, simp_cmd->lst_assign);
	if (sh_e_check_built(simp_cmd->argv[0]) != -1)
		return (sh_e_run_built(sh, simp_cmd));
	if ((ret = sh_e_check_exec(simp_cmd->argv[0])) == OK)
		return (sh_e_run_exec(sh, simp_cmd));
	return (ret);
}

int		sh_e_simp_cmd_wait(t_sh *sh, void *gr, int op, int *state)
{
	t_simp_cmd	*simp_cmd;
	int			wstat;

	DF0;
	if (!sh || !gr)
		return (-1);
	simp_cmd = (t_simp_cmd*)gr;
	waitpid(simp_cmd->pid, &wstat, op);
	if (WIFEXITED(wstat) || WIFSIGNALED(wstat))
		*state = SH_E_STATE_DONE;
	simp_cmd->state = *state;
	simp_cmd->wstat = wstat;
	return (WEXITSTATUS(simp_cmd->wstat));
}

int		sh_e_simp_cmd_kill(t_sh *sh, void *gr, int sig)
{
	t_simp_cmd	*simp_cmd;

	DF0;
	if (!sh || !gr)
		return (-1);
	simp_cmd = (t_simp_cmd*)gr;
	if (simp_cmd->pid > 0)
		return (kill(simp_cmd->pid, sig));
	else if (BIT_IS(sh->mode, SH_MODE_SCMD))
		return (kill(simp_cmd->pid, sig));
	return (-1);
}
