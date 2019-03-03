/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_token_start_arith.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 20:15:05 by abbesbes          #+#    #+#             */
/*   Updated: 2019/03/03 20:32:47 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_lex.h"

int		xtk_start_arith(char *in, int off, t_list *tklist)
{
	if (in[off] == '+')
	{
		if (in[off + 1] == '+' || in[off + 1] == '=')
			if (xtk_add(&tklist, in[off + 1] == '+' ? TSP2 : TSP_E, NULL))
				return (2);
		if (xtk_add(&tklist, TSP, NULL))
			return (1);
	}
	if (in[off] == '-')
	{
		if (in[off + 1] == '-' || in[off + 1] == '=')
			if (xtk_add(&tklist, in[off + 1] == '-' ? TSM2 : TSM_E, NULL))
				return (2);
		if (xtk_add(&tklist, TSP, NULL))
			return (1);
	}
	if (in[off] == '*')
		if (xtk_add(&tklist, in[off + 1] == '=' ? TSAES_E : TSAES, NULL))
			return (1 + (in[off + 1] == '='));
	if (in[off] == '%')
		if (xtk_add(&tklist, in[off + 1] == '=' ? TSMOD_E : TSMOD, NULL))
			return (1 + (in[off + 1] == '='));
	if (in[off] == '/')
		if (xtk_add(&tklist, in[off + 1] == '=' ? TSSH_E : TSSH, NULL))
			return (1 + (in[off + 1] == '='));
}
