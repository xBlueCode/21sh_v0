/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_p_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 19:29:45 by abbesbes          #+#    #+#             */
/*   Updated: 2019/10/07 19:29:46 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftsh.h"

extern int	g_btreeapp_lev;

int		sh_p_lookshift(t_parser *p)
{
	(void)p;
	return (0);
}

void	test_sh_p_astapp(t_btree *root)
{
	int i;

	if (!root)
		return ;
	i = -1;
	while (++i < g_btreeapp_lev)
		ft_printf("%s |"T_END, i % 2 ? C_GRN : C_RED);
	ft_printf("- GR(%03d): ", root->op);
	ft_printf(C_CYN"  L (%03d) "T_END, root->left ? root->left->op : 0);
	ft_putstr(" | ");
	ft_printf(C_MGN" R (%03d)"T_END, root->right ? root->right->op : 0);
	if (root->data && ft_printf(" | "))
	{
		DPTOKPUT(((t_token*)root->data));
	}
	else
		ft_putendl("");
}

int		sh_p_match(t_parser *p, t_btree **ast, int target)
{
	t_token *token;

	DF0;
	DPM0;
	if (!p->tlook || !(token = (t_token*)p->tlook->content))
		PMRET(0);
	if (token->t == TSTOK)
	{
		if (!sh_tok_distinct(p->tlook->content, target))
			PMRET(0);
	}
	else if (((t_token*)p->tlook->content)->t != target)
		PMRET(0);
	if (ast && *ast)
	{
		sh_lex_tok_free((t_token**)&(*ast)->data);
		(*ast)->data = sh_lex_tokdup(token);
		(*ast)->dsize = sizeof(t_token);
	}
	DPM1;
	p->tlook = p->tlook->next;
	PMRET(1);
}
