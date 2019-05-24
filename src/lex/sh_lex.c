//
// Created by xbluecode on 24.05.19.
//

#include "libft.h"
#include "sh_lex.h"

t_lex		g_lex;

t_lex 		sh_lex(void)
{
	return (g_lex);
}

int 		sh_lex_init(t_lex **plex, char *input)
{
	if (!input || !(*plex = (t_lex*)ft_memalloc(sizeof(t_lex))))
		return (-1);
	(*plex)->str = ft_strdup(input);
	(*plex)->i = 0;
	(*plex)->tlst = NULL;
	(*plex)->toff = NULL;
	return (0);
}

int 		sh_lex_free(t_lex **plex)
{
	ft_memdel((void**)&(*plex)->str);
	ft_lst_free(&(*plex)->tlst, &sh_lex_tok_free);
	return (0);
}

int 		sh_lex_start(t_lex *lex)
{
	return (0);
}
