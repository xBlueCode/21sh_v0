#include "ftsh.h"

extern int 		g_g_putlev;

void			*sh_g_loop_new(void)
{
	t_loop *loop;

	SHG_CHECK_MALL(loop)
	loop->cond = NULL;
	loop->do_group = NULL;
	return (loop);
}

void			*sh_g_loop(t_btree *ast)
{

	t_loop	*loop;

	//SHG_CHECK_AST(loop, SH_GR_WHILE_CLAUSE)
	if (!ast || (ast->op != SH_GR_WHILE_CLAUSE && ast->op != SH_GR_UNTIL_CLAUSE))
		return (NULL);
	loop = sh_g_loop_new();
	if (!(loop->cond = sh_g_com_cmd(ast->left))) // free if true
		return (NULL);
	loop->cond->gr = SH_GR_COMP_LIST; // TBD
	if (!(loop->do_group = sh_g_group(ast->right))) // free if true
		return (NULL);
	return (loop);
}

void			sh_g_loop_put(void*g, int op)
{
	t_loop	*loop;

	if (!g)
		return ;
	g_g_putlev++;
	SHG_PUT_CASTVAR(loop, g, t_loop*, op)
	SHG_PUT_PRINTF("loop:\n", g_g_putlev++);
	SHG_PUT_PRINTF("condition:\n", g_g_putlev);
	sh_g_com_cmd_put(loop->cond, 0);
	SHG_PUT_PRINTF("do_group:\n", g_g_putlev);
	sh_g_com_cmd_put(loop->do_group, 0);
}
