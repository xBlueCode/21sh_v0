/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_oxu.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 20:14:56 by abbesbes          #+#    #+#             */
/*   Updated: 2019/01/15 14:28:37 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdint.h>

int			pf_oxu(int fd, t_flagset fset, va_list *args)
{
	if (ft_strchr("uU", fset.spec))
		return (pf_u(fd, fset, get_var_oxu(fset.mod, fset.spec, args)));
	else if (ft_strchr("oO", fset.spec))
		return (pf_o(fd, fset, get_var_oxu(fset.mod, fset.spec, args)));
	else if (ft_strchr("xX", fset.spec))
		return (pf_x(fd, fset, get_var_oxu(fset.mod, fset.spec, args)));
	return (-1);
}

uintmax_t	get_var_oxu(int mod, int spec, va_list *args)
{
	if (mod == mod_l || ft_strchr("OU", spec))
		return ((unsigned long)va_arg(*args, long int));
	if (mod == mod_hh)
		return ((unsigned char)va_arg(*args, unsigned int));
	if (mod == mod_h)
		return ((unsigned short)va_arg(*args, unsigned int));
	if (mod == mod_ll)
		return ((unsigned long long)va_arg(*args, unsigned long long int));
	if (mod == mod_j)
		return ((uintmax_t)va_arg(*args, uintmax_t));
	if (mod == mod_z)
		return ((size_t)va_arg(*args, size_t));
	return ((unsigned int)va_arg(*args, int));
}

int			pf_o(int fd, t_flagset fset, uintmax_t un)
{
	int n_len;
	int t_len;

	n_len = get_uint_len(un, 8) - (fset.prec > -1 && !un);
	t_len = n_len + (fset.hash ? 1 : 0);
	t_len = fset.prec > t_len ? fset.prec : t_len;
	t_len = t_len - (fset.hash && fset.prec < 0 && !un);
	if (!fset.minus)
	{
		if (fset.prec < 0 && fset.zero_pad)
			fill_char_fd(fd, '0', fset.field_w - t_len);
		else
			fill_char_fd(fd, ' ', fset.field_w - t_len);
	}
	fill_char_fd(fd, '0', t_len - n_len);
	if (!(!fset.prec && !un) && n_len)
		ft_putuint_base_fd(un, 8, 0, fd);
	if (fset.minus)
		fill_char_fd(fd, ' ', fset.field_w - t_len);
	return ((fset.field_w > t_len ? fset.field_w : t_len));
}

int			pf_x(int fd, t_flagset fset, uintmax_t un)
{
	int		n_len;
	int		t_len;
	char	*prefix;

	n_len = get_uint_len(un, 16) - (!fset.prec && !un);
	prefix = "\0";
	if (fset.hash && un)
		prefix = (fset.spec == 'x') ? "0x" : "0X";
	t_len = (fset.prec > n_len ? fset.prec : n_len) + (!*prefix ? 0 : 2);
	if (!fset.minus && (fset.prec < 0 && fset.zero_pad))
	{
		ft_putstr_fd(prefix, fd);
		fill_char_fd(fd, '0', fset.field_w - t_len);
	}
	else if (!fset.minus)
		fill_char_fd(fd, ' ', fset.field_w - t_len);
	ft_putstr_fd(fset.minus ||
			!(fset.prec < 0 && fset.zero_pad) ? prefix : "", fd);
	fill_char_fd(fd, '0', t_len - n_len - 2 * !(!*prefix));
	if (!(!fset.prec && !un))
		ft_putuint_base_fd(un, 16, fset.spec == 'x' ? 'a' : 'A', fd);
	fill_char_fd(fd, ' ', !(!fset.minus) * (fset.field_w - t_len));
	return (fset.field_w > t_len ? fset.field_w : t_len);
}

int			pf_u(int fd, t_flagset fset, uintmax_t un)
{
	int	t_len;

	t_len = get_uint_len(un, 10);
	t_len = fset.prec > t_len ? fset.prec : t_len;
	t_len = t_len - (!fset.prec && !un);
	if (!fset.minus)
	{
		if (fset.prec < 0 && fset.zero_pad)
			fill_char_fd(fd, '0', fset.field_w - t_len);
		else
			fill_char_fd(fd, ' ', fset.field_w - t_len);
	}
	fill_char_fd(fd, '0', t_len - get_uint_len(un, 10));
	if (!(!fset.prec && !un))
		ft_putuint_base_fd(un, 10, 0, fd);
	if (fset.minus && fset.field_w - t_len > 0)
		fill_wchar_fd(fd, ' ', fset.field_w - t_len);
	return (fset.field_w > t_len ? fset.field_w : t_len);
}
