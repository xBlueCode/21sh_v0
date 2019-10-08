/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_p_ifelse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 19:29:14 by abbesbes          #+#    #+#             */
/*   Updated: 2019/10/07 19:29:16 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftsh.h"

int				sh_p_if_clause(t_parser *p, t_btree **ast)
{
	t_btree *cast;

	DP0;
	if (!sh_p_match(p, NULL, TSRW_IF))
		PRET(0);
	SHP_CAST_INIT(SH_GR_IF_CLAUSE);
	if (!sh_p_comp_list(p, SHP_CAST_L))
		PRET(0);
	if (!sh_p_ifbody(p, SHP_CAST_R))
		PRET(0);
	if (!sh_p_match(p, NULL, TSRW_FI))
		PRET(0);
	PRET(1);
}

int				sh_p_else_part(t_parser *p, t_btree **ast)
{
	t_btree *cast;

	DP0;
	if (!sh_p_match(p, NULL, TSRW_ELIF) && !sh_p_match(p, NULL, TSRW_ELSE))
		PRET(0);
	SHP_CAST_INIT(SH_GR_ELSE_PART);
	if (!sh_p_comp_list(p, SHP_CAST_L))
		PRET(0);
	sh_p_ifbody(p, SHP_CAST_R);
	PRET(1);
}

int				sh_p_ifbody(t_parser *p, t_btree **ast)
{
	t_btree *cast;

	DP0;
	if (!sh_p_match(p, NULL, TSRW_THEN))
		PRET(0);
	SHP_CAST_INIT(SH_GR_IFBODY);
	if (!sh_p_comp_list(p, SHP_CAST_L))
		PRET(0);
	sh_p_else_part(p, SHP_CAST_R);
	PRET(1);
}
