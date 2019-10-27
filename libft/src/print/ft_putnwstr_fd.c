/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnwstr_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/01 19:31:43 by abbesbes          #+#    #+#             */
/*   Updated: 2019/01/11 17:49:33 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <wchar.h>

void	ft_putnwstr_fd(wint_t *wstr, int n, int fd)
{
	int i;

	if (!wstr || n < 1 || fd < 0)
		return ;
	i = 0;
	while (i < n && wstr[i])
		ft_putwchar_fd(wstr[i++], fd);
}
