/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 17:05:36 by abbesbes          #+#    #+#             */
/*   Updated: 2019/01/22 16:52:04 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MATH_H
# define FT_MATH_H

# define PI 3.14159

int				ft_atoi(const char *str);
char			*ft_itoa(int n);

unsigned int	ft_pgcd(unsigned int a, unsigned int b);
double			ft_sqrt(double x);

int				ft_pow(int base, int expo);

#endif
