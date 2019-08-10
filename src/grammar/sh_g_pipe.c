#include "ftsh.h"

void			*sh_g_pipe_new(void)
{
	t_pipe *pipe;

	SHG_CHECK_MALL(pipe);
	pipe->lst_cmd = NULL;
	pipe->neg = 0;
	return (pipe);
}

void			*sh_g_pipe(t_btree *ast)
{
	t_pipe	*pipe;
	t_btree	*ast_pipesec;
	t_cmd	*cmd;

	SHG_CHECK_AST(ast, SH_GR_PIPELINE)
	pipe = sh_g_pipe_new();
	pipe->neg = ast->data ? 1 : 0;
	ast_pipesec = ast->left;
	while (ast_pipesec)
	{
		if ((cmd = sh_g_cmd(ast_pipesec->left)))
			SHG_LSTADD(pipe, lst_cmd, cmd);
		ast_pipesec = ast_pipesec->right;
	}
	return (pipe);
}
