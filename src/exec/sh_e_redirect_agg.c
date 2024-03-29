/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_e_redirect_agg.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 01:20:37 by abbesbes          #+#    #+#             */
/*   Updated: 2019/10/14 01:20:39 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftsh.h"
#include "sys/stat.h"
#include <fcntl.h>

static void		aggregate(int ion, int fdf, int std)
{
	if (fdf < 0)
		close(std);
	else
		ft_dup2(fdf, std, 1);
	if (ion < 0 && std != STDIN_FILENO)
		ft_dup2(fdf, STDERR_FILENO, 1);
}

static int		sh_e_check_fildes(t_redir *redir, int *fdf)
{
	DF0;
	if (!redir)
		return (KO);
	if (redir->ion > 2)
		FT_INST_RET(KO, ft_printf("ftsh: redir: Bad fildes: %d\n", redir->ion));
	if (!ft_strcmp("-", redir->word))
		*fdf = -1;
	else if (ft_isdigit(*redir->word) && !redir->word[1])
	{
		if ((*fdf = *redir->word - '0') > 2)
			FT_INST_RET(KO, ft_printf("ftsh: redir: Bad fildes: %d\n", *fdf));
	}
	return (OK);
}

int				sh_e_redirect_ga(t_redir *redir)
{
	int fdo;
	int fdf;

	DF0;
	fdf = -2;
	if (sh_e_check_fildes(redir, &fdf) == KO)
		return (KO);
	else if (fdf == -2)
	{
		if (!access(redir->word, F_OK) && access(redir->word, W_OK))
			return (KO);
		if (0 > (fdf = open(redir->word,
			O_CREAT | (redir->op == TSG2 ? O_APPEND : O_TRUNC) | O_WRONLY,
			0664)))
			return (KO);
	}
	fdo = redir->ion < 0 ? STDOUT_FILENO : redir->ion;
	aggregate(redir->ion, fdf, fdo);
	return (OK);
}

int				sh_e_redirect_la(t_redir *redir)
{
	int fdi;
	int fdf;

	DF0;
	fdf = -2;
	if (sh_e_check_fildes(redir, &fdf) == KO)
		return (KO);
	else if (fdf == -2)
	{
		if (access(redir->word, F_OK) || access(redir->word, R_OK))
			return (KO);
		if ((fdf = open(redir->word,
				redir->op == TSL_G ? O_RDWR : O_RDONLY)) < 0)
			return (KO);
	}
	fdi = redir->ion < 0 ? STDIN_FILENO : redir->ion;
	aggregate(redir->ion, fdf, fdi);
	return (OK);
}
