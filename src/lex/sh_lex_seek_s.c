//
// Created by xbluecode on 06.06.19.
//

#include "libft.h"
#include "sh_lex.h"

int 			sh_lex_seek_param(t_lex *lex, int op)
{
	if (ft_strncmp(lex->in->str + lex->i, "${", 2))
		return (0);
	lex->i += 2;
	while (lex->in->str[lex->i] && lex->in->str[lex->i] != '}')
	{
		if (sh_lex_seek_join(lex, op)
			//|| sh_lex_seek_space(lex, op)
			|| sh_lex_seek_escape(lex, op)
			//|| sh_lex_seek_sq(lex, op)
			//|| sh_lex_seek_dq(lex, op)
			|| sh_lex_seek_bq(lex, op)
			//|| sh_lex_seek_param(lex, op)
			//|| sh_lex_seek_smath(lex, op)
			//|| sh_lex_seek_scmd(lex, op)
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
		SH_LEX_RETERR(lex, TSCBR)
	lex->i++;
	lex->st = TSCBR;
	return (1);
}
