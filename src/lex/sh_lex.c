/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_lex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 19:14:04 by abbesbes          #+#    #+#             */
/*   Updated: 2019/10/07 19:14:06 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "sh_lex.h"

t_lex		g_lex;

t_lex 		sh_lex(void)
{
	return (g_lex);
}

t_lex 		*sh_lex_new(char *input)
{
	t_lex	*lex;

	if (!input || !(lex = (t_lex*)ft_memalloc(sizeof(t_lex))))
		return (NULL);
//	ft_printf(C_CYN"LEX INIT:\n%s\n"T_END, input);
	lex->in = ft_dstrnew_str(input);
	lex->i = 0;
	lex->scope = ft_dstrnew_max(1);
	lex->st = TSNONE;
	lex->ctx = TCTX_FIRSTW;
	lex->tlst = NULL;
	lex->toff = lex->tlst;
	lex->tclass = lex->tlst;
	lex->hd_key = ft_dastrnew_max(1);
	lex->hd_val = ft_dastrnew_max(1);
	lex->alias_chain =
			ft_hset_init(24, &ft_hcode_str, &ft_hequals_str, &ft_memdel);
	lex->alias_off = 0;
	lex->alias_rec = 0;
	lex->assi = -1;
//	sh_lex_tok_add(*plex, sh_lex_tok_new(TSNONE, -1, 0, NULL));
	lex->tokend = &((t_token){.t = TSNONE, .p = -1, .l = 0, .val = NULL});
	return (0);
}

int 		sh_lex_init(t_lex **plex, char *input)
{
	if (!input || !(*plex = (t_lex*)ft_memalloc(sizeof(t_lex))))
		return (-1);
//	ft_printf(C_CYN"LEX INIT:\n%s\n"T_END, input);
	(*plex)->in = ft_dstrnew_str(input);
	(*plex)->i = 0;
	(*plex)->scope = ft_dstrnew_max(1);
	(*plex)->st = TSNONE;
	(*plex)->ctx = TCTX_FIRSTW;
	(*plex)->tlst = NULL;
	(*plex)->toff = (*plex)->tlst;
    (*plex)->tclass = (*plex)->tlst;
	(*plex)->hd_key = ft_dastrnew_max(1);
	(*plex)->hd_val = ft_dastrnew_max(1);
	(*plex)->alias_chain =
			ft_hset_init(24, &ft_hcode_str, &ft_hequals_str, &ft_memdel);
	(*plex)->alias_off = 0;
	(*plex)->alias_rec = 0;
	(*plex)->assi = -1;
//	sh_lex_tok_add(*plex, sh_lex_tok_new(TSNONE, -1, 0, NULL));
	(*plex)->tokend = &((t_token){.t = TSNONE, .p = -1, .l = 0, .val = NULL});
	return (0);
}

int 		sh_lex_free(t_lex **plex)
{
	if (!plex || !*plex)
		return (-1);
	ft_dstrfree(&(*plex)->in);
	ft_dstrfree(&(*plex)->scope);
	ft_lst_free(&(*plex)->tlst, (void(*)(void**))(&sh_lex_tok_free));
	ft_dastrfree(&(*plex)->hd_val);
	ft_dastrfree(&(*plex)->hd_key);
	ft_hset_free(&(*plex)->alias_chain);
	FT_MEMDEL((*plex));
	return (0);
}

int 		sh_lex_start(t_lex *lex)
{
	return (sh_lex_seek(lex, 1));
}
