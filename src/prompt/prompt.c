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

	getcwd(cwd, PATH_MAX);
	if (PROMPT_LOGIN)
	{
		CFPUTSTR(C_CYN, getlogin(), 1);
		ft_putwstr_fd(C_YLW""L" \u25C9  "T_END, 1);
	}
}
