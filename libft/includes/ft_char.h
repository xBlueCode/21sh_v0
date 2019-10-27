/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 16:29:55 by abbesbes          #+#    #+#             */
/*   Updated: 2019/01/22 16:47:59 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CHAR_H
# define FT_CHAR_H

int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_toupper(int c);
int				ft_tolower(int c);
int				ft_isspace(int c);
int				ft_isblank(int c);
int				ft_iscntrl(int c);
int				ft_islower(int c);
int				ft_isupper(int c);

int				ft_wchar_len(wint_t wch);

#endif
