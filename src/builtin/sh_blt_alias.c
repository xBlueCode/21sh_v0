/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_blt_alias.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 18:27:22 by abbesbes          #+#    #+#             */
/*   Updated: 2019/10/27 18:27:23 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftsh.h"

int			sh_blt_alias(t_sh *sh, char **argv, char **envp)
{
	int		ac;

	(void)envp;
	if (!sh || !sh->inter)
		return (1);
	ac = ft_arr_len((void**)argv);
	if (ac < 1)
		return (1);
	else if (ac == 1)
		sh_als_print(sh_als());
	else if (ac == 2 && !ft_strcmp("-a", argv[1]))
		sh_als_reset();
	else if (ac == 3)
	{
		if (!ft_strcmp("-d", argv[1]))
			sh_als_rem(sh_als(), argv[2]);
		else
			sh_als_add(sh_als(), argv[1], argv[2]);
	}
	else
		FT_INST_RET(1, ft_printf("ftsh: alias: Bad arguments !\n"));
	return (0);
}
