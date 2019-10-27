/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 15:27:51 by abbesbes          #+#    #+#             */
/*   Updated: 2019/01/15 15:28:02 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		init_flagset(t_flagset *fset)
{
	fset->valid = 0;
	fset->arg_index = -1;
	fset->hash = 0;
	fset->zero_pad = 0;
	fset->minus = 0;
	fset->space = 0;
	fset->plus = 0;
	fset->apost = 0;
	fset->field_w = -1;
	fset->prec = -1;
	fset->mod = -1;
	fset->spec = 0;
}
