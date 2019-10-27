/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrlenz.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 15:45:58 by abbesbes          #+#    #+#             */
/*   Updated: 2019/01/13 19:54:38 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <wchar.h>

size_t	ft_wstrlenz(wint_t *wstr)
{
	if (!wstr || *wstr == L'\0')
		return (0);
	return (ft_wchar_len(*wstr) + ft_wstrlenz(wstr + 1));
}
