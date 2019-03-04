/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_token_start_enao.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 19:48:11 by abbesbes          #+#    #+#             */
/*   Updated: 2019/03/04 17:03:47 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "sh_lex.h"

int		xtk_start_enao(char *in, int off, t_list **tklist)
{
	if (in[off] == '=')
	{
		if (in[off + 1] == '=' && xtk_add(tklist, TSE2, NULL))
			return (2);
		if (xtk_add(tklist, TSE, NULL))
			return (1);
	}
	if (in[off] == '!' && xtk_add(tklist, TSN, NULL))
		return (1);
	if (in[off] == '&')
	{
		if (in[off + 1] == '>' && xtk_add(tklist, TSA_G, NULL))
			return (2);
		if (in[off + 1] == '&' && xtk_add(tklist, TSA2, NULL))
			return (2);
		if (xtk_add(tklist, TSA, NULL))
			return (1);
	}
	if (in[off] == '|')
		if (xtk_add(tklist, in[off + 1] == '|' ? TSO2 : TSO, NULL))
			return (in[off + 1] == '|' ? 2 : 1);
	return (0);
}
