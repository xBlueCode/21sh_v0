/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_lex_seek_s.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 19:14:54 by abbesbes          #+#    #+#             */
/*   Updated: 2019/10/07 19:14:55 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "sh_lex.h"

int		sh_lex_seek_param(t_lex *lex, int op)
{
	if (ft_strncmp(lex->in->str + lex->i, "${", 2))
		return (0);
	ft_dstrins_ch(lex->scope, -1, RL_SCP_PARAM);
	lex->i += 2;
	while (lex->in->str[lex->i])
	{
		if (lex->in->str[lex->i] == '}')
		{
			if (sh_lex_seek_cb(lex, op))
				sh_lex_seek_ctx(lex, op);
			else
				break ;
		}
		else if (sh_lex_seek_rescope(lex, op)
			|| sh_lex_seek_join(lex, op) || sh_lex_seek_escape(lex, op)
			|| sh_lex_seek_cb(lex, op) || sh_lex_seek_bq(lex, op))
			continue ;
		else
			lex->i++;
	}
	if (lex->in->str[lex->i] == '}' && ++lex->i)
		ft_dstrdel_n(lex->scope, -1, 1);
	lex->st = TSD_CBL;
	return (1);
}

int		sh_lex_seek_scmd(t_lex *lex, int op)
{
	if (ft_strncmp(lex->in->str + lex->i, "$(", 2))
		return (0);
	ft_dstrins_ch(lex->scope, -1, RL_SCP_SCMD);
	lex->i += 2;
	lex->ctx = TCTX_FIRSTW;
	while ((lex->in->str[lex->i]))
	{
		if (lex->in->str[lex->i] == ')')
		{
			if (sh_lex_seek_p(lex, op))
				sh_lex_seek_ctx(lex, op);
			break ;
		}
		else if (sh_lex_seek_rescope(lex, op) || sh_lex_seek_join(lex, op)
			|| sh_lex_seek_escape(lex, op) || sh_lex_seek_hash(lex, op)
			|| sh_lex_seek_hd(lex, op) || sh_lex_seek_op(lex, op)
			|| sh_lex_seek_p(lex, op) || sh_lex_seek_cb(lex, op)
			|| sh_lex_seek_sq(lex, op) || sh_lex_seek_dq(lex, op)
			|| sh_lex_seek_bq(lex, op) || sh_lex_seek_param(lex, op)
			|| sh_lex_seek_smath(lex, op) || sh_lex_seek_scmd(lex, op))
			sh_lex_seek_ctx(lex, op);
		else
			lex->i++;
	}
	if (lex->in->str[lex->i] == ')' && ++lex->i)
		ft_dstrdel_n(lex->scope, -1, 1);
	lex->st = TSD_PL;
	return (1);
}

int		sh_lex_seek_smath(t_lex *lex, int op)
{
	if (ft_strncmp(lex->in->str + lex->i, "$((", 3))
		return (0);
	ft_dstrins_ch(lex->scope, -1, RL_SCP_SMATH);
	lex->i += 3;
	while (lex->in->str[lex->i] && ft_strncmp(lex->in->str + lex->i, "))", 2))
	{
		if (sh_lex_seek_rescope(lex, op)
			|| sh_lex_seek_join(lex, op)
			|| sh_lex_seek_escape(lex, op)
			|| sh_lex_seek_bq(lex, op)
			|| sh_lex_seek_param(lex, op)
			|| sh_lex_seek_smath(lex, op)
			|| sh_lex_seek_scmd(lex, op))
			continue ;
		else
			lex->i++;
	}
	if (!ft_strncmp("))", lex->in->str + lex->i, 2) && (lex->i += 2))
		ft_dstrdel_n(lex->scope, -1, 1);
	lex->st = TSD_PL2;
	return (1);
}
