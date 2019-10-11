/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_p_simp_cmd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 19:29:36 by abbesbes          #+#    #+#             */
/*   Updated: 2019/10/07 19:29:38 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftsh.h"

static int	sh_p_simp_cmd_norm(t_parser *p, t_btree **ast,
		t_btree *cast, t_btree **fast)
{
	t_list	*back;

	back = p->tlook;
	cast->data = sh_lex_tokdup(SHG_AST_TOK(*fast));
	cast->dsize = (*fast)->dsize;
	ft_btreefree(fast, (t_free) & sh_lex_tok_tfree);
	if (sh_p_cmd_suff(p, SHP_CAST_R))
		PRET(1);
	p->tlook = back;
	PRET(1);
}

int			sh_p_simp_cmd(t_parser *p, t_btree **ast)
{
	t_list	*back0;
	t_list	*back1;
	t_btree *cast;
	t_btree *fast;

	DF0;
	DP0;
	SHP_CAST_INIT(SH_GR_SIMP_CMD);
	fast = NULL;
	back0 = p->tlook;
	if (sh_p_cmd_pref(p, SHP_CAST_L))
	{
		back1 = p->tlook;
		if (sh_p_cmd_word(p, &fast))
			return (sh_p_simp_cmd_norm(p, ast, cast, &fast));
		ft_btreefree(&fast, (t_free) & sh_lex_tok_tfree);
		p->tlook = back1;
		PRET(1);
	}
	p->tlook = back0;
	if (sh_p_cmd_name(p, &fast))
		return (sh_p_simp_cmd_norm(p, ast, cast, &fast));
	PRET(0);
}

int			sh_p_cmd_name(t_parser *p, t_btree **ast)
{
	t_btree *cast;

	DP0;
	SHP_CAST_INIT(SH_GR_CMD_NAME);
	if (sh_p_match(p, &cast, SH_GR_CMD_NAME))
		PRET(1);
	PRET(0);
}

int			sh_p_cmd_word(t_parser *p, t_btree **ast)
{
	t_btree *cast;

	DP0;
	SHP_CAST_INIT(SH_GR_CMD_WORD);
	if (sh_p_match(p, &cast, SH_GR_CMD_WORD))
		PRET(1);
	PRET(0);
}
