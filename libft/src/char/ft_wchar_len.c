/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wchar_len.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 12:50:15 by abbesbes          #+#    #+#             */
/*   Updated: 2019/01/11 13:08:12 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wchar.h>

int		ft_wchar_len(wint_t wch)
{
	if (wch < 0x0 || wch > 0x7FFFFFFF)
		return (-1);
	else if (wch < 0x80)
		return (1);
	else if (wch < 0x800)
		return (2);
	else if (wch < 0x10000)
		return (3);
	else if (wch < 0x200000)
		return (4);
	else if (wch < 0x4000000)
		return (5);
	else
		return (6);
}
