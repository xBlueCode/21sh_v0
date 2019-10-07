/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_lex_seek_ctx.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 19:14:29 by abbesbes          #+#    #+#             */
/*   Updated: 2019/10/07 19:14:32 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "sh_lex.h"

int 	sh_lex_seek_ctx(t_lex *lex, int op)
{
	(void)op;
	if (lex->st == TSBLANK)
		return (0);
	else if (lex->st == TSSTART
		||	lex->st == TSSC
		|| lex->st == TSA || lex->st == TSA2
		|| lex->st == TSO || lex->st == TSO2
		|| lex->st == TSPL || lex->st == TSNL
		)
		lex->ctx = TCTX_FIRSTW;
	else
		lex->ctx = TCTX_NONE;
	return (1);
}

int 	sh_lex_ctx_last(t_lex *lex, int op)
{
	(void)op;
	return (sh_lex_tok_ctx(sh_lex_tok_last(lex)));
}

int 	sh_lex_tok_ctx(t_token *token)
{
	if (!token)
		return (TCTX_NONE);
	if (token->t == TSBLANK)
		return (TCTX_NONE);
	else if (token->t == TSSTART || token->t == TSNONE // TODO: re-Check TSNONE
			 ||	token->t == TSSC
			 || token->t == TSA || token->t == TSA2
			 || token->t == TSO || token->t == TSO2
			 || token->t == TSPL || token->t == TSNL
			)
		return (TCTX_FIRSTW);
	else
		return (TCTX_NONE);
}
