/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_double.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 17:29:18 by abbesbes          #+#    #+#             */
/*   Updated: 2019/01/15 14:53:30 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdint.h>

int		pf_double(int fd, t_flagset fset, va_list *args)
{
	if (ft_strchr("fF", fset.spec))
		return (pf_f(fd, fset, (double)va_arg(*args, double)));
	else
		return (0);
}

void	ft_putdouble_base_fd(double db, int prec, int base, int fd)
{
	uintmax_t	un;
	double		fp;

	if (db < 0.0)
	{
		ft_putchar_fd('-', fd);
		ft_putdouble_base_fd(-db, prec, base, fd);
		return ;
	}
	un = (uintmax_t)db;
	ft_putuint_base_fd(un, base, 'A', fd);
	if (prec)
	{
		ft_putchar_fd('.', fd);
		fp = (db - (long)db) * ft_pow(10, prec + 1);
		fp = (long)fp % 10 > 4 ? fp / 10 + 1 : fp / 10;
		ft_putuint_base_fd((int)fp, base, 'A', fd);
	}
}

int		pf_f(int fd, t_flagset fset, double f)
{
	int			t_len;
	long int	un;
	int			pfx;

	un = f < 0.0 ? (long int)(-f) : (long int)f;
	pfx = '\0';
	if (f < 0.0f)
		pfx = '-';
	else if (fset.plus)
		pfx = '+';
	else if (fset.space)
		pfx = ' ';
	t_len = !(!pfx) + get_uint_len(un, 10) + (fset.prec ? fset.prec + 1 : 0);
	if (!fset.minus && !fset.zero_pad)
		fill_char_fd(fd, ' ', fset.field_w - t_len);
	if (pfx)
		ft_putchar_fd(pfx, fd);
	if (!fset.minus && fset.zero_pad)
		fill_char_fd(fd, '0', fset.field_w - t_len);
	ft_putdouble_base_fd(f < 0.0 ? -f : f, fset.prec, 10, fd);
	fill_char_fd(fd, ' ', fset.minus ? fset.field_w - t_len : 0);
	return (fset.field_w > t_len ? fset.field_w : t_len);
}
