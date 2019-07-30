#include "libft.h"
#include "sh_lex.h"
#include "ft_rl.h"

int 			sh_lex_seek_ssh(t_lex *lex, int op) {
	if (lex->in->str[lex->i] != '(')
		return (0);
	ft_dstrins_ch(lex->scope, -1, RL_SCP_SUBSH);
	lex->i++;
	while (lex->in->str[lex->i] && lex->in->str[lex->i] != ')')
	{
		if (sh_lex_seek_rescope(lex, op)
			|| sh_lex_seek_join(lex, op)
			|| sh_lex_seek_space(lex, op)
			//|| sh_lex_seek_escape(lex, op)
			//|| sh_lex_seek_sq(lex, op)
			//|| sh_lex_seek_dq(lex, op)
			//|| sh_lex_seek_bq(lex, op)
			//|| sh_lex_seek_param(lex, op)
			//|| sh_lex_seek_smath(lex, op)
			//|| sh_lex_seek_scmd(lex, op)
			|| sh_lex_seek_hd(lex, op)
			|| sh_lex_seek_op(lex, op)
			|| sh_lex_seek_ion(lex, op)
			//|| sh_lex_seek_wo(lex, op)
			//|| sh_lex_seek_nl(lex, op)
			|| sh_lex_seek_tok(lex, op)
			)
			continue;
			//sh_lex_seek_add(lex, op);
		else
			lex->i++;
	}
	//if (!lex->in->str[lex->i])
	//	SH_LEX_RETERR(lex, TSDQ)
	if (lex->in->str[lex->i] == ')' && ++lex->i)
		ft_dstrdel_n(lex->scope, -1, 1);
	//lex->i++;
	lex->st = TSPL;
	return (1);
}
