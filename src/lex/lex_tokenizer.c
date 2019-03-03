/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_tokenizer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 17:46:29 by abbesbes          #+#    #+#             */
/*   Updated: 2019/03/03 19:46:24 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_lex.h"

t_list		*x_tokenize(char *in)
{
	t_list	*tklst;
	int		off;
	int		tks;

	off = 0;
	tklst = NULL;
	while (in[off])
		if ((tks = xtk_recogize(in, off, &tklist)) > 0)
			off += tks;
		else
			return (NULL); // print error + free_list
}

int		xtk_recognize(char *in, int off, t_list	*tklist)
{
	while (XTK_ISWS(in[off]))
		off++;
	if ((ft_strchr(XTK_START_GL, in[off])))
		return (xtk_start_gl(in, off, &tklist));
	if ((ft_strchr(XTK_START_ENAO, in[off])))
		return (xtk_start_enao(in, off, &tklist));
	if ((ft_strchr(XTK_START_ARITH, in[off])))
		return (xtk_start_arith(in, off, &tklist));
	if ((ft_strchr(XTK_START_PONCT, in[off])))
		return (xtk_start_ponct(in, off, &tklist));
	if ((ft_strchr(XTK_CLOSURE, in[off])))
		return (xtk_start_closure(in, off, &tklist));
	if ((ft_strchr(XTK_START_QUOTE, in[off])))
		return (xtk_start_quote(in, off, &tklist));
	else
		return (xtk_start_word(in, off, &tklist));
}
