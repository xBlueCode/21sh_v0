/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/04 16:11:45 by abbesbes          #+#    #+#             */
/*   Updated: 2018/11/20 22:29:16 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char const *s, char c)
{
	size_t	i;
	size_t	start;
	size_t	ind;
	char	**arr;

	if (!s || !c)
		return (NULL);
	if (!(arr = (char**)malloc((1 + ft_count_sep_words(s, c)) * sizeof(char*))))
		return (NULL);
	i = 0;
	ind = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
		{
			start = i;
			while (s[i] && s[i] != c)
				i++;
			arr[ind++] = ft_strsub(s, start, i - start);
		}
	}
	arr[ind] = NULL;
	return (arr);
}
