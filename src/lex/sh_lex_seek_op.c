//
// Created by xbluecode on 27.05.19.
//

#include "libft.h"
#include "sh_lex.h"

int 			sh_lex_seek_op(t_lex *lex, int op)
{
	if (!ft_strchr(SH_LEX_OPSET, lex->in->str[lex->i]))
		return (0);
	if (lex->in->str[lex->i] == ';')
	{
		lex->i += 1;
		lex->st = TSSC;
	}
	ft_printf("--->  seek_op found ! ... |%s\n", lex->in->str + lex->off);
	return (1);
}
