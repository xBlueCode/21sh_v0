/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 16:59:59 by abbesbes          #+#    #+#             */
/*   Updated: 2019/04/11 13:56:49 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STR_H
# define FT_STR_H

size_t			ft_strlen(const char *str);
char			*ft_strdup(const char *s1);
char			*ft_strdup_cond(char *str, int (*cond)(int c));
char			*ft_strcpy(char *dst, const char *src);
char			*ft_strcpy_safe(char *dst, const char *src);
char			*ft_strncpy(char *dst, const char *src, size_t len);
char			*ft_strcat(char *s1, const char *s2);
char			*ft_strcat_safe(char *s1, const char *s2);
char			*ft_strncat(char *s1, const char *s2, size_t n);
size_t			ft_strlcat(char *dst, const char *src, size_t dstsize);
char			*ft_strchr(const char *s, int c);
char			*ft_strchr_inv(const char *s, int c);
ssize_t			ft_strichr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
char			*ft_strstr(const char *haystack, const char *needle);
char			*ft_strnstr(const char *haystack, const char *needle,
		size_t len);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);

char			*ft_strnew(size_t size);
void			ft_strdel(char **as);
void			ft_strclr(char *s);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int				ft_strequ(char const *s1, char const *s2);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strjoin_safe(char const *s1, char const *s2);
char			*ft_strjoin_safe_free(char const **s1, char const **s2);
char			*ft_strtrim(char const *s);
char			**ft_strsplit(char const *s, char c);
char			*ft_strconnect(int n, ...);

char			*ft_strndup(const char *s1, size_t n);
char			*ft_strndup_i(const char *s1, size_t n, size_t i);
char			*ft_strndup_free(char **s1, size_t n);

int				ft_count_sep_words(const char *s, char c);
size_t			ft_strlenz(char *str);
char			*ft_strrev(char *str);
int				ft_strcontains(char *str, int c);
size_t			ft_strcontains_all(char *str, int c);

char			*pre_append_char(char *str, int s, char c);

size_t			ft_wstrlenz(wint_t *wstr);

#endif
