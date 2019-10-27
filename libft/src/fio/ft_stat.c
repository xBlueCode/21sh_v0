/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 18:53:26 by abbesbes          #+#    #+#             */
/*   Updated: 2019/10/21 18:53:27 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "sys/stat.h"

int		ft_stat_is(char *fname, int type)
{
	struct stat st;

	if (!fname)
		return (KO);
	if (stat(fname, &st))
		return (KO);
	if ((st.st_mode & S_IFMT) == type)
		return (OK);
	return (KO);
}
