/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_e.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 19:07:22 by abbesbes          #+#    #+#             */
/*   Updated: 2019/10/07 19:07:25 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftsh.h"

int		sh_e_com_cmds(t_sh *sh, void *gr)
{
	t_com_cmds	*com_cmds;
	t_list		*com_cmd;
	int			ret;

	DF0;
	if (!sh || !gr)
		return (0);
	com_cmds = (t_com_cmds*)gr;
	com_cmd = com_cmds->lst_com_cmd;
	ret = 0;
	while (com_cmd)
	{
		ret = sh_e_com_cmd(sh, com_cmd->content);
		com_cmd = com_cmd->next;
	}
	return (ret);
}

int		sh_e_com_cmd(t_sh *sh, void *gr)
{
	t_list		*and_or_lst;
	t_com_cmd	*com_cmd;
	t_sh		*nsh;
	int			ret;

	DF0;
	if ((ret = 0) || !sh || !gr)
		return (0);
	com_cmd = (t_com_cmd*)gr;
	and_or_lst = com_cmd->lst_and_or;
	nsh = (com_cmd->gr == SH_GR_SUBSH) ? sh_sh_clone(sh, SH_MODE_SSH) : NULL;
	while (and_or_lst)
	{
		if (!nsh)
			sh_jc_add(sh->jc, ft_dstrget_ch(com_cmd->sep, 0) == TSA);
		ft_dstrdel_n(com_cmd->sep, 0, 1);
		ret = sh_e_and_or(nsh ? nsh : sh, and_or_lst->content);
		if (sh->jc->cjob->bg)
			sh_jcj_print(sh->jc->cjob);
		and_or_lst = and_or_lst->next;
	}
	sh_sh_free(&nsh);
	return (ret);
}

int		sh_e_and_or(t_sh *sh, void *gr)
{
	t_and_or	*and_or;
	t_list		*pipe_lst;
	int			ret;
	int			sep_ao;
	char		*strret;

	DF0;
	if ((ret = 0) || !sh || !gr)
		return (0);
	and_or = (t_and_or*)gr;
	pipe_lst = and_or->lst_pipe;
	while (pipe_lst)
	{
		sep_ao = ft_dstrget_ch(and_or->sep, 0);
		ft_dstrdel_n(and_or->sep, 0, 1);
		ret = sh_e_pipe(sh, pipe_lst->content);
		strret = ft_itoa(ret);
		ft_tabins(sh->var, ft_tabrow_set(-1, "?", strret, SH_VO_ESTAT), 1);
		FT_MEMDEL(strret);
		pipe_lst = pipe_lst->next;
		if (((ret && sep_ao == TSA2) || (!ret && sep_ao == TSO2)) && pipe_lst)
			pipe_lst = pipe_lst->next;
	}
	return (ret);
}

int		sh_e_com_cmd_wait(t_sh *sh, void *gr, int op, int *state)
{
	(void)sh;
	(void)gr;
	(void)op;
	(void)state;
	return (0);
}

int		sh_e_com_cmd_kill(t_sh *sh, void *gr, int sig)
{
	(void)sh;
	(void)gr;
	(void)sig;
	return (0);
}
