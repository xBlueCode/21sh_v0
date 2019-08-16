#include "ftsh.h"

int			sh_e_com_cmds(t_sh *sh, void *gr, int cinb)
{
	t_com_cmds	*com_cmds;
	t_list		*com_cmd;
	int 		ret;

	(void)cinb;
	if (!sh || !gr)
		return (0);
	com_cmds = (t_com_cmds*)gr;
	com_cmd = com_cmds->lst_com_cmd;
	ret = 0;
	while (com_cmd) // replace by lst_iter
	{
		ret = sh_e_com_cmd(sh, com_cmd, 0);
		com_cmd = com_cmd->next;
	}
	return (ret);
}

int			sh_e_com_cmd(t_sh *sh, void *gr, int inbg) // map to group exec (subsh)
{
	t_list		*and_or_lst;
	t_com_cmd	*com_cmd;
	int 		cinbg; // current in_back (level)
	int 		ret;

	if ((ret = 0) || !sh || !gr)
		return (0);
	com_cmd = (t_com_cmd*)gr;
	and_or_lst = com_cmd->lst_and_or;
	while (and_or_lst)
	{
		cinbg = inbg;
		if (!cinbg)
		{
			cinbg = ft_dstrget_ch(com_cmd->sep, -1) == '&' ? 1 : 0;
			sh_jc_add(sh->jc, sh_jc_new(cinbg));
		}
		ft_dstrdel_n(com_cmd->sep, -1, 1);
		ret = sh_e_and_or(sh, and_or_lst->content, cinbg);
		and_or_lst = and_or_lst->next;
	}
	return (ret);
}

int 		sh_e_and_or(t_sh *sh, void *gr, int cinb)
{
	t_and_or	*and_or;
	t_list		*pipe_lst;
	int 		ret;
	int 		sep_ao;

	if ((ret = 0) || !sh || !gr)
		return (0);
	and_or = (t_and_or*)gr;
	pipe_lst = and_or->lst_pipe;
	while (pipe_lst)
	{
		sep_ao = ft_dstrget_ch(and_or->sep, -1);
		ft_dstrdel_n(and_or->sep, -1, 1);
		ret = sh_e_pipe(sh, pipe_lst->content, cinb);
		if ((ret && sep_ao == TSA2) || (!ret && sep_ao == TSO2))
			break;
		pipe_lst = pipe_lst->next;
	}
	return (ret);
}

int			sh_e_pipe(t_sh *sh, void *gr, int cinb)
{
	t_pipe	*pip;
	t_list	*cmd_lst;
	t_cmd	*cmd;
	int 	fifo[2];
	int 	ret;

	if ((ret = 0) || !sh || !gr)
		return (0);
	pip = (t_pipe*)gr;
	cmd_lst = pip->lst_cmd;
	fifo[0] = -1;
	while (cmd_lst)
	{
		cmd = cmd_lst->content;
		if (fifo[0] != -1)
			cmd->stdi = fifo[0];
		if (cmd_lst->next)
		{
			if (pipe(fifo) < 0)
			{
				ft_printf("error: pipe()\n");
				exit(1);
			}
			cmd->stdo = fifo[1];
		}
		ret = sh_e_cmd(sh, cmd, cinb);
	}
	ret = pip->neg ? pip->neg - ret : ret;
	return (ret);
}

int			sh_e_cmd(t_sh *sh, void *gr, int cinb)
{
	t_cmd	*cmd;
	int 	ret;

	if ((ret = 0) || !sh || !gr)
		return (0);
	cmd = (t_cmd*)gr;
	// TODO: perform redirection for compound cmd
	if (cmd->type == SH_GR_SIMP_CMD)
		return (sh_e_simp_cmd(sh, cmd->core, cinb));
	else
		return (1);
}

int 		sh_e_simp_cmd(t_sh *sh, void *gr, int cinb)
{
	t_simp_cmd	*simp_cmd;
	t_list		*wordslst;
	char 		**wordsarr;
	int 		i;
	int 	ret;
	t_dastr	*dcli;

	(void)cinb;
	if ((ret = 0) || !sh || !gr)
		return (0);
	simp_cmd = (t_simp_cmd*)gr;
	dcli = ft_dastrnew_max(5);
	wordslst = simp_cmd->lst_words;
	while (wordslst)
	{
		ft_dastrput_dstr(dcli, -1, (t_dstr*)wordslst->content);
		wordslst = wordslst->next;
	}
	wordsarr = ft_memalloc(dcli->len + 1);
	i = -1;
	while (++i < dcli->len + 1)
		wordsarr[i] = dcli->a[i]->str;
	execve(wordsarr[0], wordsarr + 1, NULL);
	return (ret);
}