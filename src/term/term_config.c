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

	tcgetattr(STDERR_FILENO, &(term->tconfig_def));
	if (tcgetattr(STDERR_FILENO, &tconfig))
	{
		ft_putendl_fd("ftsh: tcgetattr: Failed !", STDERR_FILENO);
		sh_termconfig_reset(term);
		return (-1);
	}
	term->tconfig_def = tconfig;
	tconfig.c_lflag &= ~(ICANON | ECHO);
	tconfig.c_lflag &= ISIG;
	tconfig.c_cc[VTIME] = 0;
	tconfig.c_cc[VMIN] = 1;
	if (tcsetattr(STDERR_FILENO, TCSANOW, &tconfig))
	{
		ft_putendl_fd("ftsh: tcsetattr: Failed !", STDERR_FILENO);
		return (-1);
	}
	return (0);
}

/*
static int	sh_termconfig_jobc(t_term *term)
{
	term->stdi = STDIN_FILENO;
	if (!(term->inter = isatty(term->stdi)))
		return (KO);
	while (tcgetpgrp(term->stdi) != (term->pgid = getpgrp()))
		kill(-term->pgid, SIGTTIN);
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	signal(SIGTSTP, SIG_IGN);
	signal(SIGTTIN, SIG_IGN);
	signal(SIGTTOU, SIG_IGN);
	signal(SIGCHLD, SIG_IGN);
	term->pgid = getpid();
	if (setpgid(term->pgid, term->pgid) < 0)
	{
		ft_dprintf(2, "Unable to put the shell in its own process group !");
		exit(1);
	}
	tcsetpgrp(term->stdi, term->pgid);
	return (OK);
}
*/

int			sh_termconfig_init(t_term *term)
{
	char			*tname;
	char			buff[2048];
	int				r;

	//if (sh_termconfig_jobc(term) != OK)
	//	return (KO);
	if (!(tname = getenv("TER")))
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
	if (tcsetattr(STDERR_FILENO, TCSANOW, &(term->tconfig_def)))
	{
		ft_putendl_fd("ftsh: tcsetattr: Failed !", STDERR_FILENO);
		return (1);
	}
	return (0);
}
