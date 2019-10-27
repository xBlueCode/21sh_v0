/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_s.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 12:36:33 by abbesbes          #+#    #+#             */
/*   Updated: 2019/01/22 16:57:29 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <wchar.h>

int			pf_ss(int fd, t_flagset fset, va_list *args)
{
	if (fset.spec == 'S' || fset.mod == mod_l)
		return (pf_ws(fd, fset, (wchar_t *)va_arg(*args, wchar_t *)));
	else
		return (pf_s(fd, fset, (char *)va_arg(*args, int *)));
}

int			pf_ws(int fd, t_flagset fset, wint_t *str)
{
	int		wlen;
	int		tlen;
	int		n;
	wint_t	*wstr;

	wstr = str ? str : (wint_t*)L"(null)";
	if (*wstr == 0xc1)
		return (-1);
	wlen = ft_wstrlenz(wstr);
	tlen = (fset.prec < 0 || fset.prec > wlen) ? wlen : fset.prec;
	n = -1;
	while (wstr[++n])
		if (wstr[n] < 0x0 || wstr[n] > 0x10FFFF)
			return (-1);
	n = (fset.prec < 0 || fset.prec > n) ? n : fset.prec;
	if (!fset.minus && fset.zero_pad)
		fill_char_fd(fd, '0', fset.field_w - tlen);
	else if (!fset.minus)
		fill_char_fd(fd, ' ', fset.field_w - wlen);
	ft_putnwstr_fd(wstr, n, fd);
	if (fset.minus)
		fill_wchar_fd(fd, ' ', fset.field_w - wlen);
	if (fset.spec == 'S' && fset.mod > -1 && !str)
		return (-1);
	return (fset.field_w > n ? fset.field_w : n);
}

int			pf_s(int fd, t_flagset fset, char *str)
{
	int		len;

	str = str ? str : "(null)";
	len = ft_strlenz(str);
	len = (fset.prec < 0 || fset.prec > len) ? len : fset.prec;
	if (!fset.minus && fset.zero_pad)
		fill_wchar_fd(fd, '0', fset.field_w - len);
	else if (!fset.minus)
		fill_wchar_fd(fd, ' ', fset.field_w - len);
	ft_putnstr_fd(str, len, fd);
	if (fset.minus)
		fill_wchar_fd(fd, ' ', fset.field_w - len);
	return (fset.field_w > len ? fset.field_w : len);
}
