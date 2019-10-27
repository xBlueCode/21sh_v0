/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strconnect.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 10:33:17 by abbesbes          #+#    #+#             */
/*   Updated: 2019/04/11 11:34:10 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

ssize_t	total_len(int n, va_list *args)
{
	va_list cargs;
	ssize_t	l;

	va_copy(cargs, *args);
	l = 0;
	while (--n > -1)
		l += ft_strlenz(va_arg(cargs, char *));
	va_end(cargs);
	return (l);
}

char	*ft_strconnect(int n, ...)
{
	va_list	args;
	char	*res;

	if (n < 1)
		return (NULL);
	va_start(args, n);
	res = (char*)ft_memalloc((total_len(n, &args) + 1) * sizeof(char));
	while (--n > -1)
		res = ft_strcat_safe(res, va_arg(args, char *));
	va_end(args);
	return (res);
}
