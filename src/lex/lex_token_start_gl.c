/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_token_start_gl.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 19:26:59 by abbesbes          #+#    #+#             */
/*   Updated: 2019/03/03 19:55:57 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_lex.h"

int		xtk_start_gl(char *in, int off, t_list *tklist)
{
	if (in[off] == '>')
		return (xtk_start_g(in, off, &tklist));
	if (in[off] == '<')
		return (xtk_start_l(in, off, &tklist));
	return (-1);
}

int		xtk_start_g(char *in, int off, t_list *tklist)
{
	if (in[off] == '>')
	{
		if (in[off + 1] == '>' && xtk_add(&tklist, TSG2, NULL))
			return (2);
		if (in[off + 1] == '=' && xtk_add(&tklist, TSG_E, NULL))
			return (2);
		if (in[off + 1] == '&' && xtk_add(&tklist, TSG_A, NULL))
			return (2);
		if (in[off + 1] == '|' && xtk_add(&tklist, TSG_O, NULL))
			return (2);
		if (xtk_add(&tklist, TSG, NULL))
			return (1);
	}
	return (0);
}

int		xtk_start_l(char *in, int off, t_list *tklist)
{
	if (in[off] == '<')
	{
		if (in[off + 1] == '>' && xtk_add(&tklist, TSL_G, NULL))
			return (2);
		if (in[off + 1] == '<')
		{
			if (in[off + 2] == '-' && xtk_add(&tklist, TSL2_M, NULL))
				return (3);
			else if (xtk_add(&tklist, TSL2, NULL))
				return (2);
		}
		if (in[off + 1] == '=' && xtk_add(&tklist, TSL_E, NULL))
			return (2);
		if (in[off + 1] == '&' && xtk_add(&tklist, TSL_A, NULL))
			return (2);
		if (in[off + 1] == '|' && xtk_add(&tklist, TSL_O, NULL))
			return (2);
		if (xtk_add(&tklist, TSL))
			return (1);
	}
	return (0);
}
