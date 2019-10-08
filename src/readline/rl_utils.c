/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 17:41:25 by abbesbes          #+#    #+#             */
/*   Updated: 2019/03/22 14:28:53 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_rl.h"
#include <sys/ioctl.h>

extern t_rl	g_rl;

int			rl_ter_putchar(int ch)
{
	ft_putchar_fd(ch, STDERR_FILENO);
	return (0);
}

int			rl_update_win(void)
{
	struct winsize ws;

	if (ioctl(STDIN_FILENO, TIOCGWINSZ, &ws))
		return (-1);
	g_rl.wc = ws.ws_col;
	g_rl.wl = ws.ws_row;
	return (0);
}
