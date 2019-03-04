/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_token_start_quote.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 20:01:19 by abbesbes          #+#    #+#             */
/*   Updated: 2019/03/04 20:48:50 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "sh_lex.h"

int		xtk_start_quote(char *in, int off, t_list **tklist)
{
	if (in[off] == '\'')
		return (xtk_start_squote(in, off, tklist));
	if (in[off] == '\"')
		return (xtk_start_dquote(in, off, tklist));
	//if (in[off] == '`')
	//	return (xtk_start_bquote(in, off, tklist));
	return (0);
}

int		xtk_start_squote(char *in, int off, t_list **tklist)
{
	int end;

	if (in[off] == '\'' && (end = off + 1))
	{
		while (in[end] && in[end] != '\'')
			end++;
		if (in[end] == '\'' && xtk_add(tklist, TSWSQ,
					ft_strndup_i(in, end - off + 1, off)))
			return (end - off + 1);
		return (0);
	}
	return (0);
}

int		xtk_start_dquote(char *in, int off, t_list **tklist)
{
	int end;

	if (in[off] == '\"' && (end = off + 1))
	{
		while (in[end] && (in[end] != '\"' || in[end - 1] == '\\'))
			end++;
		if (in[end] == '\"' && xtk_add(tklist, TSWSQ,
						ft_strndup_i(in, end - off + 1, off)))
			return (end - off + 1);
		return (0);
	}
	return (0);
}
