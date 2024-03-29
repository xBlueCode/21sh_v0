/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_lex_seek_ssh.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 19:14:56 by abbesbes          #+#    #+#             */
/*   Updated: 2019/10/07 19:14:59 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "sh_lex.h"
#include "ft_rl.h"

int		sh_lex_seek_ssh(t_lex *lex, int op)
{
	if (lex->in->str[lex->i] != '(')
		return (0);
	ft_dstrins_ch(lex->scope, -1, RL_SCP_SUBSH);
	lex->i++;
	while (lex->in->str[lex->i] && lex->in->str[lex->i] != ')')
	{
		if (sh_lex_seek_rescope(lex, op)
			|| sh_lex_seek_join(lex, op)
			|| sh_lex_seek_blank(lex, op)
			|| sh_lex_seek_hd(lex, op)
			|| sh_lex_seek_op(lex, op)
			|| sh_lex_seek_ion(lex, op))
			continue ;
		else
			lex->i++;
	}
	if (lex->in->str[lex->i] == ')' && ++lex->i)
		ft_dstrdel_n(lex->scope, -1, 1);
	lex->st = TSPL;
	return (1);
}
