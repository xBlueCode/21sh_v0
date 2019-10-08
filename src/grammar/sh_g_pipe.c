/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_g_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 19:13:28 by abbesbes          #+#    #+#             */
/*   Updated: 2019/10/07 19:13:30 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftsh.h"

extern int		g_g_putlev;

void			*sh_g_pipe_new(void)
{
	t_pipe *pipe;

	SHG_CHECK_MALL(pipe);
	pipe->lst_cmd = NULL;
	pipe->neg = 0;
	return (pipe);
}

void			sh_g_pipe_free(void **g)
{
	t_pipe	**pipe;

	DF0;
	pipe = (t_pipe**)g;
	ft_lst_free(&(*pipe)->lst_cmd, &sh_g_cmd_free);
	ft_dstrfree(&(*pipe)->op);
	FT_MEMDEL(*g);
}

void			*sh_g_pipe(t_btree *ast)
{
	t_pipe	*pipe;
	t_btree	*ast_pipesec;
	t_cmd	*cmd;

	SHG_CHECK_AST(ast, SH_GR_PIPELINE);
	pipe = sh_g_pipe_new();
	pipe->neg = ast->data ? 1 : 0;
	ast_pipesec = ast->left;
	while (ast_pipesec)
	{
		if ((cmd = sh_g_cmd(ast_pipesec->left)))
			SHG_LSTADD_FREE(pipe, lst_cmd, cmd);
		ast_pipesec = ast_pipesec->right;
		//FT_MEMDEL(cmd);
	}
	if (!pipe->lst_cmd)
		return (NULL);
	return (pipe);
}

void			sh_g_pipe_put(void *g, int op)
{
	t_pipe *pipe;

	if (!g)
		return ;
	g_g_putlev++;
	SHG_PUT_CASTVAR(pipe, g, t_pipe*, op);
	SHG_PUT_PRINTF("pipe: ", g_g_putlev++);
	ft_printf("(neg = %d)\n", pipe->neg);
	SHG_PUT_PRINTF("command_list:\n", g_g_putlev);
	ft_lstiterop(pipe->lst_cmd, SHG_PUT_CASTFUN(sh_g_cmd_put), 1);
	g_g_putlev -= 2;
}
