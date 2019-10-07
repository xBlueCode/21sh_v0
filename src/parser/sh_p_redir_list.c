/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_p_redir_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 19:29:32 by abbesbes          #+#    #+#             */
/*   Updated: 2019/10/07 19:29:34 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftsh.h"

int		sh_p_redir_list(t_parser *p, t_btree **ast)
{
	t_btree *cast;

	DP0
	SHP_CAST_INIT(SH_GR_REDIR_LIST)
	if (sh_p_io_redir(p, SHP_CAST_L) && sh_p_redir_list_sub(p, SHP_CAST_R))
		PRET(1);
	PRET(0);
}

int		sh_p_redir_list_sub(t_parser *p, t_btree **ast)
{
	t_list	*back;
	t_btree *cast;

	DP0
	SHP_CAST_INIT(SH_GR_REDIR_LIST_SUB)
	if (!(back = p->tlook))
		PRET(1)
	if (sh_p_io_redir(p, SHP_CAST_L) && sh_p_redir_list_sub(p, SHP_CAST_R))
		PRET(1)
	p->tlook = back;
	PRET(1)
}
