/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwstr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/02 16:38:44 by abbesbes          #+#    #+#             */
/*   Updated: 2019/01/02 16:38:49 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <wchar.h>

void	ft_putwstr_fd(wchar_t *str, int fd)
{
	while (*str)
	{
		ft_putwchar_fd(*str, fd);
		str++;
	}
}
