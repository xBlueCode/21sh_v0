/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_p_lbreak.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 19:29:19 by abbesbes          #+#    #+#             */
/*   Updated: 2019/10/07 19:29:22 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftsh.h"

int		sh_p_nl_list(t_parser *p, t_btree **ast)
{
	t_btree *cast;

	DP0
	SHP_CAST_INIT(SH_GR_NL_LIST)
	if (sh_p_match(p, NULL, TSNL) && sh_p_nl_list_sub(p, NULL))
		PRET(1);
	PRET(0);
}

int		sh_p_nl_list_sub(t_parser *p, t_btree **ast)
{
	t_list	*back;
	t_btree *cast;

	DP0
	SHP_CAST_INIT(SH_GR_LIST_SUB)
	if (!(back = p->tlook))
		PRET(1)
	if (sh_p_match(p, NULL, TSNL))
	{
		if (sh_p_nl_list_sub(p, NULL))
			PRET(1)
		PRET(1)
	}
	p->tlook = back;
	PRET(1);
}

int		sh_p_lbreak(t_parser *p, t_btree **ast)
{
	t_btree *cast;

	DP0
	SHP_CAST_INIT(SH_GR_LBREAK)
	if (!p->tlook)
		PRET(1)
	if (sh_p_nl_list(p, NULL))
		PRET(1)
	PRET(1)
}
