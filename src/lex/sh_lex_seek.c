#include "libft.h"
#include "sh_lex.h"

int 		sh_lex_seek(t_lex *lex, int op)
{
	//return (sh_lex_seek_all(lex, op));
	return (sh_lex_seek_start(lex, op));
}

int 		sh_lex_seek_all(t_lex *lex, int op)
{
	//ssize_t off;

	//ft_printf("seeking All...\n");
	lex->buf = ft_dstrnew_max(1);
	while (lex->in->str[lex->i])
	{
		//lex->off = lex->i; // not final
		//lex->st = TSNONE; // not final
		//ft_printf("--->  seeking all from %d\n", off);
		if (sh_lex_seek_join(lex, op)
			|| sh_lex_seek_space(lex, op)
			|| sh_lex_seek_escape(lex, op)
			|| sh_lex_seek_sq(lex, op)
			|| sh_lex_seek_dq(lex, op)
			|| sh_lex_seek_bq(lex, op)
			|| sh_lex_seek_param(lex, op)
			|| sh_lex_seek_smath(lex, op)
			|| sh_lex_seek_scmd(lex, op)
			|| sh_lex_seek_hd(lex, op)
			|| sh_lex_seek_op(lex, op)
			|| sh_lex_seek_ion(lex, op) // check in other scopes
			|| sh_lex_seek_wo(lex, op)
			|| sh_lex_seek_nl(lex, op)
			)
			//continue;
			sh_lex_seek_add(lex, op);
		else
			lex->i++;
	}
	return (OK);
}

int 		sh_lex_seek_space(t_lex *lex, int op)
{
	(void)op;
	if (lex->in->str[lex->i] == '\n')
		return (0);
	if (!ft_isspace(lex->in->str[lex->i]))
		return (0);
	while (ft_isspace(lex->in->str[lex->i]))
		lex->i++;
	//ft_printf("-- > space detected ! at %d\n", lex->i);
	return (1);
}

int 		sh_lex_seek_wo(t_lex *lex, int op)
{
	(void)op;
	while (lex->in->str[lex->i])
	{
		if (sh_lex_seek_join(lex, 0) || sh_lex_seek_escape(lex, 0))
			continue;
		if (ft_strchr(SH_LEX_SEPSET, lex->in->str[lex->i])
			|| ft_isspace(lex->in->str[lex->i]))
		{
			lex->st = TSW;
			return (1);
		}
		lex->i++;
	}
	return (0);
}