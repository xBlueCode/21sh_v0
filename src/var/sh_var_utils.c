/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_var_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 19:32:36 by abbesbes          #+#    #+#             */
/*   Updated: 2019/10/07 19:33:02 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftsh.h"

int		sh_var_tsel_glo(t_trow trow)
{
	if (BIT_IS(trow.opt, SH_VO_GLO))
		return (1);
	return (0);
}

char	*sh_var_tbuild_env(t_trow trow)
{
	return (ft_strconnect(3, trow.name, "=", trow.value));
}

int		sh_var_assign(t_table *envt, t_dastr *assigns)
{
	char	*val;
	char	*key;
	int		i;

	if (!assigns || !assigns->len)
		return (0);
	i = -1;
	while (++i < assigns->len)
	{
		key = assigns->a[i]->str;
		if (!(val = ft_strchr(key, '=')))
			return (-1);
		*val = '\0';
		val++;
		ft_tabins(envt, ft_tabrow_set(-1, key, val, SH_VO_GLO), 1);
	}
	return (1);
}
