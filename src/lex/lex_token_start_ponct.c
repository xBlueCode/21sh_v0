/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_token_start_ponct.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 20:36:33 by abbesbes          #+#    #+#             */
/*   Updated: 2019/03/04 20:20:16 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "sh_lex.h"

/*
** Not sure about this
*/

int		xtk_start_ponct(char *in, int off, t_list **tklist)
{
	if (in[off] == '\\')
		return (xtk_start_esc(in, off, tklist));
	if (in[off] == '$')
	{
		if (in[off + 1] == '(')
		{
			if (in[off + 2] == '(' && xtk_add(tklist, TSD_PL2, NULL))
				return (3);
			else if (xtk_add(tklist, TSD_PL, NULL))
				return (2);
		}
		if (in[off + 1] == '{' && xtk_add(tklist, TSD_CBL, NULL))
			return (2);
		if (xtk_add(tklist, TSD, NULL))
			return (1);
	}
	if (in[off] == ';')
		if (xtk_add(tklist, in[off + 1] == ';' ? TSSC2 : TSSC, NULL))
			return (in[off + 1] == ';' ? 2 : 1);
	if (in[off] == '\n' && xtk_add(tklist, TSNL, NULL))
		return (1);
	return (0);
}

int		xtk_start_esc(char *in, int off, t_list **tklist)
{
	if (in[off] == '\\'
			&& xtk_add(tklist, TSBSH, ft_strndup_i(in, 1, off + 1)))
		return (2);
	return (0);
}
