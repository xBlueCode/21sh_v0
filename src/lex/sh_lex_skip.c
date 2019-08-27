#include "ftsh.h"

int		sh_lex_skip(char *input, t_sh_lex_seeker lex_seeker, int *len)
{
	t_lex	*lex;
	int		ret;

	if (!input || !lex_seeker)
		return ((*len = 0));
	if (sh_lex_init(&lex, input))
		return (0);
	ret = (*lex_seeker)(lex, 0);
	*len = lex->i;
	sh_lex_free(&lex);
	return (ret);
}