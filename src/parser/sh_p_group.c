/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_p_group.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 19:29:12 by abbesbes          #+#    #+#             */
/*   Updated: 2019/10/07 19:29:14 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftsh.h"

int		sh_p_cb_group(t_parser *p, t_btree **ast)
{
	t_btree *cast;

	DP0;
	SHP_CAST_INIT(SH_GR_CB_GROUP);
	if (sh_p_match(p, NULL, TSCBL)
		&& sh_p_comp_list(p, SHP_CAST_L)
		&& sh_p_match(p, NULL, TSCBR))
		PRET(1);
	PRET(0);
}

int		sh_p_do_group(t_parser *p, t_btree **ast)
{
	t_btree *cast;

	DP0;
	SHP_CAST_INIT(SH_GR_DO_GROUP);
	if (sh_p_match(p, NULL, TSRW_DO)
		&& sh_p_comp_list(p, SHP_CAST_L)
		&& sh_p_match(p, NULL, TSRW_DONE))
		PRET(1);
	PRET(0);
}
