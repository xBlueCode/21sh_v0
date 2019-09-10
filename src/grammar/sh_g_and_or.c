#include "ftsh.h"

extern int 		g_g_putlev;

void			*sh_g_and_or_new(void)
{
	t_and_or	*and_or;

	SHG_CHECK_MALL(and_or);
	and_or->lst_pipe = NULL;
	and_or->sep = ft_dstrnew_max(2);
	return (and_or);
}

void			sh_g_and_or_free(void**g)
{
	t_and_or	**and_or;

	and_or = (t_and_or**)g;
	ft_dstrfree(&(*and_or)->sep);
	ft_lst_free(&(*and_or)->lst_pipe, &sh_g_pipe_free);
	FT_MEMDEL(*and_or);
}

void			*sh_g_and_or(t_btree *ast_ao)
{
	t_and_or	*and_or;
	t_pipe		*pipe;

	SHG_CHECK_AST(ast_ao, SH_GR_AND_OR);
	and_or = sh_g_and_or_new();
	//pipe = NULL; // TODO: recheck
	while (ast_ao)
	{
		if (ast_ao->data)
			ft_dstrins_ch(and_or->sep, -1, SHG_AST_TOK(ast_ao)->t);
		if ((pipe = sh_g_pipe(ast_ao->left)))
			SHG_LSTADD(and_or, lst_pipe, pipe)
		else
			break;
		ast_ao = ast_ao->right;
		FT_MEMDEL(pipe);
	}
	if (!and_or->lst_pipe)
		return (NULL);
	return (and_or);
}

void			sh_g_and_or_put(void*g, int op)
{
	t_and_or	*and_or;
	int 		i;

	if (!g)
		return ;
	g_g_putlev++;
	SHG_PUT_CASTVAR(and_or, g, t_and_or*, op)
	SHG_PUT_PRINTF("and_or:\n", g_g_putlev++);
	SHG_PUT_PRINTF("pipe_list:\n", g_g_putlev);
	ft_lstiterop(and_or->lst_pipe, SHG_PUT_CASTFUN(sh_g_pipe_put), 1);
	SHG_PUT_PRINTF("separators: ", g_g_putlev);
	i = -1;
	while (++i < and_or->sep->len)
		ft_printf("%s  ", and_or->sep->str[i] == TSA2 ? "&&" : "||");
	ft_putchar('\n');
	g_g_putlev -= 2;
}
