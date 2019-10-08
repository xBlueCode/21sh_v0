/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_lex_tok.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 19:15:04 by abbesbes          #+#    #+#             */
/*   Updated: 2019/10/07 19:15:05 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "sh_lex.h"

t_token			*sh_lex_tok_new(int type, ssize_t pos, int len, char *xme)
{
	t_token		*tok;

	if (!(tok = (t_token*)ft_memalloc(sizeof(t_token))))
		return (NULL);
	tok->t = type;
	tok->p = pos;
	tok->l = len;
	tok->assi = -1;
	tok->val = ft_dstrnew_str(xme);
	return (tok);
}

t_token			*sh_lex_tok_set(int type, ssize_t pos, int len, char *xme)
{
	t_token		*tok;

	if (!(tok = (t_token*)ft_memalloc(sizeof(t_token))))
		return (NULL);
	tok->t = type;
	tok->p = pos;
	tok->l = len;
	tok->assi = -1;
	tok->val = ft_dstrset_str(xme);
	return (tok);
}

int				sh_lex_tok_free(t_token **ptok)
{
	if (!ptok || !*ptok)
		return (KO);
	ft_dstrfree(&(*ptok)->val);
	ft_memdel((void**)ptok);
	return (OK);
}

void			sh_lex_tok_tfree(t_token **ptok)
{
	if (!ptok || !*ptok)
		return ;
	ft_dstrfree(&(*ptok)->val);
	ft_memdel((void**)ptok);
}
