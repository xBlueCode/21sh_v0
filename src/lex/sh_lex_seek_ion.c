#include "libft.h"
#include "sh_lex.h"

int		sh_lex_seek_ion(t_lex *lex, int op)
{
	int pos;

	(void)op;
	if (!ft_isdigit(lex->in->str[lex->i]))
		return (0);
	pos = lex->i + 1;
	while (ft_isdigit(lex->in->str[pos]))
		pos++;
	if (lex->in->str[pos] == '<' || lex->in->str[pos] == '>')
	{
		lex->st = TSION;
		lex->i = pos;
		return (1);
	}
	return (0);
}
