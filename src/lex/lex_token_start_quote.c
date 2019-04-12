/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_token_start_quote.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 20:01:19 by abbesbes          #+#    #+#             */
/*   Updated: 2019/03/07 17:04:07 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "sh_lex.h"

int		xtk_start_quote(char *in, int off, t_list **tklist, int m)
{
	if (in[off] == '\'')
		return (xtk_start_squote(in, off, tklist, m));
	if (in[off] == '\"')
		return (xtk_start_dquote(in, off, tklist, m));
	//if (in[off] == '`')
	//	return (xtk_start_bquote(in, off, tklist));
	return (0);
}

int		xtk_start_squote(char *in, int off, t_list **tklist, int m)
{
	int end;

	if (in[off] == '\'' && (end = off + 1))
	{
		while (in[end] && in[end] != '\'')
			end++;
		if (in[end] == '\'' && xtk_add(tklist, TSWSQ,
					ft_strndup_i(in, end - off + 1, off), m))
			return (end - off + 2);
		return (0);
	}
	return (0);
}

int		xtk_start_dquote(char *in, int off, t_list **tklist, int m)
{
	int end;

	if (in[off] == '\"' && (end = off + 1))
	{
		while (in[end] && (in[end] != '\"'))
		{
			if (in[end] == '\\' && end++)
			{
				if (ft_strchr(XTK_DQ_ESC, in[end])) // append in[end]
				{
					ft_printf("escaped char %c\n", in[end]);
					end++;
				}
				else if (in[end] == '\n')
					end++;
			}
			else
				end++;
		}
		if (in[end] == '\"' && xtk_add(tklist, TSWSQ,
						ft_strndup_i(in, end - off + 1, off), m))
			return (end - off + 2);
		return (0);
	}
	return (0);
}
