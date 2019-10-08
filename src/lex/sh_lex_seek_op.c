/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_lex_seek_op.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 23:24:57 by abbesbes          #+#    #+#             */
/*   Updated: 2019/10/08 23:24:59 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "sh_lex.h"

int		sh_lex_seek_op(t_lex *lex, int op)
{
	if (sh_lex_seek_op_bang(lex, op))
		return (1);
	if (!ft_strchr(SH_LEX_OPSET, lex->in->str[lex->i]))
		return (0);
	if (
		sh_lex_seek_op_sc(lex, op)
		|| sh_lex_seek_op_a(lex, op)
		|| sh_lex_seek_op_o(lex, op)
		|| sh_lex_seek_op_g(lex, op)
		|| sh_lex_seek_op_l(lex, op))
		return (1);
	return (-1);
}

int		sh_lex_seek_op_sc(t_lex *lex, int op)
{
	(void)op;
	if (lex->in->str[lex->i] == ';')
	{
		if (lex->in->str[++lex->i] == ';' && ++lex->i)
			lex->st = TSSC2;
		else
		{
			lex->st = TSSC;
		}
		return (1);
	}
	return (0);
}

int		sh_lex_seek_op_a(t_lex *lex, int op)
{
	(void)op;
	if (lex->in->str[lex->i] == '&' && ++lex->i)
	{
		if (lex->in->str[lex->i] == '&' && ++lex->i)
		{
			lex->st = TSA2;
			ft_dstrins_ch(lex->scope, -1, RL_SCP_AND);
		}
		else
			lex->st = TSA;
		return (1);
	}
	return (0);
}

int		sh_lex_seek_op_o(t_lex *lex, int op)
{
	(void)op;
	if (lex->in->str[lex->i] == '|' && ++lex->i)
	{
		if (lex->in->str[lex->i] == '|' && ++lex->i)
		{
			lex->st = TSO2;
			ft_dstrins_ch(lex->scope, -1, RL_SCP_OR);
		}
		else
		{
			if (lex->in->str[lex->i] == '&' && ++lex->i)
				lex->st = TSO_A;
			else
				lex->st = TSO;
			ft_dstrins_ch(lex->scope, -1, RL_SCP_PIPE);
		}
		return (1);
	}
	return (0);
}

int		sh_lex_seek_op_bang(t_lex *lex, int op)
{
	(void)op;
	if (lex->in->str[lex->i] == '!'
		&& lex->ctx == TCTX_FIRSTW
		&& ft_isblank(lex->in->str[lex->i + 1]))
	{
		lex->i++;
		lex->st = TSBANG;
		return (1);
	}
	return (0);
}
