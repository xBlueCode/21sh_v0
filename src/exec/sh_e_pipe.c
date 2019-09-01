#include "ftsh.h"



int			sh_e_pipe(t_sh *sh, void *gr)
{
	t_pipe	*pip;
	t_list	*cmd_lst;
	t_cmd	*cmd;
	int 	fifo[2];
	int 	ret;

	DF0
	if ((ret = 0) || !sh || !gr)
		return (0);
	pip = (t_pipe*)gr;
	cmd_lst = pip->lst_cmd;
	fifo[0] = -1;
	while (cmd_lst)
	{
		cmd = cmd_lst->content;
		ft_dup_stdioe_copy(cmd->stdioe, 0);
		if (fifo[0] != -1)
			cmd->stdioe[0] = fifo[0];
		if (cmd_lst->next)
		{
			//ft_printf(C_MGN"--> piping ...\n"T_END);
			if (pipe(fifo) < 0)
			{
				ft_printf("error: pipe()\n");
				exit(1);
			}
			//ft_printf(C_GRN"PIPE (%d, %d)\n"T_END, fifo[0], fifo[1]);
			cmd->stdioe[1] = fifo[1];
			//if (pip->op->str[0] == TSO_A)
			//	ft_dup2(fifo[1], STDERR_FILENO, 0);
			//ft_dstrdel_n(pip->op, 0, 1);
		}
		ret = sh_e_cmd(sh, cmd);
		cmd_lst = cmd_lst->next;
	}
	ret = pip->neg ? pip->neg - ret : ret;
	return (ret);
}

int			sh_e_cmd(t_sh *sh, void *gr)
{
	t_cmd	*cmd;
	int 	ret;
	int 	stdioe[3];

	DF0
	if (!sh || !gr)
		return (0);
	cmd = (t_cmd*)gr;
	// TODO: perform redirection for compound cmd
	ft_dup_stdioe_copy(stdioe, 0);
	ft_dup_stdioe_set(cmd->stdioe, 1);
	sh_e_redirect(cmd->lst_redir);
	ret = cmd->exec(sh, cmd->core);
	ft_dup_stdioe_set(stdioe, 1);
	return (ret);
	/*
	if (cmd->type == SH_GR_SIMP_CMD)
	{
		ret = sh_e_simp_cmd(sh, cmd->core);
		ft_dup_stdioe_set(stdioe, 1);
		return (ret);
	}
	 */
}
