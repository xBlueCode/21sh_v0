/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arr_strdup.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 15:27:34 by abbesbes          #+#    #+#             */
/*   Updated: 2019/02/17 15:21:28 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_arr_strdup(char **arr)
{
	char	**new;
	ssize_t	i;

	if (!arr)
		return (NULL);
	i = -1;
	while (arr[++i])
		;
	if (!(new = (char**)malloc((i + 1) * sizeof(char*))))
		return (NULL);
	new[i] = NULL;
	while (--i + 1 > 0)
		new[i] = ft_strdup(arr[i]);
	return (new);
}

/*
** Usage: minishell:blt_setenv() |
**
** Return: a new copy of the array with extended NULLs
*/

char	**ft_arr_strdup_extend(char **arr, ssize_t e)
{
	char	**new;
	ssize_t	i;

	if (!arr)
		return (NULL);
	i = -1;
	while (arr[++i])
		;
	if (!(new = (char**)malloc((i + e + 1) * sizeof(char*))))
		return (NULL);
	while (e > -1)
		new[i + e--] = NULL;
	while (--i + 1 > 0)
		new[i] = ft_strdup(arr[i]);
	return (new);
}
