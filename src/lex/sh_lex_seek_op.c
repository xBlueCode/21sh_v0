//
// Created by xbluecode on 27.05.19.
//

#include "libft.h"
#include "sh_lex.h"

int		sh_lex_seek_op(t_lex *lex, int op)
{
	if (!ft_strchr(SH_LEX_OPSET, lex->in->str[lex->i]))
		return (0);
	if (
		sh_lex_seek_op_sc(lex, op)
		|| sh_lex_seek_op_a(lex, op)
		|| sh_lex_seek_op_o(lex, op)
		|| sh_lex_seek_op_g(lex, op)
		|| sh_lex_seek_op_l(lex, op)
		)
		return (1);
	return (-1);
}


int 	sh_lex_seek_op_sc(t_lex *lex, int op)
{
	if (lex->in->str[lex->i] == ';')
	{
		if (lex->in->str[++lex->i] == ';' && lex->i++)
			lex->st = TSSC2;
		else
			lex->st = TSSC;
		return (1);
	}
	return (0);
}

int 	sh_lex_seek_op_a(t_lex *lex, int op)
{
	if (lex->in->str[lex->i] == '&' && ++lex->i)
	{
		if (lex->in->str[lex->i] == '&' && ++lex->i)
			lex->st = TSA2;
		else
			lex->st = TSA;
		return (1);
	}
	return (0);
}

int 	sh_lex_seek_op_o(t_lex *lex, int op)
{
	if (lex->in->str[lex->i] == '|' && ++lex->i)
	{
		if (lex->in->str[lex->i] == '|' && ++lex->i)
			lex->st = TSO2;
		else
			lex->st = TSO;
		return (1);
	}
	return (0);
}