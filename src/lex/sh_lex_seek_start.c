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
		if (//sh_lex_seek_escape(lex, op)
			sh_lex_seek_rescope(lex, op)
		    || sh_lex_seek_join(lex, op)
		    || sh_lex_seek_hash(lex, op)
		    //|| sh_lex_seek_escape(lex, op)
			|| sh_lex_seek_blank(lex, op)
			|| sh_lex_seek_p(lex, op)
			|| sh_lex_seek_cb(lex, op)
			//|| sh_lex_seek_sq(lex, op)
			//|| sh_lex_seek_dq(lex, op)
			//|| sh_lex_seek_bq(lex, op)
			//|| sh_lex_seek_param(lex, op)
			//|| sh_lex_seek_smath(lex, op)
			//|| sh_lex_seek_scmd(lex, op)
			|| sh_lex_seek_hd(lex, op)
			//|| sh_lex_seek_hdk(lex, op) // TODO: replace {hdk, hdv} with hd
			//|| sh_lex_seek_hdv(lex, op)
			|| sh_lex_seek_op(lex, op)
			|| sh_lex_seek_ion(lex, op) // check in other scopes
			|| sh_lex_seek_nl(lex, op)
			|| sh_lex_seek_tok(lex, op)
			)
			//continue;
		{
			if (lex->st != TSNONE)
				sh_lex_seek_ctx(lex, op);
			if (sh_lex_seek_add(lex, op) < 0)
				return (-1);
		}
		else
			lex->i++;
	}
	return (OK);
}

int 		sh_lex_seek_tok(t_lex *lex, int op)
{
	int 	off;

	(void)op;
	off = lex->i;
	while (lex->in->str[lex->i])
	{
		if (sh_lex_seek_rescope(lex, op)
			|| sh_lex_seek_join(lex, op)
			|| sh_lex_seek_escape(lex, op)
			|| sh_lex_seek_sq(lex, op)
			|| sh_lex_seek_dq(lex, op)
			|| sh_lex_seek_bq(lex, op)
			|| sh_lex_seek_param(lex, op)
			|| sh_lex_seek_smath(lex, op)
			|| sh_lex_seek_scmd(lex, op)
			//|| sh_lex_seek_ssh(lex, op)
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
			if (lex->i == off)
				lex->st = TSERR;
			else
				lex->st = TSTOK;
			//lex->i++;
			return (1);
		}
		/*
		if (ft_strchr(SH_LEX_TOK_FORB, lex->in->str[lex->i]))
		{
			lex->st = TSERR;
			return (-1);
		}
		 */
		lex->i++;
	}
	return (op);
}

int         sh_lex_seek_rescope(t_lex *lex, int op)
{
	ssize_t		i;
	char 		*line;

	(void)op;
	i = lex->i;
	line = lex->in->str;
	if (ft_dstrget_ch(lex->scope, -1) == RL_SCP_JOIN)
		ft_dstrdel_n(lex->scope, -1, 1);
	else if (
			ft_dstrget_ch(lex->scope, -1) == RL_SCP_PIPE
			|| ft_dstrget_ch(lex->scope, -1) == RL_SCP_AND
			|| ft_dstrget_ch(lex->scope, -1) == RL_SCP_OR
			)
	{
		while (ft_isspace(line[i]))
			i++;
		if (line[i] && line[i] != '\n' && line[i] != '\\')
			ft_dstrdel_n(lex->scope, -1, 1);
		if (sh_lex_seek_join(lex, op))
			return (1);
		lex->i = i;
		return (1);
	}
	return (0);
}