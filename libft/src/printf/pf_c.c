/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_c.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 12:34:09 by abbesbes          #+#    #+#             */
/*   Updated: 2019/01/15 14:15:45 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <wchar.h>

int			pf_cc(int fd, t_flagset fset, va_list *args)
{
	if (fset.spec == 'C' || fset.mod == mod_l)
		return (pf_wc(fd, fset, (unsigned)va_arg(*args, unsigned)));
	else
		return (pf_c(fd, fset, (unsigned char)va_arg(*args, int)));
}

int			pf_c(int fd, t_flagset fset, int ch)
{
	if (!fset.minus && fset.zero_pad)
		fill_char_fd(fd, '0', fset.field_w - 1);
	else if (!fset.minus)
		fill_char_fd(fd, ' ', fset.field_w - 1);
	ft_putchar_fd(ch, fd);
	if (fset.minus)
		fill_char_fd(fd, ' ', fset.field_w - 1);
	return (fset.field_w > 0 ? fset.field_w : 1);
}

int			pf_wc(int fd, t_flagset fset, unsigned int wch)
{
	int			wch_len;

	if ((wch_len = ft_wchar_len(wch)) < 1)
		return (wch_len);
	if (!fset.minus && fset.zero_pad)
		fill_char_fd(fd, '0', fset.field_w - wch_len);
	else if (!fset.minus)
		fill_char_fd(fd, ' ', fset.field_w - wch_len);
	ft_putwchar_fd(wch, fd);
	if (fset.minus)
		fill_wchar_fd(fd, ' ', fset.field_w - wch_len);
	return (fset.field_w > wch_len ? fset.field_w : wch_len);
}
