/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_lex_seek_q.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 19:14:48 by abbesbes          #+#    #+#             */
/*   Updated: 2019/10/07 19:14:49 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "sh_lex.h"

int		sh_lex_seek_sq(t_lex *lex, int op)
{
	(void)op;
	if (lex->in->str[lex->i] != '\'')
		return (0);
	ft_dstrins_ch(lex->scope, -1, RL_SCP_SQ);
	while (lex->in->str[lex->i] && lex->in->str[++lex->i] != '\'')
		;
	if (lex->in->str[lex->i] && ++lex->i)
		ft_dstrdel_n(lex->scope, -1, 1);
	lex->st = TSSQ;
	return (1);
}

int		sh_lex_seek_bq(t_lex *lex, int op)
{
	(void)op;
	if (lex->in->str[lex->i] != '`')
		return (0);
	ft_dstrins_ch(lex->scope, -1, RL_SCP_BQ);
	while (lex->in->str[lex->i] && lex->in->str[++lex->i] != '`')
		;
	if (lex->in->str[lex->i] && ++lex->i)
		ft_dstrdel_n(lex->scope, -1, 1);
	lex->st = TSBQ;
	return (1);
}

int		sh_lex_seek_dq(t_lex *lex, int op)
{
	if (lex->in->str[lex->i] != '"')
		return (0);
	ft_dstrins_ch(lex->scope, -1, RL_SCP_DQ);
	lex->i++;
	while (lex->in->str[lex->i] && lex->in->str[lex->i] != '"')
	{
		if (sh_lex_seek_rescope(lex, op)
			|| sh_lex_seek_join(lex, op)
			|| sh_lex_seek_escape(lex, op)
			|| sh_lex_seek_bq(lex, op)
			|| sh_lex_seek_param(lex, op)
			|| sh_lex_seek_smath(lex, op)
			|| sh_lex_seek_scmd(lex, op))
			continue;
		else
			lex->i++;
	}
	if (lex->in->str[lex->i] && ++lex->i)
		ft_dstrdel_n(lex->scope, -1, 1);
	lex->st = TSDQ;
	return (1);
}
