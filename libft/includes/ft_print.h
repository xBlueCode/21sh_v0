/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 16:32:22 by abbesbes          #+#    #+#             */
/*   Updated: 2019/03/23 17:30:52 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINT_H
# define FT_PRINT_H

void			ft_putchar(char c);
void			ft_putnchar(char c, int n);
void			ft_putstr(char const *str);
void			ft_putnstr_fd(const char *str, int n, int fd);
void			ft_putnstr(const char *str, int n);
void			ft_putendl(char const *str);
void			ft_putnbr(int nbr);
void			ft_putchar_fd(char c, int fd);
void			ft_putnchar_fd(char c, int n, int fd);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putnbr_fd(int n, int fd);

void			ft_putuint_base_fd(uintmax_t n, int base, int ch, int fd);

void			ft_putwchar_fd(wchar_t c, int fd);
void			ft_putwchar(wchar_t c);
void			ft_putwstr_fd(wchar_t *str, int fd);
void			ft_putnwstr_fd(wint_t *wstr, int n, int fd);

#endif
