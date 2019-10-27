/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 18:53:13 by abbesbes          #+#    #+#             */
/*   Updated: 2019/10/21 18:53:14 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fio.h"
#include "libft.h"

int		ft_dup2(int fildes, int fildes2, int op)
{
	int ret;

	if (fildes == fildes2)
		return (KO);
	if ((ret = dup2(fildes, fildes2)) > -1 && op)
		close(fildes);
	if (op)
		close(fildes);
	return (ret);
}

int		ft_dup_stdioe_copy(int stdioe[3], int op)
{
	if (!stdioe)
		return (KO);
	if ((stdioe[0] = dup(STDIN_FILENO)) < 0)
		return (KO);
	if ((stdioe[1] = dup(STDOUT_FILENO)) < 0)
		return (KO);
	if ((stdioe[2] = dup(STDERR_FILENO)) < 0)
		return (KO);
	if (!op)
		return (OK);
	close(STDIN_FILENO);
	close(STDOUT_FILENO);
	close(STDERR_FILENO);
	return (OK);
}

int		ft_dup_stdioe_set(int stdioe[3], int op)
{
	int ret;

	if (!stdioe)
		return (KO);
	ft_dup2(stdioe[0], STDIN_FILENO, op);
	ft_dup2(stdioe[1], STDOUT_FILENO, op);
	ft_dup2(stdioe[2], STDERR_FILENO, op);
	if (!op)
		return (OK);
	close(stdioe[0]);
	close(stdioe[1]);
	close(stdioe[2]);
	return (OK);
}
