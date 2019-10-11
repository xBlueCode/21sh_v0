/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_p_and_or.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 19:28:52 by abbesbes          #+#    #+#             */
/*   Updated: 2019/10/07 19:28:54 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftsh.h"

int		sh_p_and_or(t_parser *p, t_btree **ast)
{
	t_btree *cast;

	DF0;
	DP0;
	SHP_CAST_INIT(SH_GR_AND_OR);
	if (sh_p_pipeline(p, SHP_CAST_L) && sh_p_and_or_sub(p, SHP_CAST_R))
		PRET(1);
	PRET(0);
}

int		sh_p_and_or_sub(t_parser *p, t_btree **ast)
{
	t_list	*back;
	t_btree *cast;

	DP0;
	SHP_CAST_INIT(SH_GR_AND_OR_SUB);
	if (!(back = p->tlook))
		PRET(1);
	if (sh_p_match(p, &cast, TSA2))
	{
		if (sh_p_lbreak(p, NULL) && sh_p_pipeline(p, SHP_CAST_L)
			&& sh_p_and_or_sub(p, SHP_CAST_R))
			PRET(1);
		PRET(0);
	}
	if (sh_p_match(p, &cast, TSO2))
	{
		if (sh_p_lbreak(p, NULL) && sh_p_pipeline(p, SHP_CAST_L)
			&& sh_p_and_or_sub(p, SHP_CAST_R))
			PRET(1);
		PRET(0);
	}
	PRET(1);
}
