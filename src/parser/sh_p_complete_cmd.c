/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_p_complete_cmd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 19:29:06 by abbesbes          #+#    #+#             */
/*   Updated: 2019/10/07 19:29:07 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftsh.h"

int		sh_p_complete_cmds(t_parser *p, t_btree **ast)
{
	t_btree *cast;

	DF0;
	DP0;
	SHP_CAST_INIT(SH_GR_COMPLETE_CMDS);
	if (sh_p_complete_cmd(p, SHP_CAST_L)
		&& sh_p_complete_cmds_sub(p, SHP_CAST_R))
	{
		PRET(1);
	}
	PRET(0);
}

int		sh_p_complete_cmds_sub(t_parser *p, t_btree **ast)
{
	t_btree *cast;

	DP0;
	SHP_CAST_INIT(SH_GR_COMPLETE_CMDS_SUB);
	if (!p->tlook)
		PRET(1);
	if (sh_p_nl_list(p, NULL))
	{
		if (sh_p_complete_cmd(p, SHP_CAST_L))
		{
			if (sh_p_complete_cmds_sub(p, SHP_CAST_R))
				PRET(1);
			PRET(1);
		}
		PRET(1);
	}
	PRET(1);
}

int		sh_p_complete_cmd(t_parser *p, t_btree **ast)
{
	t_btree *cast;

	DF0;
	DP0;
	SHP_CAST_INIT(SH_GR_COMPLETE_CMD);
	if (sh_p_list(p, SHP_CAST_L))
	{
		if (sh_p_sep_op(p, SHP_CAST_R))
			PRET(1);
		PRET(1);
	}
	PRET(0);
}
