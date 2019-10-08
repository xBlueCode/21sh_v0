/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 19:32:21 by abbesbes          #+#    #+#             */
/*   Updated: 2019/10/07 19:32:22 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftsh.h"

char	*sh_env_getval(char **envp, char *name)
{
	int		i;
	int		eqi;

	if (!envp || !name)
		return (NULL);
	i = -1;
	while (envp[++i])
	{
		if ((eqi = ft_strichr(envp[i], '=')) < 0)
			eqi = ft_strlen(envp[i]);
		if (ft_strncmp(envp[i], name, eqi))
			continue;
		if (envp[i][eqi] == '=')
			return (envp[i] + eqi + 1);
		else
			return (envp[i] + eqi);
	}
	return (NULL);
}
