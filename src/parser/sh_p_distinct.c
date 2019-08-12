#include "ftsh.h"

char 	*g_reserved[] =
		{/*
			"if",
			"then",
			"else",
			"elif",
			"fi",
			"do",
			"done",
			"case",
			"esac",
			"while",
			"until",
			"for",
			"in",*/
			NULL
		};

int 	sh_tok_distinct(t_token *token, int target)
{
	if (!token || token->t != TSTOK)
		return (0);
	if (target == TSTOK_WORD || target == SH_GR_CMD_WORD) // TODO: handle cmd_word separately
		return (1 + 0 * (token->t = TSTOK_WORD));
	if (target == TSTOK_ASS_WORD
		&& token->assi > 0 && sh_tok_isname_till_eq(token->val->str))
		return (1 + 0 * (token->t = TSTOK_ASS_WORD));
	else if (target == TSTOK_NAME && sh_tok_isname(token->val->str))
		return (1 + 0 * (token->t = TSTOK_NAME));
	else if (target == SH_GR_CMD_NAME)
	{
		if (token->assi < 1 && !sh_tok_getrw(token->val->str))
			return (1 + 0 * (token->t = TSTOK_WORD));
		if (token->assi > 1 && !sh_tok_isname_till_eq(token->val->str))
			return (1 + 0 * (token->t = TSTOK_WORD));
		return (0);
	}
	else if (target > TSRW && target < TSRW_MAX
		&& target == sh_tok_getrw(token->val->str))
		return (1 + 0 * (token->t = target));
	return (0);
}

int		sh_tok_isname(char *val)
{
	int i;

	i = -1;
	while (val[++i])
	{
		if (val[i] != '_' && !ft_isalnum(val[i]))
			break;
	}
	if (!val[i])
		return (1);
	return (0);
}

int		sh_tok_isname_till_eq(char *val)
{
	int i;

	i = -1;
	while (val[++i])
	{
		if (val[i] != '_' && !ft_isalnum(val[i]))
			break;
	}
	if (val[i] == '=')
		return (1);
	return (0);
}

int 	sh_tok_getrw(char *tokval)
{
	int i;

	i = -1;
	while (g_reserved[++i])
		if (!ft_strcmp(g_reserved[i], tokval))
			return (TSRW + 1 + i);
	return (0);
}

int		sh_tok_distinct_rw(t_token *token, int target) // d_rule 1
{
	int i;

	(void)target;
	i = -1;
	while (g_reserved[++i])
		if (!ft_strcmp(g_reserved[i], token->val->str))
		{
			token->t = TSRW + 1 + i;
			return (1);
		}
	token->t = TSTOK_WORD;
	return (0);
}