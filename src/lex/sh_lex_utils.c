/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_lex_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 19:15:06 by abbesbes          #+#    #+#             */
/*   Updated: 2019/10/07 19:15:08 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "sh_lex.h"

int		sh_lex_isinname(char c)
{
	return (c == '_' || c == '?' || ft_isalnum(c));
}

int		sh_lex_tok_isdelim(char c)
{
	if (!c)
		return (1);
	return (ft_strchr(SH_LEX_SEPSET_X, c) || ft_isspace(c));
}

t_token	*sh_lex_tok_last(t_lex *lex)
{
	if (!lex)
		return (NULL);
	return (lex->tokend);
}

t_token	*sh_lex_tokdup(t_token *t)
{
	if (!t)
		return (NULL);
	return (sh_lex_tok_new(t->t, t->p, t->l,
		!t->val ? NULL : t->val->str));
}
