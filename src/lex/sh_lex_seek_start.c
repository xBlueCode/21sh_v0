#include "libft.h"
#include "sh_lex.h"

int		sh_lex_seek_start(t_lex *lex, int op)
{
	lex->buf = ft_dstrnew_max(1);
	while (lex->in->str[lex->i])
	{
		//lex->off = lex->i; // not final
		//lex->st = TSNONE; // not final
		//ft_printf("--->  seeking all from %d\n", off);
		if (
			sh_lex_seek_join(lex, op)
			|| sh_lex_seek_space(lex, op)
			|| sh_lex_seek_escape(lex, op)
			//|| sh_lex_seek_sq(lex, op)
			//|| sh_lex_seek_dq(lex, op)
			//|| sh_lex_seek_bq(lex, op)
			//|| sh_lex_seek_param(lex, op)
			//|| sh_lex_seek_smath(lex, op)
			//|| sh_lex_seek_scmd(lex, op)
			|| sh_lex_seek_hd(lex, op)
			|| sh_lex_seek_op(lex, op)
			|| sh_lex_seek_ion(lex, op) // check in other scopes
			|| sh_lex_seek_nl(lex, op)
			|| sh_lex_seek_tok(lex, op)
			)
			//continue;
			sh_lex_seek_add(lex, op);
		else
			lex->i++;
	}
	return (OK);
}

int 		sh_lex_seek_tok(t_lex *lex, int op)
{
	(void)op;
	while (lex->in->str[lex->i])
	{
		if (
			sh_lex_seek_join(lex, op)
			|| sh_lex_seek_escape(lex, op)
			|| sh_lex_seek_sq(lex, op)
			|| sh_lex_seek_dq(lex, op)
			|| sh_lex_seek_bq(lex, op)
			|| sh_lex_seek_param(lex, op)
			|| sh_lex_seek_smath(lex, op)
			|| sh_lex_seek_scmd(lex, op)
			//|| sh_lex_seek_hd(lex, op)
			//|| sh_lex_seek_op(lex, op)
			//|| sh_lex_seek_ion(lex, op) // check in other scopes
			//|| sh_lex_seek_wo(lex, op)
			//|| sh_lex_seek_nl(lex, op)
			)
			continue;
		if (ft_strchr(SH_LEX_SEPSET_X, lex->in->str[lex->i])
			|| ft_isspace(lex->in->str[lex->i]))
		{
			lex->st = TSTOK;
			return (1);
		}
		lex->i++;
	}
	return (op);
}
