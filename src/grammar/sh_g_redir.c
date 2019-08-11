#include "ftsh.h"

extern int 		g_g_putlev;

void			*sh_g_redir_new(void)
{
	t_redir *redir;

	SHG_CHECK_MALL(redir)
	redir->ion = -1;
	redir->op = -1;
	redir->word = NULL;
	return (redir);
}

void			*sh_g_redir(t_btree *ast)
{
	t_btree		*ast_iofh;
	t_btree		*ast_fh;
	t_redir		*redir;

	SHG_CHECK_AST(ast, SH_GR_IO_REDIR)
	redir = sh_g_redir_new();
	if (ast->data)
		redir->ion = ft_atoi(SHG_AST_TOK(ast)->val->str);
	else
		redir->ion = -1;
	if (!(ast_iofh = ast->left)) // TODO: free redir
		return (NULL);
	if (ast_iofh->data)
		redir->op = SHG_AST_TOK(ast_iofh)->t;
	if (!(ast_fh = ast_iofh->left)) // TODO: free redir
		return (NULL);
	if (ast_fh->data)
	{
		redir->word = ft_strdup(SHG_AST_TOK(ast_fh)->val->str); // TODO: secure val(dstr)
	}

		ft_printf(C_RED);
	//	sh_g_redir_put(redir, 0);
		ft_putstr(T_END);
	return (redir);
}

void			sh_g_redir_put(void*g, int op)
{
	t_redir *redir;

	if (!g)
		return ;
	g_g_putlev++;
	SHG_PUT_CASTVAR(redir, g, t_redir*, op)
	SHG_PUT_PRINTF("redirect:  ", g_g_putlev);
	ft_printf("  ion : %d", redir->ion);
	ft_printf("  op  : %d", redir->op);
	ft_printf("  word: %s", redir->word);
	ft_putchar('\n');
	g_g_putlev--;
}
