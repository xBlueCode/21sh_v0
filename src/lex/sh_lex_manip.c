/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_lex_manip.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 19:14:09 by abbesbes          #+#    #+#             */
/*   Updated: 2019/10/07 19:14:11 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "sh_lex.h"

int 	sh_lex_tok_add(t_lex *lex, t_token *tok)
{
	if (!lex || !tok)
		return (-1);
	//lex->i += tok->l;
	ft_lst_addlast(&(lex->tlst), ft_lstset(tok, sizeof(t_token*)));
	lex->tokend = tok;
	return (OK);
}

t_token 		*sh_lex_tok_eat(t_lex *lex)
{
	t_token	*eaten;

	if (!lex->toff)
		return (NULL);
	eaten = (t_token*)lex->toff->content;
	lex->toff = lex->toff->next;
	return (eaten);
}

t_token 		*sh_lex_tok_get(t_lex *lex)
{
	if (!lex->toff)
		return (NULL);
	return ((t_token*)lex->toff->content);
}

int 			sh_lex_tok_next(t_lex *lex)
{
	if (!lex->toff)
		return (-1);
	lex->toff = lex->toff->next;
	return (0);
}

int 			sh_lex_tok_setoff(t_lex	*lex)
{
	lex->toff = lex->tlst;
	return (0);
}
