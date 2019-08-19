#include "ftsh.h"

int 		sh_e_simp_cmd(t_sh *sh, void *gr)
{
	t_simp_cmd	*simp_cmd;
	t_list		*wordslst;
	char 		**wordsarr;
	int 		i;
	int 	ret;
	t_dastr	*dcli;
	pid_t		pid;
	int 		wstat;

	DF0
	if ((ret = 0) || !sh || !gr)
		return (0);
	simp_cmd = (t_simp_cmd*)gr;
	dcli = ft_dastrnew_max(5);
	wordslst = simp_cmd->lst_words;
	while (wordslst)
	{
		//ft_dastrput_dstr(dcli, -1, (t_dstr*)wordslst->content);
		ft_dastrins_str(dcli, -1, ((t_dstr*)wordslst->content)->str);
		wordslst = wordslst->next;
	}
	wordsarr = ft_memalloc(dcli->len + 1);
	i = -1;
	wordsarr[dcli->len] = NULL;
	while (++i < dcli->len)
		wordsarr[i] = dcli->a[i]->str;
	if ((pid = fork()) < 0)
		return (ft_printf("fork error\n"));
	else if (!pid)
	{
		execve(wordsarr[0], wordsarr, NULL);
		exit(1);
	}
	ft_printf("waiting ....\n");
	wait(&wstat);
	return (WEXITSTATUS(wstat));
}
