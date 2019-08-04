#include "libft.h"
#include "sh_lex.h"

int		sh_lex_isinname(char c)
{
	return (c == '_' || ft_isalnum(c));
}
