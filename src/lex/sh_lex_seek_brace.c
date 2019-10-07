/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_lex_seek_brace.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 19:14:24 by abbesbes          #+#    #+#             */
/*   Updated: 2019/10/07 19:14:25 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftsh.h"

int 		sh_lex_seek_brace(t_lex *lex, int op)
{
	int off;

	if (lex->in->str[lex->i] != '{')
		return (0);
	off = ++lex->i;
	while (lex->in->str[lex->i] && lex->in->str[lex->i] != '}')
	{
		if (//sh_lex_seek_rescope(lex, op)
			//|| sh_lex_seek_join(lex, op)
			//|| sh_lex_seek_blank(lex, op)
			sh_lex_seek_escape(lex, op)
			|| sh_lex_seek_sq(lex, op)
			|| sh_lex_seek_dq(lex, op)
			|| sh_lex_seek_bq(lex, op)
			|| sh_lex_seek_param(lex, op)
			|| sh_lex_seek_smath(lex, op)
			|| sh_lex_seek_scmd(lex, op)
			//|| sh_lex_seek_op(lex, op)
			//|| sh_lex_seek_wo(lex, op)
			//|| sh_lex_seek_nl(lex, op)
			)
			continue;
			//sh_lex_seek_add(lex, op);
		else
			lex->i++;
	}
	if (!lex->in->str[lex->i])
	{
		lex->i = off;
		return (1);
	}
	lex->st = TSS_BRACE;
	lex->i++;
	return (1);
}
