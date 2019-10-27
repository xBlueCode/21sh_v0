/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/04 12:49:20 by abbesbes          #+#    #+#             */
/*   Updated: 2018/11/23 20:07:48 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_isspc(int c)
{
	return (c == '\t' || c == '\n' || c == '\v'
			|| c == '\f' || c == '\r' || c == ' ');
}

static int	ft_isdig(int c)
{
	return (c >= '0' && c <= '9');
}

int			ft_atoi(const char *str)
{
	int			i;
	long long	nat;
	int			ichara;

	i = 0;
	nat = 0;
	ichara = 1;
	while (ft_isspc(*(str)))
		str++;
	if (*str == '+')
		str++;
	else if (*str == '-')
		ichara = -1 + 0 * *str++;
	while (*str && ft_isdig(*str))
	{
		nat = nat * 10 + *str++ - '0';
		if (nat > 922337203685477580)
			return (-1 + (ichara == -1));
	}
	return (int)(nat * ichara);
}
