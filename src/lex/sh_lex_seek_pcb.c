#include "libft.h"
#include "sh_lex.h"

int 	sh_lex_seek_p(t_lex *lex, int op)
{
	(void)op; // TODO: Implement two types of (): subshell and other ...
	if (lex->in->str[lex->i] == '(')
	{
		lex->st = TSPL;
		lex->i++;
		if (lex->ctx == TCTX_FIRSTW)
			ft_dstrins_ch(lex->scope, -1, RL_SCP_SUBSH);
		return (1);
	}
	else if (lex->in->str[lex->i] == ')')
	{
		if (ft_dstrget_ch(lex->scope, -1) == RL_SCP_SCMD)
			return (0);
		if (ft_dstrget_ch(lex->scope, -1) == RL_SCP_SUBSH)
			ft_dstrdel_n(lex->scope, -1, 1);
		lex->st = TSPR;
		lex->i++;
		return (1);
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
	{
		lex->st = TSCBR;
		ft_dstrdel_n(lex->scope, -1, 1);
		lex->i++;
		return (1);
	}
	return (0);
}