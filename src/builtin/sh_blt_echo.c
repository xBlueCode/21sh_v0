/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_blt_echo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 19:06:16 by abbesbes          #+#    #+#             */
/*   Updated: 2019/10/07 19:07:14 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftsh.h"

static int	sh_blt_echo_check_std(void)
{
	int c;

	if (read(STDOUT_FILENO, &c, 0) < 0)
	{
		ft_dprintf(2, "ftsh: echo: Impossible to write to stdout !\n");
		return (OK);
	}
	return (OK);
}

int			sh_blt_echo(t_sh *sh, char **argv, char **envp)
{
	uint8_t op;
	int		i;

	(void)envp;
	(void)sh;
	if (!argv || sh_blt_echo_check_std() != OK)
		return (1);
	op = 0;
	i = 1;
	if (argv[i] && !ft_strcmp(argv[i], "-n") && i++)
		op = 1;
	while (argv[i])
	{
		if (!argv[i + 1])
			break ;
		ft_putstr(argv[i++]);
		ft_putchar(' ');
	}
	if (argv[i])
		ft_putstr(argv[i]);
	if (!op)
		ft_putchar('\n');
	return (0);
}
