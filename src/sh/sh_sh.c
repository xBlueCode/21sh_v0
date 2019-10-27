/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_sh.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 19:32:10 by abbesbes          #+#    #+#             */
/*   Updated: 2019/10/07 19:32:13 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftsh.h"
#include <signal.h>

extern t_sh	*g_sh;

t_sh		*sh_sh(void)
{
	return (g_sh);
}

static int	sh_sh_init_inter(t_sh *sh)
{
	while (tcgetpgrp((sh)->term_std) != ((sh)->pgid = getpgrp()))
		kill(-(sh)->pgid, SIGTTIN);
	(sh)->pgid = getpid();
	if (setpgid((sh)->pgid, (sh)->pgid) < 0)
	{
		ft_printf("Couldn't put the shell in its own process group !\n");
		exit(1);
	}
	sh_termconfig_init(&(sh)->term);
	return (0);
}

int			sh_sh_init(t_sh **sh, char **envp, int mode)
{
	if (!sh)
		return (KO);
	DF0;
	*sh = ft_memalloc(sizeof(t_sh));
	(*sh)->mode = mode;
	(*sh)->jc = sh_jc_new();
	(*sh)->pgid = 0;
	(*sh)->term_std = STDERR_FILENO;
	(*sh)->inter = isatty((*sh)->term_std);
	sh_var_start(&(*sh)->var, envp);
	sh_bin_init(&(*sh)->bin_ht, &(*sh)->bin_nl);
	sh_bin_update((*sh)->bin_ht,
			(*sh)->bin_nl, sh_var_getval((*sh)->var, "PATH"));
	(*sh)->nest = 0;
	if (BIT_IS(mode, SH_MODE_TER) && (*sh)->inter)
		sh_sh_init_inter(*sh);
	(*sh)->sub_pipe = NULL;
	(*sh)->sub_out = NULL;
	(*sh)->quit = 0;
	return (OK);
}

t_sh		*sh_sh_clone(t_sh *sh, int mode)
{
	t_sh	*nsh;

	if (!sh)
		return (NULL);
	nsh = ft_memalloc(sizeof(t_sh));
	if (mode == SH_MODE_SSH || mode == SH_MODE_SCMD)
	{
		nsh->mode = sh->mode;
		BIT_MSET(nsh->mode, SH_MODE_M, mode);
		nsh->jc = NULL;
		nsh->var = ft_tabdup(sh->var);
		nsh->inter = 0;
		nsh->nest = sh->nest;
		nsh->bin_ht = sh->bin_ht;
		nsh->bin_nl = sh->bin_nl;
		if (mode == SH_MODE_SCMD)
		{
			nsh->sub_pipe = ft_memalloc(2 * sizeof(int));
			nsh->sub_out = ft_dstrnew_max(2);
		}
	}
	return (nsh);
}

int			sh_sh_free(t_sh **sh)
{
	if (!sh || !*sh)
		return (1);
	if (!BIT_IS((*sh)->mode, SH_MODE_SSH) && !BIT_IS((*sh)->mode, SH_MODE_SCMD))
	{
		ft_hset_free(&(*sh)->bin_ht);
		ft_dastrfree(&(*sh)->bin_nl);
	}
	ft_tabfree(&(*sh)->var);
	FT_MEMDEL((*sh)->sub_pipe);
	ft_dstrfree(&(*sh)->sub_out);
	FT_MEMDEL(*sh);
	return (0);
}
