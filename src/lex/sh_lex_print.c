//
// Created by xbluecode on 28.05.19.
//

#include "libft.h"
#include "sh_lex.h"

int				sh_lex_print(t_lex *lex)
{
	t_list 	*lstHead;
	t_token	*token;
	int		i;

	if (!lex)
		ft_printf("Invalid Lexer !\n");
	else if (!(lstHead = lex->tlst))
		ft_printf("No token found !");
	else
	{
		i = 0;
		while (lstHead)
		{
			if ((token = (t_token*)lstHead->content))
				ft_printf("-%d\tT: <%-02d>\tV: <%s>",
					i, token->t, token->val);
			lstHead = lstHead->next;
		}
	}
	return (0);
}