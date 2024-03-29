/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_lex_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 19:14:12 by abbesbes          #+#    #+#             */
/*   Updated: 2019/10/07 19:14:13 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "sh_lex.h"

int		sh_lex_print(t_lex *lex)
{
	t_list	*lst_head;
	t_token	*token;
	int		i;

	if (!lex)
		ft_printf("Invalid Lexer !\n");
	else if (!(lst_head = lex->tlst))
		ft_printf("No token found !");
	else
	{
		i = 0;
		while (lst_head)
		{
			if ((token = (t_token*)lst_head->content))
				ft_printf("-%d\tT: <%-02d>\tV: <%s>",
					i, token->t, token->val);
			lst_head = lst_head->next;
		}
	}
	return (0);
}
