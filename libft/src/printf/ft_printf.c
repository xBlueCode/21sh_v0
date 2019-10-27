/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/25 18:47:58 by abbesbes          #+#    #+#             */
/*   Updated: 2019/02/28 14:01:32 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int		ft_printf(const char *format, ...)
{
	t_list	*tokens;
	int		pf_ret;
	va_list	args;

	tokens = format_tokenize((char*)format);
	va_start(args, format);
	pf_ret = tokens_process(1, tokens, &args);
	va_end(args);
	ft_lst_free(&tokens, &ft_memdel);
	return (pf_ret);
}

int		ft_dprintf(int fd, const char *format, ...)
{
	t_list	*tokens;
	int		pf_ret;
	va_list	args;

	tokens = format_tokenize((char*)format);
	va_start(args, format);
	pf_ret = tokens_process(fd, tokens, &args);
	va_end(args);
	ft_lst_free(&tokens, &ft_memdel);
	return (pf_ret);
}

int		ft_vdprintf(int fd, const char *format, va_list args)
{
	t_list	*tokens;
	int		pf_ret;
	va_list	args_new;

	tokens = format_tokenize((char*)format);
	va_copy(args_new, args);
	pf_ret = tokens_process(fd, tokens, &args_new);
	va_end(args_new);
	ft_lst_free(&tokens, &ft_memdel);
	return (pf_ret);
}
