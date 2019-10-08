/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_lex_seek_als.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 19:14:21 by abbesbes          #+#    #+#             */
/*   Updated: 2019/10/07 19:14:23 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "sh_lex.h"
#include "sh_alias.h"

int 	sh_lex_seek_als_start(t_lex *lex, int op);

int 	sh_lex_seek_als(t_lex *lex, int op)
{
	int pos;
	char *word;
	t_lex *alex;
	t_list *keys;

	(void) op;
	if (lex->i < lex->alias_off
		|| (lex->ctx != TCTX_ALIAS && lex->ctx != TCTX_FIRSTW)
		|| !sh_lex_isinname(lex->in->str[lex->i]))
		return (0);
	pos = lex->i;
	while (sh_lex_isinname(lex->in->str[++pos]));
	if (!ft_strchr(SH_LEX_SEPSET_X, lex->in->str[pos])
		&& !ft_isblank(lex->in->str[pos]))
		return (0);
	word = ft_strndup(lex->in->str + lex->i, pos - lex->i);
	if (!ft_htab_contains(sh_als(), word, ft_strlenz(word) + 1))
		FT_INST_RET(0, FT_MEMDEL(word));
	if (ft_hset_contains(lex->alias_chain, word))
		FT_INST_RET(0, FT_MEMDEL(word));
	sh_lex_init(&alex, ft_htab_getval(sh_als(), word, ft_strlen(word) + 1));
	ft_hset_add(alex->alias_chain, word, ft_strlen(word) + 1);
	keys = ft_hset_tolst(lex->alias_chain);
	while (keys)
	{
		ft_hset_add(alex->alias_chain, keys->content, ft_strlenz(keys->content) + 1);
		keys = keys->next;
	}
	if (sh_lex_seek_als_start(alex, op) < 0)
		return (0);
	ft_dstrdel_n(lex->in, lex->i, pos);
	ft_dstrins_str(lex->in, lex->i, alex->in->str);
	lex->alias_off = lex->i + ft_strlen(alex->in->str);
	FT_MEMDEL(word);
	sh_lex_free(&alex);
	sleep(8);
	return (1);
}

int 	sh_lex_seek_als_start(t_lex *lex, int op)
{
	while (lex->in->str[lex->i])
	{
		if (sh_lex_seek_als(lex, op) < 0)
			return (-1);
		else if (
				sh_lex_seek_rescope(lex, op)
				|| sh_lex_seek_join(lex, op)
				|| sh_lex_seek_hash(lex, op)
				|| sh_lex_seek_blank(lex, op)
				|| sh_lex_seek_p(lex, op)
				|| sh_lex_seek_cb(lex, op)
				|| sh_lex_seek_hd(lex, op)
				|| sh_lex_seek_op(lex, op)
				|| sh_lex_seek_ion(lex, op)
				|| sh_lex_seek_nl(lex, op)
				|| sh_lex_seek_tok(lex, op))
		{
			if (lex->st != TSNONE)
				sh_lex_seek_ctx(lex, op);
		}
		else
			lex->i++;
	}
	return (OK);
}
