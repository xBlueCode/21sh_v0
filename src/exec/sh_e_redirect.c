#include "ftsh.h"
#include "sys/stat.h"
#include <fcntl.h>

int 	sh_e_redirect(t_list *redir_lst)
{
//	int		fdf;
	t_redir	*redir;

	while (redir_lst)
	{
		if (!(redir = (t_redir*)redir_lst->content))
			continue;
		if (redir->op == TSG || redir->op == TSG_O || redir->op == TSG2)
			sh_e_redirect_g(redir);
		if (redir->op == TSL)
			sh_e_redirect_l(redir);
		redir_lst = redir_lst->next;
	}
	return (OK);
}

int 	sh_e_prepare_file(char *fname, int exist, int read, int write)
{
// TODO: to be rechecked
	if (!fname)
		return (KO);
	if (exist && access(fname, F_OK))
		return (KO);
	if (ft_stat_is(fname, S_IFDIR))
		return (KO);
	if (read && (!access(fname, F_OK) && access(fname, R_OK)))
		return (KO);
	if (write && (!access(fname, F_OK) && access(fname, W_OK)))
		return (KO);
	return (OK);
}

int 	sh_e_redirect_g(t_redir *redir)
{
	int fdo;
	int fdf;

	DF0
	if (!redir)
		return (KO);
	if (!access(redir->word, F_OK) && access(redir->word, W_OK))
		return (KO);
	if ((fdf = open(redir->word, O_CREAT | O_TRUNC | O_WRONLY, 0664)) < 0)
		return (KO);
	fdo = redir->ion < 0 ? STDOUT_FILENO : redir->ion;
	ft_dup2(fdf, fdo, 1);
	return (OK);
}

int 	sh_e_redirect_l(t_redir *redir)
{
	int fdi;
	int fdf;

	if (!redir)
		return (KO);
	if (access(redir->word, F_OK) || access(redir->word, R_OK))
		return (KO);
	if ((fdf = open(redir->word, O_RDONLY)) < 0)
		return (KO);
	fdi = redir->ion < 0 ? STDIN_FILENO : redir->ion;
	ft_dup2(fdf, fdi, 1);
	return (OK);
}
