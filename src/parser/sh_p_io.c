#include "ftsh.h"

int		sh_p_io_redir(t_parser *p, t_btree **ast)
{
	t_btree *cast;

	DP0
	SHP_CAST_INIT(SH_GR_IO_REDIR)
	if (sh_p_match(p, &cast, TSION)) // TODO
	{
		if (sh_p_io_file(p, SHP_CAST_L) || sh_p_io_here(p, SHP_CAST_L))
			PRET(1)
		PRET(0)
	}
	if (sh_p_io_file(p, SHP_CAST_L) || sh_p_io_here(p, SHP_CAST_L))
		PRET(1)
	PRET(0)
}

int		sh_p_io_file(t_parser *p, t_btree **ast)
{
	t_btree *cast;

	DP0
	SHP_CAST_INIT(SH_GR_IO_FILE)
	if (sh_p_match(p, &cast, TSL)
		|| sh_p_match(p, &cast, TSL_A)
		|| sh_p_match(p, &cast, TSG)
		|| sh_p_match(p, &cast, TSG_A)
		|| sh_p_match(p, &cast, TSG2)
		|| sh_p_match(p, &cast, TSL_G)
		|| sh_p_match(p, &cast, TSG_O)
		)
	{
		if (sh_p_filename(p, SHP_CAST_L))
			PRET(1)
		PRET(0)
	}
	PRET(0)
}

int		sh_p_filename(t_parser *p, t_btree **ast)
{
	t_btree *cast;

	DP0
	SHP_CAST_INIT(SH_GR_FILENAME) // TODO
	if (sh_p_match(p, &cast, TSTOK_WORD)) //TODO: Rule 2
		PRET(1);
	PRET(0)
}

int		sh_p_io_here(t_parser *p, t_btree **ast)
{
	t_btree *cast;

	DP0
	SHP_CAST_INIT(SH_GR_IO_HERE)
	if (sh_p_match(p, &cast, TSL2)) // TODO: Implement <<-
	{
		if (sh_p_here_end(p, SHP_CAST_L))
			PRET(1)
		PRET(0)
	}
	PRET(0)
}

int		sh_p_here_end(t_parser *p, t_btree **ast)
{
	t_btree *cast;
	t_dstr 	*dhd;

	DP0
	SHP_CAST_INIT(SH_GR_HERE_END)
	if (sh_p_match(p, &cast, TSTOK_WORD)) // Apply Rule 3
	{
		dhd = SHG_AST_TOK(cast)->val;
		ft_dstrdel_n(dhd, 0, dhd->len);
		ft_dstrins_str(dhd, 0, p->hd_val->a[0]->str);
		ft_dastrdel_n(p->hd_val, 0, 1);
		//ft_dstrfree(&dhd);
		/* // Replacemenet of the above
		i = -1;
		while (++i < p->hd_key->len)
		{
			if (!ft_strcmp(dhd->str, p->hd_key->a[i]->str))
			{
				ft_dstrdel_n(dhd, 0, dhd->len);
				ft_dstrins_str(dhd, 0, p->hd_val->a[i]->str);
				break;
			}
		}
		*/
		PRET(1);
	}
	PRET(0);
}
