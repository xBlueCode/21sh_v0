/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_int.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 20:48:34 by abbesbes          #+#    #+#             */
/*   Updated: 2019/01/15 14:58:42 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdint.h>

static intmax_t	get_var_di(int mod, int spec, va_list *args)
{
	if (mod == mod_l || spec == 'D')
		return ((long)va_arg(*args, long int));
	if (mod == mod_hh)
		return ((signed char)va_arg(*args, int));
	if (mod == mod_h)
		return ((short)va_arg(*args, int));
	if (mod == mod_ll)
		return ((long long)va_arg(*args, long long int));
	if (mod == mod_j)
		return ((intmax_t)va_arg(*args, intmax_t));
	if (mod == mod_z)
		return ((size_t)va_arg(*args, size_t));
	return ((int)va_arg(*args, int));
}

static int		handle_dzero_int(int fd, t_flagset fset, int pfx)
{
	if (!fset.minus)
	{
		fill_char_fd(fd, ' ', fset.field_w - 1 + !pfx);
		if (pfx)
			ft_putchar_fd(pfx, fd);
		return (fset.field_w > 1 ? fset.field_w : 1 - !pfx);
	}
	if (pfx)
		ft_putchar_fd(pfx, fd);
	if (fset.minus && fset.field_w > 1)
		fill_char_fd(fd, ' ', fset.field_w - 1 + !pfx);
	return (fset.field_w > 1 ? fset.field_w : 1 - !pfx);
}

static void		pf_int_start(int fd, t_flagset fset, int n_len, char pfx)
{
	int t_len;

	t_len = fset.prec < n_len + 1 - !pfx ?
		n_len + 1 - !pfx : fset.prec + 1 - !pfx;
	if (!fset.minus)
	{
		if (fset.prec < 0 && fset.zero_pad)
		{
			if (pfx)
				ft_putchar_fd(pfx, fd);
			fill_char_fd(fd, '0', fset.field_w - t_len);
		}
		else
		{
			fill_char_fd(fd, ' ', fset.field_w - t_len);
			if (pfx)
				ft_putchar_fd(pfx, fd);
		}
	}
	if (fset.minus && pfx)
		ft_putchar_fd(pfx, fd);
	fill_char_fd(fd, '0', fset.prec - n_len);
}

int				pf_int(int fd, t_flagset fset, va_list *args)
{
	intmax_t	n;
	uintmax_t	un;
	int			n_len;
	int			t_len;
	char		pfx;

	n = get_var_di(fset.mod, fset.spec, args);
	un = n < 0 ? -n : n;
	n_len = get_uint_len(un, 10);
	pfx = '\0';
	if (n < 0)
		pfx = '-';
	else if (fset.plus)
		pfx = '+';
	else if (fset.space)
		pfx = ' ';
	t_len = fset.prec < n_len + 1 - !pfx ?
		n_len + 1 - !pfx : fset.prec + 1 - !pfx;
	if (fset.prec == 0 && !un)
		return (handle_dzero_int(fd, fset, pfx));
	pf_int_start(fd, fset, n_len, pfx);
	ft_putuint_base_fd(un, 10, 0, fd);
	if (fset.minus)
		fill_char_fd(fd, ' ', fset.field_w - t_len);
	return (fset.field_w > t_len ? fset.field_w : t_len);
}
