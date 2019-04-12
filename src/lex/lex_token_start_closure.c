/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_token_start_closure.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 20:59:26 by abbesbes          #+#    #+#             */
/*   Updated: 2019/03/07 13:48:48 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "sh_lex.h"

int		xtk_start_closure(char *in, int off, t_list **tklist, int m)
{
	if (in[off] == '(')
		if (xtk_add(tklist, in[off + 1] == '(' ? TSPL2 : TSPL, NULL, m))
			return (1 + (in[off + 1] == '('));
	if (in[off] == '[' && xtk_add(tklist, TSBL, NULL, m))
		return (1);
	if (in[off] == '{' && xtk_add(tklist, TSCBL, NULL, m))
		return (1);
	if (in[off] == ')')
		if (xtk_add(tklist, in[off + 1] == ')' ? TSPR2 : TSPR, NULL, m))
			return (1 + (in[off + 1] == ')'));
	if (in[off] == ']' && xtk_add(tklist, TSBR, NULL, m))
		return (1);
	if (in[off] == '}' && xtk_add(tklist, TSCBR, NULL, m))
		return (1);
	return (0);
}
