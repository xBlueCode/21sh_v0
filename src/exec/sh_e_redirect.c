#include "ftsh.h"
#include "sys/stat.h"
#include <fcntl.h>

int 	sh_e_redirect(t_list *redir_lst)
{
	t_redir	*redir;

	while (redir_lst)
	{
		if (!(redir = (t_redir*)redir_lst->content))
			continue;
		if (redir->op == TSG || redir->op == TSG_O || redir->op == TSG2)
			sh_e_redirect_g(redir);
		else if (redir->op == TSL)
			sh_e_redirect_l(redir);
		else if (redir->op == TSL2)
			sh_e_redirect_l2(redir);
		redir_lst = redir_lst->next;
	}
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
	if ((fdf = open(redir->word, redir->op == TSL_G ? O_RDWR : O_RDONLY)) < 0)
		return (KO);
	fdi = redir->ion < 0 ? STDIN_FILENO : redir->ion;
	ft_dup2(fdf, fdi, 1);
	return (OK);
}


int 	sh_e_redirect_l2(t_redir *redir)
{
	int		hdpipe[2];

	if (!redir || !redir->word)
		return (KO);
	pipe(hdpipe);
	write(hdpipe[1], redir->word, ft_strlen(redir->word));
	close(hdpipe[1]);
	if (redir->ion > -1)
		ft_dup2(hdpipe[0], redir->ion, 1);
	else
		ft_dup2(hdpipe[0], STDIN_FILENO, 1);
	return (OK);
}
