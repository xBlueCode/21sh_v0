#include "libft.h"
#include "sh_lex.h"

int             sh_lex_class_name(t_lex *lex, int op)
{
    t_token *token;
    char    *lexme;

    if (!lex)
        return (0);
    if (!(token = lex->tclass) || token->t != TSTOK)
        return (0);
    lexme = token->val->str;
    if (!ft_isdigit(*lexme) && (ft_isalpha(*lexme) || *lexme == '_'))
    {
        while (*(++lexme))
        {
            if (!ft_isdigit(*lexme) && !ft_isalpha(*lexme) && *lexme != '_')
                return (0);
        }
        token->t = TSNAME; // update lex state instead
        return (1);
    }
    return (0);
}
