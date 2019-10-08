/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_p_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 19:28:56 by abbesbes          #+#    #+#             */
/*   Updated: 2019/10/07 19:28:58 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftsh.h"

int				sh_p_cmd(t_parser *p, t_btree **ast)
{
	t_list	*back;
	t_btree *cast;

	DP0;
	SHP_CAST_INIT(SH_GR_CMD);
	back = p->tlook;
	if (sh_p_comp_cmd(p, SHP_CAST_L))
	{
		sh_p_redir_list(p, SHP_CAST_R);
		PRET(1);
	}
	p->tlook = back;
	if (sh_p_simp_cmd(p, SHP_CAST_L))
		PRET(1);
	PRET(0);
}

int				sh_p_comp_cmd(t_parser *p, t_btree **ast)
{
	t_btree *cast;

	DP0;
	SHP_CAST_INIT(SH_GR_COMP_CMD);
	if (sh_p_cb_group(p, SHP_CAST_L))
		PRET(1);
	if (sh_p_subsh(p, SHP_CAST_L))
		PRET(1);
	if (sh_p_for_clause(p, SHP_CAST_L))
		PRET(1);
	if (sh_p_while_clause(p, SHP_CAST_L))
		PRET(1);
	if (sh_p_until_clause(p, SHP_CAST_L))
		PRET(1);
	if (sh_p_if_clause(p, SHP_CAST_L))
		PRET(1);
	PRET(0);
}
