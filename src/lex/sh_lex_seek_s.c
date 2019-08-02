//
// Created by xbluecode on 06.06.19.
//

#include "libft.h"
#include "sh_lex.h"

int 			sh_lex_seek_param(t_lex *lex, int op)
{
	if (ft_strncmp(lex->in->str + lex->i, "${", 2))
		return (0);
	ft_dstrins_ch(lex->scope, -1, RL_SCP_PARAM);
	lex->i += 2;
	while (lex->in->str[lex->i] && lex->in->str[lex->i] != '}')
	{
		if (sh_lex_seek_rescope(lex, op)
			|| sh_lex_seek_join(lex, op)
			//|| sh_lex_seek_space(lex, op)
			|| sh_lex_seek_escape(lex, op)
			//|| sh_lex_seek_sq(lex, op)
			//|| sh_lex_seek_dq(lex, op)
			|| sh_lex_seek_bq(lex, op)
			)
			continue;
			//sh_lex_seek_add(lex, op);
		else
			lex->i++;
	}
	if (lex->in->str[lex->i] == '}' && ++lex->i)
		ft_dstrdel_n(lex->scope, -1, 1);
	//if (!lex->in->str[lex->i])
	//	SH_LEX_RETERR(lex, TSD_CBL)
	//lex->i++;
	lex->st = TSD_CBL;
	return (1);
}

int 			sh_lex_seek_scmd(t_lex *lex, int op)
{
	if (ft_strncmp(lex->in->str + lex->i, "$(", 2))
		return (0);
	ft_dstrins_ch(lex->scope, -1, RL_SCP_SCMD);
	lex->i += 2;
	lex->ctx = TCTX_FIRSTW;
	//while ((lex->in->str[lex->i] && lex->in->str[lex->i] != ')'))
		//|| ft_dstrget_ch(lex->scope, -1) == RL_SCP_SUBSH)
	while ((lex->in->str[lex->i]))
	{
		if (lex->in->str[lex->i] == ')')
		{
			if (sh_lex_seek_p(lex, op))
				sh_lex_seek_ctx(lex, op);
			else
				break;
		}
		else if (sh_lex_seek_rescope(lex, op)
			|| sh_lex_seek_join(lex, op)
			//|| sh_lex_seek_space(lex, op)
			|| sh_lex_seek_escape(lex, op)
			|| sh_lex_seek_hd(lex, op)
			|| sh_lex_seek_op(lex, op)
			|| sh_lex_seek_p(lex, op)
			|| sh_lex_seek_sq(lex, op)
			|| sh_lex_seek_dq(lex, op)
			|| sh_lex_seek_bq(lex, op)
			|| sh_lex_seek_param(lex, op)
			|| sh_lex_seek_smath(lex, op)
			//|| sh_lex_seek_ssh(lex, op)
			|| sh_lex_seek_scmd(lex, op)
			)
			//continue;
		{
			//if (lex->st != TSNONE)
			sh_lex_seek_ctx(lex, op);
		}
			//sh_lex_seek_add(lex, op);
		else
			lex->i++;
	}
	if (lex->in->str[lex->i] == ')' && ++lex->i)
		ft_dstrdel_n(lex->scope, -1, 1);
	//if (!lex->in->str[lex->i])
	//	SH_LEX_RETERR(lex, TSD_PL)
	//lex->i++;
	lex->st = TSD_PL;
	return (1);
}

int 			sh_lex_seek_smath(t_lex *lex, int op)
{
	if (ft_strncmp(lex->in->str + lex->i, "$((", 3))
		return (0);
	ft_dstrins_ch(lex->scope, -1, RL_SCP_SMATH);
	lex->i += 3;
	while (lex->in->str[lex->i] && ft_strncmp(lex->in->str + lex->i, "))", 2))
	{
		if (sh_lex_seek_rescope(lex, op)
			|| sh_lex_seek_join(lex, op)
			//|| sh_lex_seek_space(lex, op)
			|| sh_lex_seek_escape(lex, op)
			//|| sh_lex_seek_sq(lex, op)
			//|| sh_lex_seek_dq(lex, op)
			|| sh_lex_seek_bq(lex, op)
			|| sh_lex_seek_param(lex, op)
			|| sh_lex_seek_smath(lex, op)
			|| sh_lex_seek_scmd(lex, op)
			)
			continue;
			//sh_lex_seek_add(lex, op);
		else
			lex->i++;
	}
	//if (!lex->in->str[lex->i])
	//	SH_LEX_RETERR(lex, TSD_PL2)
	//if (lex->in->str[lex->i])
	//	ft_dstrdel_n(lex->scope, -1, 1);
	if (!ft_strncmp("))", lex->in->str + lex->i, 2) && (lex->i += 2))
		ft_dstrdel_n(lex->scope, -1, 1);
	//lex->i += 2;
	lex->st = TSD_PL2;
	return (1);
}
