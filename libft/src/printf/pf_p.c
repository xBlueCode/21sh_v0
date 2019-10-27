/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_p.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 12:36:53 by abbesbes          #+#    #+#             */
/*   Updated: 2019/01/15 14:20:29 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <wchar.h>

int		pf_p(int fd, t_flagset fset, va_list *args)
{
	uintmax_t	pa;
	int			t_len;

	fset.mod = mod_l;
	fset.hash = 1;
	fset.spec = 'x';
	pa = get_var_oxu(fset.mod, fset.spec, args);
	if (pa)
		return (pf_x(fd, fset, pa));
	t_len = 2 + (fset.prec < 0 ? 1 : fset.prec);
	if (!fset.minus)
	{
		if (fset.prec < 0 && fset.zero_pad)
		{
			ft_putstr_fd("0x", fd);
			fill_char_fd(fd, '0', fset.field_w - t_len);
			fill_char_fd(fd, '0', t_len - 2);
		}
		else
			fill_char_fd(fd, ' ', fset.field_w - t_len);
	}
	ft_putstr_fd(!fset.zero_pad ? "0x" : "\0", fd);
	fill_char_fd(fd, '0', !fset.zero_pad ? t_len - 2 : 0);
	fill_char_fd(fd, ' ', !(!fset.minus) * (fset.field_w - t_len));
	return (fset.field_w > t_len ? fset.field_w : t_len);
}
