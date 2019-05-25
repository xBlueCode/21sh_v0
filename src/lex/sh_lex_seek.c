//
// Created by xbluecode on 25.05.19.
//

#include "libft.h"
#include "sh_lex.h"

int 		sh_lex_seek(t_lex *lex, int op)
{

}

int 		sh_lex_seek_all(t_lex *lex, int op)
{
	ssize_t off;

	lex->buf = ft_dstrnew_max(1);
	while (lex->in->str[lex->i])
	{
		off = lex->i;
		lex->state = TSNONE;
		if (sh_lex_seek_join(lex, op)
			|| sh_lex_seek_space(lex, op)
			|| sh_lex_seek_escape(lex, op)
			|| sh_lex_seek_sq(lex, op)
			|| sh_lex_seek_dq(lex, op)
			|| sh_lex_seek_bq(lex, op)
			|| sh_lex_seek_param(lex, op)
			|| sh_lex_seek_smath(lex, op)
			|| sh_lex_seek_scmd(lex, op)
			|| sh_lex_seek_op(lex, op)
			|| sh_lex_seek_wo(lex, op)
			)
			continue;
		//	sh_lex_seek_add(lex, off);
		else
			lex->i++;
	}
}

int 		sh_lex_seek_space(t_lex *lex, int op)
{
	if (!ft_isspace(lex->in->str[lex->i]))
		return (0);
	while (ft_isspace(lex->in->str[lex->i]))
		lex->i++;
	return (1);
}

int 		sh_lex_seek_wo(t_lex *lex, int op)
{
	while (lex->in->str[lex->i])
	{
		if (sh_lex_seek_join(lex, op) || sh_lex_seek_escape(lex, 0))
			continue;
		if (ft_strchr(SH_LEX_SEPSET, lex->in->str[lex->i])
			|| ft_isspace(lex->in->str[lex->i]))
		{
			lex->state = TSW;
			return (1);
		}
		lex->i++;
	}
	return (0);
}