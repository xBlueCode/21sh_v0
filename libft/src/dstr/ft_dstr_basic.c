/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dstr_basic.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 10:53:33 by abbesbes          #+#    #+#             */
/*   Updated: 2019/03/14 14:27:26 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dstr			*ft_dstrnew_str(char *str)
{
	int		s;
	t_dstr	*dstr;

	if (!str)
		return (NULL);
	s = ft_strlenz(str) + 2;
	dstr = (t_dstr*)malloc(sizeof(t_dstr));
	dstr->str = ft_memalloc(s * sizeof(char));
	ft_strcpy(dstr->str, str);
	dstr->str[--s] = '\0';
	dstr->max = s--;
	dstr->len = s;
	return (dstr);
}

t_dstr			*ft_dstrset_str(char *str)
{
	t_dstr	*dstr;

	if (!str)
		return (NULL);
	dstr = (t_dstr*)malloc(sizeof(t_dstr));
	dstr->str = str;
	dstr->max = ft_strlenz(str);
	dstr->len = ft_strlenz(str);
	return (dstr);
}

t_dstr			*ft_dstrnew_str_free(char **str)
{
	t_dstr	*dstr;

	dstr = ft_dstrnew_str(*str);
	ft_memdel((void**)str);
	return (dstr);
}

t_dstr			*ft_dstrnew_max(ssize_t max)
{
	t_dstr	*dstr;

	if (max < 0)
		return (NULL);
	if (!(dstr = (t_dstr*)malloc(sizeof(t_dstr))))
		return (NULL);
	if (!(dstr->str = (char*)malloc((max + 1) * sizeof(char))))
	{
		ft_memdel((void**)&dstr);
		return (NULL);
	}
	dstr->max = max;
	while (max > -1)
		dstr->str[max--] = '\0';
	dstr->len = 0;
	return (dstr);
}

int				ft_dstrfree(t_dstr **dstr)
{
	ft_memdel((void**)&((*dstr)->str));
	ft_memdel((void**)dstr);
	return (0);
}
