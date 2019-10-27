/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pgcd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 11:08:16 by exam              #+#    #+#             */
/*   Updated: 2018/11/21 11:03:07 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_pgcd(unsigned int a, unsigned int b)
{
	unsigned int r;

	if (b > a)
		ft_swap(&a, &b);
	while ((r = a % b))
	{
		a = b;
		b = r;
	}
	return (b);
}
