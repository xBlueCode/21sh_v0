/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_p_sep.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 19:29:34 by abbesbes          #+#    #+#             */
/*   Updated: 2019/10/07 19:29:36 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftsh.h"

int		sh_p_sep_op(t_parser *p, t_btree **ast)
{
	t_btree *cast;

	DP0;
	SHP_CAST_INIT(SH_GR_SEP_OP);
	if (sh_p_match(p, &cast, TSA) || sh_p_match(p, &cast, TSSC))
		PRET(1);
	PRET(0);
}

int		sh_p_sep(t_parser *p, t_btree **ast)
{
	t_btree *cast;
	t_btree *fast;

	DP0;
	SHP_CAST_INIT(SH_GR_SEP);
	fast = NULL;
	if (sh_p_sep_op(p, &fast))
	{
		cast->data = sh_lex_tokdup(SHG_AST_TOK(fast));
		cast->dsize = fast->dsize;
		ft_btreefree(&fast, (t_free) & sh_lex_tok_tfree);
		if (sh_p_lbreak(p, NULL))
			PRET(1);
	}
	else if (sh_p_nl_list(p, NULL))
		PRET(1);
	PRET(0);
}

int		sh_p_seq_sep(t_parser *p, t_btree **ast)
{
	t_btree *cast;

	DP0;
	SHP_CAST_INIT(SH_GR_SEQ_SEP);
	if ((sh_p_match(p, &cast, TSSC) && sh_p_lbreak(p, NULL))
		|| sh_p_nl_list(p, NULL))
		PRET(1);
	PRET(0);
}
