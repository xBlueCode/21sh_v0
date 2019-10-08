/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_p_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 19:29:24 by abbesbes          #+#    #+#             */
/*   Updated: 2019/10/07 19:29:26 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftsh.h"

int		sh_p_list(t_parser *p, t_btree **ast)
{
	t_btree *cast;

	DP0;
	SHP_CAST_INIT(SH_GR_LIST);
	if (sh_p_and_or(p, SHP_CAST_L) && sh_p_list_sub(p, SHP_CAST_R))
		PRET(1);
	PRET(0);
}

int		sh_p_list_sub(t_parser *p, t_btree **ast)
{
	t_btree	*cast;
	t_btree	*fast;
	t_list	*back;

	DP0;
	SHP_CAST_INIT(SH_GR_LIST_SUB);
	if (!(back = p->tlook))
		PRET(1);
	fast = NULL;
	if (sh_p_sep_op(p, &fast))
	{
		cast->data = sh_lex_tokdup(SHG_AST_TOK(fast));
		cast->dsize = fast->dsize;
		ft_btreefree(&fast, (t_free) & sh_lex_tok_tfree);
		if (sh_p_and_or(p, SHP_CAST_L) && sh_p_list_sub(p, SHP_CAST_R))
			PRET(1);
		p->tlook = back;
		PRET(1);
	}
	PRET(1);
}
