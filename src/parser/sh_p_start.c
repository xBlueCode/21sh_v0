/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_p_start.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 19:29:38 by abbesbes          #+#    #+#             */
/*   Updated: 2019/10/07 19:29:40 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftsh.h"

void		sep(t_list *e)
{
	t_com_cmd com_cmd;

	ft_printf("sep\n");
	if (!e)
		ft_printf("ELEM NULL\n");
	com_cmd = *((t_com_cmd*)(e->content));
	if (!e->content)
		ft_printf("content NULL\n");
	else if (!com_cmd.sep)
		ft_printf("sep NULL");
	else if (!com_cmd.sep->str)
		ft_printf("sep->str NULL");
	else
		ft_putendl(com_cmd.sep->str);
}

t_com_cmds	*sh_p_start(t_lex *lex)
{
	t_parser	p;
	t_btree		*ast;
	t_com_cmds	*com_cmds;

	DF0;
	p.tlook = lex->tlst;
	p.hd_val = lex->hd_val;
	p.lev = 0;
	ft_btreeinit(&ast, NULL, 0, SH_GR_START);
	sh_p_program(&p, &(ast->left));
	if (p.tlook && p.tlook->content)
	{
		ft_printf(C_RED"\nParsing Error at: %d\n"T_END,
			(((t_token*)p.tlook->content)->p));
		DPTOKPUT(((t_token*)p.tlook->content));
		ft_btreefree(&ast, (t_free) & sh_lex_tok_tfree);
	}
	else
	{
		if (!ast || !ast->left || !ast->left->left)
			FT_INST_RET(NULL, ft_btreefree(&ast, (t_free) & sh_lex_tok_tfree));
		com_cmds = sh_g_com_cmds(ast->left->left);
		ft_btreefree(&ast, (t_free) & sh_lex_tok_tfree);
		return (com_cmds);
	}
	return (NULL);
}
