/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_percent.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 19:58:18 by abbesbes          #+#    #+#             */
/*   Updated: 2019/01/15 14:12:52 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		pf_percent(int fd, t_flagset fset)
{
	int t_len;

	t_len = fset.prec > 0 && fset.zero_pad ? fset.prec : 1;
	if (ft_strchr("#0- +\'hljtzqL", fset.spec))
		return (0);
	if (!fset.minus)
	{
		if (fset.zero_pad)
			fill_wchar_fd(fd, '0', fset.field_w - 1);
		else
		{
			fill_wchar_fd(fd, ' ', t_len - 1);
			fill_wchar_fd(fd, ' ', fset.field_w - t_len);
		}
	}
	fill_char_fd(fd, ' ', !fset.zero_pad ? t_len - 1 : 0);
	ft_putchar_fd(fset.spec, fd);
	if (fset.minus && fset.field_w - t_len > 0)
		fill_wchar_fd(fd, ' ', fset.field_w - t_len);
	return (fset.field_w > t_len ? fset.field_w : t_len);
}
