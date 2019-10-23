/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_g_simp_cmd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 19:13:33 by abbesbes          #+#    #+#             */
/*   Updated: 2019/10/07 19:13:36 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftsh.h"

extern int		g_g_putlev;

static void		sh_g_simp_cmd_prefsuff(t_simp_cmd *simp_cmd, t_btree *fix)
{
	t_token	*tok;
	t_redir	*redir;

	if (!simp_cmd || !fix)
		return ;
	while (fix)
	{
		if (fix->data)
		{
			tok = SHG_AST_TOK(fix);
			if (tok->t == TSTOK_WORD)
				ft_dastrins_str(simp_cmd->lst_words, -1, tok->val->str);
			else if (tok->t == TSTOK_ASS_WORD)
				ft_dastrins_str(simp_cmd->lst_assign, -1, tok->val->str);
		}
		if (fix->left && (redir = sh_g_redir(fix->left)))
			SHG_LSTADD_FREE(simp_cmd, lst_redir, redir);
		fix = fix->right;
	}
}

void			sh_g_wordput(t_list *elem)
{
	t_dstr *dstr;

	if (!elem)
		return ;
	g_g_putlev++;
	dstr = (t_dstr*)elem->content;
	if (dstr->str)
	{
		SHG_PUT_PRINTF(dstr->str, g_g_putlev);
		ft_putchar('\n');
	}
	g_g_putlev--;
}

void			*sh_g_simp_cmd(t_btree *ast)
{
	t_simp_cmd	*simp_cmd;

	simp_cmd = sh_g_simp_cmd_new();
	if (ast->data)
		ft_dastrins_str(simp_cmd->lst_words, -1, SHG_AST_TOK(ast)->val->str);
	sh_g_simp_cmd_prefsuff(simp_cmd, ast->left);
	sh_g_simp_cmd_prefsuff(simp_cmd, ast->right);
	if (!simp_cmd->lst_words)
		return (NULL);
	return (simp_cmd);
}

void			sh_g_simp_cmd_put(void *g, int op)
{
	t_simp_cmd *simp_cmd;

	if (!g)
		return ;
	g_g_putlev++;
	SHG_PUT_CASTVAR(simp_cmd, g, t_simp_cmd*, op);
	SHG_PUT_PRINTF("simple_command:\n", g_g_putlev++);
	SHG_PUT_PRINTF("assigns_list:\n", g_g_putlev);
	ft_dastrprint_all(simp_cmd->lst_assign, "\n");
	SHG_PUT_PRINTF("words_list:\n", g_g_putlev);
	ft_dastrprint_all(simp_cmd->lst_words, "\n");
	SHG_PUT_PRINTF("redirect_list:\n", g_g_putlev);
	ft_lstiterop(simp_cmd->lst_redir, SHG_PUT_CASTFUN(sh_g_redir_put), 1);
	g_g_putlev -= 2;
}
