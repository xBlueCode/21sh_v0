/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_p_io.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 19:29:17 by abbesbes          #+#    #+#             */
/*   Updated: 2019/10/07 19:29:19 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftsh.h"

int		sh_p_io_redir(t_parser *p, t_btree **ast)
{
	t_btree *cast;

	DP0;
	SHP_CAST_INIT(SH_GR_IO_REDIR);
	if (sh_p_match(p, &cast, TSION))
	{
		if (sh_p_io_file(p, SHP_CAST_L) || sh_p_io_here(p, SHP_CAST_L))
			PRET(1);
		PRET(0);
	}
	if (sh_p_io_file(p, SHP_CAST_L) || sh_p_io_here(p, SHP_CAST_L))
		PRET(1);
	PRET(0);
}

int		sh_p_io_file(t_parser *p, t_btree **ast)
{
	t_btree *cast;

	DP0;
	SHP_CAST_INIT(SH_GR_IO_FILE);
	if (sh_p_match(p, &cast, TSL)
		|| sh_p_match(p, &cast, TSL_A)
		|| sh_p_match(p, &cast, TSG)
		|| sh_p_match(p, &cast, TSG_A)
		|| sh_p_match(p, &cast, TSG2)
		|| sh_p_match(p, &cast, TSL_G)
		|| sh_p_match(p, &cast, TSG_O))
	{
		if (sh_p_filename(p, SHP_CAST_L))
			PRET(1);
		PRET(0);
	}
	PRET(0);
}

int		sh_p_filename(t_parser *p, t_btree **ast)
{
	t_btree *cast;

	DP0;
	SHP_CAST_INIT(SH_GR_FILENAME);
	if (sh_p_match(p, &cast, TSTOK_WORD))
		PRET(1);
	PRET(0);
}

int		sh_p_io_here(t_parser *p, t_btree **ast)
{
	t_btree *cast;

	DP0;
	SHP_CAST_INIT(SH_GR_IO_HERE);
	if (sh_p_match(p, &cast, TSL2))
	{
		if (sh_p_here_end(p, SHP_CAST_L))
			PRET(1);
		PRET(0);
	}
	PRET(0);
}

int		sh_p_here_end(t_parser *p, t_btree **ast)
{
	t_btree *cast;
	t_dstr	*dhd;

	DP0;
	SHP_CAST_INIT(SH_GR_HERE_END);
	if (sh_p_match(p, &cast, TSTOK_WORD))
	{
		dhd = SHG_AST_TOK(cast)->val;
		ft_dstrdel_n(dhd, 0, dhd->len);
		ft_dstrins_str(dhd, 0, p->hd_val->a[0]->str);
		ft_dastrdel_n(p->hd_val, 0, 1);
		PRET(1);
	}
	PRET(0);
}
