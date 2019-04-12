/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 12:02:09 by abbesbes          #+#    #+#             */
/*   Updated: 2019/03/16 14:39:09 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include "libft.h"
#include "ftsh.h"

void		prompt_display(void)
{
	char	cwd[PATH_MAX];
	//char	*home;

	getcwd(cwd, PATH_MAX);
	//home = blt_getenv("HOME");
	if (PROMPT_LOGIN)
	{
		CFPUTSTR(C_CYN, getlogin(), 1);
		ft_putwstr_fd(C_YLW""L" \u25C9  "T_END, 1);
	}
	//if (PROMPT_FPATH && home && !ft_strncmp(cwd, home, ft_strlenz(home)))
	//{
	//	ft_putchar_fd('~', 1);
	//	ft_putstr_fd(&cwd[ft_strlenz(home)], 1);
	//}
	else if (PROMPT_FPATH)
		ft_putstr(cwd);
	//else if (home && !ft_strcmp(cwd, home))
	//	CFPUTSTR(C_GRN, "~", 1);
	//else
	//	CFPUTSTR(C_GRN, ft_strrchr(cwd, FSEP) + (!cwd[1] ? 0 : 1), 1);
	//ft_putwstr_fd(C_RED""T_BLD""L" \u21E5  "C_END, 1);
}
