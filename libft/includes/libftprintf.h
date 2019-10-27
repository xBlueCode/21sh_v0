/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/25 18:57:26 by abbesbes          #+#    #+#             */
/*   Updated: 2019/02/27 20:49:00 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include <wchar.h>

# include "libft.h"

# define CH_START '%'
# define SPEC_SET "diouxXDOUeEfFgGaACcSspnm"

enum	e_modifier
{
	mod_hh,
	mod_h,
	mod_l,
	mod_ll,
	mod_j,
	mod_t,
	mod_z,
	mod_L
};

typedef struct	s_flagset
{
	int		valid;
	int		arg_index;
	int		hash;
	int		zero_pad;
	int		minus;
	int		space;
	int		plus;
	int		apost;
	int		field_w;
	int		prec;
	int		mod;
	int		spec;
}				t_flagset;

typedef struct	s_tokenset
{
	char		*token;
	t_flagset	*fset;
}				t_tokenset;

void			init_flagset(t_flagset *fset);
int				flag_get_arg_index(char *token);
int				flag_get_mod(char *token, t_flagset *fset);
int				flag_get_prim_flags(char *token, t_flagset *fset);
void			token_get_field_w(char *token, t_flagset *fset, va_list *args);
void			token_get_prec(char *jumper, t_flagset *fset, va_list *args);

int				ft_printf(const char *format, ...);
int				ft_dprintf(int fd, const char *format, ...);
int				ft_vdprintf(int fd, const char *format, va_list args);

char			*get_next_token(char *format);
t_list			*format_tokenize(char *format);
int				tokens_process(int fd, t_list *head, va_list *args);
int				print_token(int fd, char *token, t_flagset fset, va_list *args);

void			init_flagset(t_flagset *fset);
int				token_parse(char *token, t_flagset *flagset, va_list *args);

int				pf_percent(int fd, t_flagset fset);
int				pf_cc(int fd, t_flagset fset, va_list *args);
int				pf_c(int fd, t_flagset fset, int ch);
int				pf_wc(int fd, t_flagset fset, unsigned int wch);

int				pf_ss(int fd, t_flagset fset, va_list *args);
int				pf_s(int fd, t_flagset fset, char *str);
int				pf_ws(int fd, t_flagset fset, wint_t *str);

int				pf_int(int fd, t_flagset fset, va_list *args);
int				pf_oxu(int fd, t_flagset fset, va_list *args);
uintmax_t		get_var_oxu(int mod, int spec, va_list *args);
int				pf_u(int fd, t_flagset fset, uintmax_t un);
int				pf_o(int fd, t_flagset fset, uintmax_t un);
int				pf_x(int fd, t_flagset fset, uintmax_t un);
int				pf_p(int fd, t_flagset fset, va_list *args);

int				pf_double(int fd, t_flagset fset, va_list *args);
int				pf_f(int fd, t_flagset fset, double f);

int				pf_badconv(int fd, t_flagset fset);

size_t			fill_wchar_fd(int fd, wint_t ch, int len);
int				fill_char_fd(int fd, int ch, int len);
int				get_uint_len(uintmax_t unum, int base);

#endif
