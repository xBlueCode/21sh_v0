/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_p_program.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 19:29:30 by abbesbes          #+#    #+#             */
/*   Updated: 2019/10/07 19:29:32 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftsh.h"

int				sh_p_program(t_parser *p, t_btree **ast)
{
	t_btree *cast;

	p_lev = 0;
	DF0;
	DP0;
	SHP_CAST_INIT(SH_GR_PROGRAM);
	if (!sh_p_lbreak(p, NULL))
		PRET(0);
	if (sh_p_complete_cmds(p, SHP_CAST_L))
	{
		if (sh_p_lbreak(p, NULL))
			PRET(1);
		PRET(1);
	}
	PRET(0);
}
