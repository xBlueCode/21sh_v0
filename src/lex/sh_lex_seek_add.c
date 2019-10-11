/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_lex_seek_add.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 19:14:17 by abbesbes          #+#    #+#             */
/*   Updated: 2019/10/07 19:14:21 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "sh_lex.h"

static int	sh_lex_seek_add_lexme(t_lex *lex, int op,
		t_token **tok, int *l)
{
	(void)op;
	if (lex->st == TSW || lex->st == TSSQ || lex->st == TSDQ || lex->st == TSBQ
		|| lex->st == TSD_CBL || lex->st == TSD_PL || lex->st == TSD_PL2
		|| lex->st == TSION || lex->st == TSTOK || lex->st == TSTOK_WORD)
	{
		*tok = sh_lex_tok_set(lex->st, lex->off, *l,
			ft_strndup(lex->in->str + lex->off, *l));
		if (sh_lex_tok_last(lex)->t == TSL2 && lex->st == TSTOK)
		{
			ft_dastrins_str(lex->hd_key, -1, (*tok)->val->str);
			ft_dstrins_ch(ft_dastrget_i(lex->hd_key, -1), -1, '\n');
		}
		if (lex->assi > -1)
			(*tok)->assi = lex->assi - lex->off;
		return (1);
	}
	else
		return (0);
}

int			sh_lex_seek_add(t_lex *lex, int op)
{
	int		l;
	t_token	*tok;

	if (lex->st == TSERR)
		return (-1);
	if (lex->st == TSBLANK || lex->st == TSNONE || lex->st == TSALIAS)
	{
		lex->off = lex->i;
		lex->st = TSNONE;
		return (0);
	}
	l = lex->i - lex->off;
	if (!sh_lex_seek_add_lexme(lex, op, &tok, &l))
	{
		if (sh_lex_tok_last(lex)->t == TSL2 && lex->st != TSTOK)
		{
			ft_dstrdel_n(lex->scope, -1, 1);
			lex->st = TSERR;
			return (-1);
		}
		else
			tok = sh_lex_tok_set(lex->st, lex->off, l, NULL);
	}
	sh_lex_tok_add(lex, tok);
	lex->st = TSNONE;
	lex->off = lex->i;
	return (1);
}
