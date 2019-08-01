#include "libft.h"
#include "sh_lex.h"

int 	sh_lex_seek_p(t_lex *lex, int op)
{
	(void)op;
	if (lex->in->str[lex->i] == '(' && lex->ctx == TCTX_FIRSTW)
	{
		lex->st = TSPL;
		ft_dstrins_ch(lex->scope, -1, RL_SCP_SUBSH);
		lex->i++;
		return (1);
	}
	else if (lex->in->str[lex->i] == ')')
	{
		if (ft_dstrget_ch(lex->scope, -1) != RL_SCP_SUBSH)
		{
			lex->st = TSERR;
			lex->i++;
			return (1);
		}
		lex->st = TSPR;
		ft_dstrdel_n(lex->scope, -1, 1);
		lex->i++;
		return (1);
	}
	return (0);
}