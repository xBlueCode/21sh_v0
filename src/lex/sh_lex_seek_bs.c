//
// Created by xbluecode on 26.05.19.
//

#include "libft.h"
#include "sh_lex.h"

int 		sh_lex_seek_escape(t_lex *lex, int op)
{
	if (lex->in->str[lex->i] == '\\' && lex->in->str[lex->i + 1] != '\n')
	{
		if (op == 1)
			ft_dstrdel_n(lex->in, lex->i++, 1);
		else
			lex->i += 2;
		return (1);
	}
	return (0);
}

int 		sh_lex_seek_join(t_lex *lex, int op)
{
	if (lex->in->str[lex->i] == '\\' && lex->in->str[lex->i + 1] == '\n')
	{
		ft_dstrdel_n(lex->in, lex->i, 2);
		return (1);
	}
	return (0);
}

int 		sh_lex_seek_nl(t_lex *lex, int op)
{
	if (lex->in->str[lex->i] != '\n')
		return (0);
	lex->st = TSNL;
	lex->i++;
	return (1);
}
