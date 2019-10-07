/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_g_group.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 19:13:23 by abbesbes          #+#    #+#             */
/*   Updated: 2019/10/07 19:13:25 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftsh.h"

void			*sh_g_group(t_btree *ast)
{
	t_com_cmd	*group;

	if (!ast || (ast->op != SH_GR_SUBSH && ast->op != SH_GR_CB_GROUP
		&& ast->op != SH_GR_DO_GROUP))
		return (NULL);
	if (!(group = sh_g_com_cmd(ast->left)))
		return (NULL);
	group->gr = ast->op;
	return (group);
}
