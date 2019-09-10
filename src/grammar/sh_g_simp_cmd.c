#include "ftsh.h"

extern int 		g_g_putlev;

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
			if (tok->t == TSTOK_WORD) // TODO: orgin: TOK_WORD
				ft_dastrins_str(simp_cmd->lst_words, -1, tok->val->str);
				//SHG_LSTADD(simp_cmd, lst_words, tok->val)
			else if (tok->t == TSTOK_ASS_WORD)
				ft_dastrins_str(simp_cmd->lst_assign, -1, tok->val->str);
				//SHG_LSTADD(simp_cmd, lst_assign, tok->val);
		}
		if (fix->left && (redir = sh_g_redir(fix->left)))
			SHG_LSTADD_FREE(simp_cmd, lst_redir, redir);
			//FT_MEMDEL(redir)
		fix = fix->right;
	}
	//DF_PFWAIT("simp prefsuff i >", 8)
}

void			sh_g_wordput(t_list *elem)
{
	t_dstr *dstr;

	if (!elem)
		return;
	g_g_putlev++;
	dstr = (t_dstr*)elem->content;
	if (dstr->str)
	{
		SHG_PUT_PRINTF(dstr->str, g_g_putlev)
		ft_putchar('\n');
	}
	g_g_putlev--;
}

void			*sh_g_simp_cmd_new(void)
{
	t_simp_cmd *simp_cmd;

	SHG_CHECK_MALL(simp_cmd)
	simp_cmd->lst_assign = ft_dastrnew_max(2);
	simp_cmd->lst_redir = NULL;
	simp_cmd->lst_words = ft_dastrnew_max(2);
	simp_cmd->envp = NULL;
	simp_cmd->argv = NULL;
	return (simp_cmd);
}

void			sh_g_simp_cmd_free(void**g)
{
	t_simp_cmd	**simp_cmd;

	simp_cmd = (t_simp_cmd**)g;
	ft_dastrfree(&(*simp_cmd)->lst_assign);
	ft_dastrfree(&(*simp_cmd)->lst_words);
	ft_arr_free((void***)&(*simp_cmd)->envp, ft_arr_len((void**)(*simp_cmd)->envp));
	ft_arr_free((void***)&(*simp_cmd)->argv, ft_arr_len((void**)(*simp_cmd)->argv));
	ft_lst_free(&(*simp_cmd)->lst_redir, &sh_g_redir_free);
	FT_MEMDEL(*g)
}

void			*sh_g_simp_cmd(t_btree *ast)
{
	t_simp_cmd	*simp_cmd;
//	t_btree		*ast_pref;
//	t_btree		*ast_suff;

	simp_cmd = sh_g_simp_cmd_new();
	if (ast->data)
		ft_dastrins_str(simp_cmd->lst_words, -1, SHG_AST_TOK(ast)->val->str);
		//SHG_LSTADD(simp_cmd, lst_words, SHG_AST_TOK(ast)->val);
	//	SHG_LSTADDS(simp_cmd, lst_words, (SHG_AST_TOK(ast)->val->str),
	//			ft_strlenz(SHG_AST_TOK(ast)->val->str));
//	ast_pref = ast->left;
	sh_g_simp_cmd_prefsuff(simp_cmd, ast->left);
	sh_g_simp_cmd_prefsuff(simp_cmd, ast->right);
	if (!simp_cmd->lst_words)
		return (NULL);
	//DF_PFWAIT("simp i >", 8)
	return (simp_cmd);
}

void			sh_g_simp_cmd_put(void*g, int op)
{
	t_simp_cmd *simp_cmd;

	if (!g)
		return ;
	g_g_putlev++;
	SHG_PUT_CASTVAR(simp_cmd, g, t_simp_cmd*, op)
	SHG_PUT_PRINTF("simple_command:\n", g_g_putlev++);
	SHG_PUT_PRINTF("assigns_list:\n", g_g_putlev);
	ft_dastrprint_all(simp_cmd->lst_assign, "\n");
	//ft_lstiter(simp_cmd->lst_assign, &sh_g_wordput);
	SHG_PUT_PRINTF("words_list:\n", g_g_putlev);
	ft_dastrprint_all(simp_cmd->lst_words, "\n");
	//ft_lstiter(simp_cmd->lst_words, &sh_g_wordput);
//	ft_lstiterop(simp_cmd->lst_words, ft_dstr)
	SHG_PUT_PRINTF("redirect_list:\n", g_g_putlev);
//	if (simp_cmd)
	ft_lstiterop(simp_cmd->lst_redir, SHG_PUT_CASTFUN(sh_g_redir_put), 1);
//	ft_printf("                    sim_cmd_end.");
	g_g_putlev -= 2;
}
