/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_tokenizer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 17:46:29 by abbesbes          #+#    #+#             */
/*   Updated: 2019/03/07 18:53:43 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "sh_lex.h"

t_list		*x_tokenize(char *in, int m)
{
	t_list	*tklist;
	int		off;
	int		tks;

	off = 0;
	tklist = NULL;
	while (in[off])
	{
		ft_printf("off: %d\n", off);
		if ((tks = xtk_recognize(in, off, &tklist, m)) > 0)
			off += tks;
		else
			break;
	}
	if (in[off])
		ft_printf("-- >lex error from %s\n", in + off);
	return (tklist);
}

int		xtk_recognize(char *in, int off, t_list	**tklist, int m)
{
	int ws;
	int	tks;

	ws = 0;
	while (XTK_ISWS(in[off]))
		off = off + 1 + 0 * (ws++);
	if (!in[off])
		return (ws);
	tks = 0;
	if ((ft_strchr(XTK_START_GL, in[off])))
		tks = (xtk_start_gl(in, off, tklist, m));
	else if ((ft_strchr(XTK_START_ENAO, in[off])))
		tks = (xtk_start_enao(in, off, tklist, m));
	else if ((ft_strchr(XTK_START_ARITH, in[off])))
		tks = (xtk_start_arith(in, off, tklist, m));
	else if ((ft_strchr(XTK_START_PONCT, in[off])))
		tks = (xtk_start_ponct(in, off, tklist, m));
	else if ((ft_strchr(XTK_START_CLOSURE, in[off])))
		tks = (xtk_start_closure(in, off, tklist, m));
	if ((ft_strchr(XTK_START_QUOTE, in[off])))
		return (xtk_start_quote(in, off, tklist, m));
	if ((ft_strchr(XTK_START_SUB, in[off])))
		return (xtk_start_quote(in, off, tklist, m));
	//else
	//	return (xtk_start_word(in, off, tklist));
	return (ws + tks);
}

int		xtk_add(t_list **tklist, int ts, char *xme, int mode)
{
	(void)tklist;
	(void)xme;
	(void)mode;

	if (mode)
		ft_printf("ts: %d | %s\n", ts, xme);
	return (1);
}
