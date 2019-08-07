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
	else if (lex->in->str[lex->i] == ')'
		&& ft_dstrget_ch(lex->scope, -1) == RL_SCP_SUBSH)
	{
		if (ft_dstrget_ch(lex->scope, -1) == RL_SCP_SUBSH)
		{
			lex->st = TSPR;
			ft_dstrdel_n(lex->scope, -1, 1);
			lex->i++;
			return (1);
		}
	}
	return (0);
}

int 	sh_lex_seek_cb(t_lex *lex, int op)
{
	(void)op;
	if (!lex->in->str[lex->i])
		return (0);
	if (lex->in->str[lex->i] == '{' && lex->ctx == TCTX_FIRSTW)
	{
		lex->st = TSCBL;
		ft_dstrins_ch(lex->scope, -1, RL_SCP_CURSH);
		lex->i++;
		return (1);
	}
	else if (lex->in->str[lex->i] == '}'
		&& sh_lex_tok_isdelim(lex->in->str[lex->i + 1]))
	//		 && ft_dstrget_ch(lex->scope, -1) == RL_SCP_CURSH)
	{
	//	if (ft_dstrget_ch(lex->scope, -1) == RL_SCP_CURSH)
	//	{
			lex->st = TSCBR;
			ft_dstrdel_n(lex->scope, -1, 1);
			lex->i++;
			return (1);
	//	}
	}
	return (0);
}