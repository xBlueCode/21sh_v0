//
// Created by xbluecode on 27.05.19.
//

#include "libft.h"
#include "sh_lex.h"

int 	sh_lex_seek_op_g(t_lex *lex, int op)
{
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
