#include "ftsh.h"
#include "sys/stat.h"
#include <fcntl.h>

int		sh_e_redirect_ga(t_redir *redir)
{
	int fdo;
	int fdf;

	DF0;
	if (!redir)
		return (KO);
	if (ft_strcmp("-",redir->word))
		fdf = -1;
	else if (ft_isdigit(*redir->word) && !redir->word[1])
		fdf = *redir->word - '0';
	else
	{
		if (!access(redir->word, F_OK) && access(redir->word, W_OK))
			return (KO);
		if (0 > (fdf = open(redir->word,
			O_CREAT | (redir->op == TSG2 ? O_APPEND : O_TRUNC) | O_WRONLY,
			0664)))
			return (KO);
	}
	fdo = redir->ion < 0 ? STDOUT_FILENO : redir->ion;
	if (fdf < 0)
		close(fdo);
	else
		ft_dup2(fdf, fdo, 1);
	if (fdf == STDOUT_FILENO)
		ft_dup2(fdf, STDERR_FILENO, 1);
	return (OK);
}

int		sh_e_redirect_la(t_redir *redir)
{
	int fdi;
	int fdf;

	DF0;
	if (!redir)
		return (KO);
	if (ft_strcmp("-",redir->word))
		fdf = -1;
	else if (ft_isdigit(*redir->word) && !redir->word[1])
		fdf = *redir->word - '0';
	else
	{
		if (access(redir->word, F_OK) || access(redir->word, R_OK))
			return (KO);
		if ((fdf = open(redir->word, redir->op == TSL_G ? O_RDWR : O_RDONLY)) < 0)
			return (KO);
	}
	fdi = redir->ion < 0 ? STDIN_FILENO : redir->ion;
	if (fdf < 0)
		close(fdi);
	else
		ft_dup2(fdf, fdi, 1);
	if (fdf == STDIN_FILENO)
		ft_dup2(fdf, STDERR_FILENO, 1);
	return (OK);
}
