/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftsh_inter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 18:24:29 by abbesbes          #+#    #+#             */
/*   Updated: 2019/10/27 18:24:30 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftsh.h"
#include <fcntl.h>

t_sh	*g_sh;

int		sh_valid_stdin(void)
{
	int		c;

	if (read(STDIN_FILENO, &c, 0) < 0)
		return (KO);
	return (OK);
}

int		sh_term_run_prep(char **envp)
{
	if (sh_sh_init(&g_sh, envp, SH_MODE_TER) != OK)
		exit(1);
	rl_hist_init(RL_HIS_FILENAME);
	rl_hist_upload();
	sh_als_init();
	rl_hist_print();
	return (OK);
}
