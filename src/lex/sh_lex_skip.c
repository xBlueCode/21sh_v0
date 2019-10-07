/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_lex_skip.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 19:15:02 by abbesbes          #+#    #+#             */
/*   Updated: 2019/10/07 19:15:03 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftsh.h"

int		sh_lex_skip(char *input, t_sh_lex_seeker lex_seeker, int *len)
{
	t_lex	*lex;
	int		ret;

	if (!input || !lex_seeker)
		return ((*len = 0));
	if (sh_lex_init(&lex, input))
		return (0);
	ret = (*lex_seeker)(lex, 0);
	*len = lex->i;
	sh_lex_free(&lex);
	return (ret);
}
