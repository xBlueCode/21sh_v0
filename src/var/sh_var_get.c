/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_var_get.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 19:32:27 by abbesbes          #+#    #+#             */
/*   Updated: 2019/10/07 19:32:28 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ftsh.h"

char	*sh_var_getval(t_table *var, char *name)
{
	t_trow	trow;

	trow = ft_tabget_n(var, name);
	return (trow.value);
}
