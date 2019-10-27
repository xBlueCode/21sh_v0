/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 06:26:25 by abbesbes          #+#    #+#             */
/*   Updated: 2019/01/15 15:31:03 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		flag_get_arg_index(char *token)
{
	if (ft_strchr(token, '$'))
		return (ft_atoi(token));
	return (-1);
}

int		flag_get_mod(char *token, t_flagset *fset)
{
	while (ft_isdigit(*token))
		token++;
	while (ft_strchr("hljtzL", *token))
	{
		if (*token == 'h' && (fset->mod < mod_hh && fset->mod < mod_h))
			fset->mod = *(token + 1) == 'h' && token++ ? mod_hh : mod_h;
		if (*token == 'l' && (fset->mod < mod_ll && fset->mod < mod_l))
			fset->mod = *(token + 1) == 'l' && token++ ? mod_ll : mod_l;
		if (*token == 'j')
			fset->mod = mod_j > fset->mod ? mod_j : fset->mod;
		if (*token == 't')
			fset->mod = mod_t > fset->mod ? mod_t : fset->mod;
		if (*token == 'z')
			fset->mod = mod_z > fset->mod ? mod_z : fset->mod;
		if (*token == 'L')
			fset->mod = mod_L > fset->mod ? mod_L : fset->mod;
		token++;
	}
	return (0);
}

int		flag_get_prim_flags(char *token, t_flagset *fset)
{
	int nb;

	nb = 0;
	while (*token && ft_strchr("#0- +'", *token))
	{
		fset->hash = (*token == '#') ? 1 : fset->hash;
		fset->zero_pad = (*token == '0') ? 1 : fset->zero_pad;
		fset->minus = (*token == '-') ? 1 : fset->minus;
		fset->space = (*token == ' ') ? 1 : fset->space;
		fset->plus = (*token == '+') ? 1 : fset->plus;
		fset->apost = (*token == '\'') ? 1 : fset->apost;
		token++;
		nb++;
	}
	return (nb);
}

void	token_get_field_w(char *token, t_flagset *fset, va_list *args)
{
	char *aest;

	if (!(aest = ft_strchr(token, '*')))
		fset->field_w = ft_atoi(token);
	else if (*(aest - 1) != '.')
	{
		fset->field_w = (int)va_arg(*args, int);
		fset->minus = fset->field_w < 0 ? 1 : fset->minus;
		fset->field_w = fset->field_w < 0 ? -fset->field_w : fset->field_w;
		while (*aest == '*')
			aest++;
		if (ft_isdigit(*aest))
			fset->field_w = ft_atoi(aest);
	}
	else
		fset->field_w = ft_atoi(token);
}

void	token_get_prec(char *jumper, t_flagset *fset, va_list *args)
{
	int prec;

	jumper++;
	prec = -1;
	if (*jumper == '*')
	{
		prec = (int)va_arg(*args, int);
		jumper++;
	}
	else if (ft_isdigit(*jumper))
		prec = ft_atoi(jumper);
	else
		prec = ft_strchr("eEfFgG", fset->spec) ? 6 : 0;
	fset->prec = prec < -1 ? -1 : prec;
}
