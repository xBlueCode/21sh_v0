#include "libft.h"
#include "sh_lex.h"

int 	sh_lex_seek_hash(t_lex *lex, int op)
{
	int clen;

	(void)op;
	if (lex->in->str[lex->i] != '#')
		return (0);
	clen = 1;
	while (lex->in->str[lex->i + clen] != '\n')
		clen++;
	ft_dstrdel_n(lex->in, lex->i, clen);
	return (1);
}
