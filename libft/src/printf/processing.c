/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 12:51:37 by abbesbes          #+#    #+#             */
/*   Updated: 2019/01/15 17:20:39 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*get_next_token(char *format)
{
	int		i;

	if (!format || !*format)
		return (NULL);
	i = 0;
	if (ft_strchr(format, '$'))
	{
		while (format[i] != '$')
			if (!ft_isdigit(format[i++]))
				return (ft_strndup(format, i + 1));
	}
	while (ft_strchr("#0- +\'*", format[++i]))
		;
	while (ft_isdigit(format[i]) || format[i] == '*')
		i++;
	if (format[i] == '.')
		while (ft_isdigit(format[++i]) || format[i] == '*')
			;
	while (ft_strchr("hljtzqL", format[i]))
		i++;
	while (ft_strchr("#0- +.\'*", format[i]) || ft_isdigit(format[i]))
		i++;
	return (ft_strndup(format, i + 1));
	return (NULL);
}

t_list	*format_tokenize(char *format)
{
	t_list	*head;
	char	*next_format;
	char	*token;

	head = NULL;
	if (!format || !*format)
		return (NULL);
	if (format[0] == CH_START)
	{
		if (!(token = get_next_token(format)))
			return (format_tokenize(format + 1));
		head = ft_lstnew(token, ft_strlen(token) + 1);
		ft_lst_addlast(&head, format_tokenize(format + ft_strlen(token)));
		ft_memdel((void **)&token);
		return (head);
	}
	if (!(next_format = ft_strchr(format, CH_START)))
		return (ft_lstnew(format, ft_strlen(format) + 1));
	token = ft_strndup(format, next_format - format);
	head = ft_lstnew(token, ft_strlen(token) + 1);
	ft_lst_addlast(&head, format_tokenize(next_format));
	ft_memdel((void**)&token);
	return (head);
}

int		print_token(int fd, char *token, t_flagset fset, va_list *args)
{
	int tr;

	tr = -1;
	if (!fset.valid)
	{
		ft_putstr_fd(token, fd);
		tr = ft_strlenz(token);
	}
	else if (ft_strlenz(token) < 2)
		tr = 0;
	else if (fset.spec == 'C' || fset.spec == 'c')
		tr = pf_cc(fd, fset, args);
	else if (fset.spec == 's' || fset.spec == 'S')
		tr = pf_ss(fd, fset, args);
	else if (fset.spec == 'p')
		tr = pf_p(fd, fset, args);
	else if (ft_strchr("diD", fset.spec))
		tr = pf_int(fd, fset, args);
	else if (ft_strchr("ouxOUX", fset.spec))
		tr = pf_oxu(fd, fset, args);
	else if (ft_strchr("fFeEgGaA", fset.spec))
		tr = pf_double(fd, fset, args);
	else
		tr = pf_percent(fd, fset);
	return (tr);
}

int		tokens_process(int fd, t_list *head, va_list *args)
{
	t_flagset	fset;
	int			pt_ret;

	if (!head)
		return (0);
	init_flagset(&fset);
	token_parse((char *)(head->content), &fset, args);
	pt_ret = print_token(fd, (char *)(head->content), fset, args);
	return (pt_ret < 0 ? -1 : pt_ret + tokens_process(fd, head->next, args));
}

int		token_parse(char *token, t_flagset *fset, va_list *args)
{
	char	*jumper;

	if (*token != '%' || !(fset->spec = token[ft_strlen(token) - 1]))
		return (0);
	if ((fset->arg_index = flag_get_arg_index(++token)) > -1)
		token = ft_strchr(token, '$') + 1;
	token += flag_get_prim_flags(token, fset);
	token_get_field_w(token, fset, args);
	if ((jumper = ft_strchr(token, '.')))
		token_get_prec(jumper, fset, args);
	else
		fset->prec = ft_strchr("eEfFgG", fset->spec) ? 6 : -1;
	token = !jumper ? token : jumper + 1;
	while (ft_isdigit(*token) || *token == '.')
		token++;
	flag_get_mod(token, fset);
	while (ft_strchr("hljtzqL", *token))
		token++;
	token += flag_get_prim_flags(token, fset);
	return ((fset->valid = 1));
}
