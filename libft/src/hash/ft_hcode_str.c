/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hcode_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 18:45:03 by abbesbes          #+#    #+#             */
/*   Updated: 2019/10/21 18:45:07 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_hcode_str(void *data)
{
	size_t			code;
	unsigned char	*str;

	str = (unsigned char *)data;
	code = 5381;
	while (*str)
	{
		code = (code << 5) + code + *str;
		++str;
	}
	return (code);
}

size_t		ft_hcode_stric(void *data)
{
	size_t			code;
	unsigned char	*str;

	str = (unsigned char *)data;
	code = 5381;
	while (*str)
	{
		code = (code << 5) + code + (unsigned int)ft_tolower(*str);
		++str;
	}
	return (code);
}

int			ft_hequals_str(void *str1, void *str2)
{
	return (!ft_strcmp((char*)str1, (char*)str2));
}
