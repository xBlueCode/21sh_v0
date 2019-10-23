/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_g_com_cmd2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 21:43:45 by abbesbes          #+#    #+#             */
/*   Updated: 2019/10/20 21:43:47 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftsh.h"

void			*sh_g_com_cmds_new(void)
{
	t_com_cmds	*com_cmds;

	SHG_CHECK_MALL(com_cmds);
	com_cmds->lst_com_cmd = NULL;
	return (com_cmds);
}

void			*sh_g_com_cmd_new(void)
{
	t_com_cmd	*com_cmd;

	SHG_CHECK_MALL(com_cmd);
	com_cmd->lst_and_or = NULL;
	com_cmd->sep = ft_dstrnew_max(2);
	com_cmd->gr = -1;
	return (com_cmd);
}

void			sh_g_com_cmds_free(void **g)
{
	t_com_cmds	**com_cmds;

	com_cmds = (t_com_cmds**)g;
	ft_lst_free(&(*com_cmds)->lst_com_cmd, &sh_g_com_cmd_free);
	FT_MEMDEL(*g);
}

void			sh_g_com_cmd_free(void **g)
{
	t_com_cmd	**com_cmd;

	com_cmd = (t_com_cmd**)g;
	ft_lst_free(&(*com_cmd)->lst_and_or, &sh_g_and_or_free);
	ft_dstrfree(&(*com_cmd)->sep);
	FT_MEMDEL(*g);
}
