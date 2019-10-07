/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_lex_seek_op_gl.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 19:14:42 by abbesbes          #+#    #+#             */
/*   Updated: 2019/10/07 19:14:45 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "sh_lex.h"

int 	sh_lex_seek_op_g(t_lex *lex, int op)
{
	(void)op;
	if (lex->in->str[lex->i] == '>' && ++lex->i)
	{
		if (lex->in->str[lex->i] == '>' && ++lex->i)
			lex->st = TSG2;
		else if (lex->in->str[lex->i] == '&' && ++lex->i)
			lex->st = TSG_A;
		else if (lex->in->str[lex->i] == '|' && ++lex->i)
			lex->st = TSG_O;
		else
			lex->st = TSG;
		return (1);
	}
	return (0);
}

int 	sh_lex_seek_op_l(t_lex *lex, int op)
{
	(void)op;
	if (lex->in->str[lex->i] == '<' && ++lex->i)
	{
		if (lex->in->str[lex->i] == '&' && ++lex->i)
			lex->st = TSL_A;
		else if (lex->in->str[lex->i] == '>' && ++lex->i)
			lex->st = TSL_G;
		else
			lex->st = TSL;
		return (1);
	}
	return (0);
}
