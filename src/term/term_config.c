/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_config.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 18:49:53 by abbesbes          #+#    #+#             */
/*   Updated: 2019/03/23 11:15:17 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ftsh.h"

int			ter_putchar(int ch)
{
	ft_putchar_fd(ch, STDERR_FILENO);
	return (0);
}

static int	termconfig_attr(t_term *term)
{
	struct termios tconfig;

	//tputs(tgetstr("ti", NULL), 1, ter_putchar);
	//tputs(tgetstr("vi", NULL), 1, ter_putchar);
	tcgetattr(STDERR_FILENO, &(term->tconfig_def));
	if (tcgetattr(STDERR_FILENO, &tconfig))
	{
		ft_putendl_fd("ftsh: tcgetattr: Failed !", STDERR_FILENO);
		sh_termconfig_reset(term);
		return (-1);
	}
	term->tconfig_def = tconfig;
	tconfig.c_lflag &= ~(ICANON | ECHO);
	tconfig.c_cc[VTIME] = 0;
	tconfig.c_cc[VMIN] = 1;
	if (tcsetattr(STDERR_FILENO, TCSANOW, &tconfig))
	{
		ft_putendl_fd("ftsh: tcsetattr: Failed !", STDERR_FILENO);
		return (-1);
	}
	return (0);
}

int			sh_termconfig_init(t_term *term)
{
	char			*tname;
	char			buff[2048];
	int				r;

	if (!(tname = getenv("TER"))) // TODO: replace with ft_getenv
	{
		if (!(tname = TER_DEF) || !isatty(STDIN_FILENO))
		{
			ft_putendl_fd("Failed to Connect to Term !", STDERR_FILENO);
			return (-1);
		}
	}
	if ((r = tgetent(buff, tname)) < 1)
	{
		if (!r)
			ft_putendl_fd("Err: There is no such entry !", STDERR_FILENO);
		else
			ft_putendl_fd("Err: Failed to get Terminfo DB !", STDERR_FILENO);
		return (-1);
	}
	if (termconfig_attr(term))
		return (-1);
	return (0);
}

int			sh_termconfig_reset(t_term *term)
{
	//tputs(tgetstr("te", NULL), 1, ter_putchar);
	//tputs(tgetstr("ve", NULL), 1, ter_putchar);
	if (tcsetattr(STDERR_FILENO, TCSANOW, &(term->tconfig_def)))
	{
		ft_putendl_fd("ftsh: tcsetattr: Failed !", STDERR_FILENO);
		return (1);
	}
	return (0);
}
