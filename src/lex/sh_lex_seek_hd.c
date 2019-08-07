#include "libft.h"
#include "sh_lex.h"

int			sh_lex_seek_hd(t_lex *lex, int op)
{
	return (sh_lex_seek_hdk(lex, op) || sh_lex_seek_hdv(lex, op));
}

int			sh_lex_seek_hd_old(t_lex *lex, int op) // TODO : del if not needed
{
	char	*hd_key;
	char	*hd_val;
	int 	hd_klen;
	int 	off;

	(void)op;
	if (ft_strncmp(lex->in->str + lex->i, "<<", 2))
		return (0);
	lex->i += 2;
	hd_key = ft_strdup_cond(lex->in->str + lex->i, &ft_isalnum);
	hd_klen = ft_strlenz(hd_key);
	if ((off = ft_strichr(lex->in->str + lex->i, '\n')) < 0)
		return (-1);
	off += lex->i + 1;
	if (!(hd_val = sh_lex_seek_hd_getval(lex, hd_key, off)))
	{
		ft_dstrins_ch(lex->scope, -1, RL_SCP_HD);
		lex->in->str[off] = '\0';
		return (1);
	}
	ft_dstrdel_n(lex->in, (lex->i -= 2), hd_klen + 2);
	ft_dastrins_str_free(lex->hd_val, -1, &hd_val);
	ft_memdel((void**)&hd_key);
	lex->st = TSL2;
	return (1);
}
/*
int			sh_lex_seek_hdk(t_lex *lex, int op)
{
	char	*hd_key;
	int 	hd_klen;

	(void)op;
	if (ft_strncmp(lex->in->str + lex->i, "<<", 2))
		return (0);
	lex->i += 2;
	hd_key = ft_strdup_cond(lex->in->str + lex->i, &ft_isalnum);
	ft_dastrins_str(lex->hd_key, -1, hd_key);
	ft_dstrins_ch(lex->scope, -1, RL_SCP_HD);
	hd_klen = ft_strlenz(hd_key);
	lex->i += hd_klen;
	lex->st = TSL2;
	return (1);
}
*/


int			sh_lex_seek_hdk(t_lex *lex, int op)
{
	(void)op;
	if (ft_strncmp(lex->in->str + lex->i, "<<", 2))
		return (0);
	lex->i += 2;
	ft_dstrins_ch(lex->scope, -1, RL_SCP_HD);
	lex->st = TSL2;
	return (1);
}

int 		sh_lex_seek_hdv(t_lex *lex, int op)
{
	int 	off;
	char	*hd_val;
	t_dstr 	*dhd_key;

	(void)op;
	if (sh_lex_tok_last(lex)->t != TSNL
		|| ft_dstrget_ch(lex->scope, -1) != RL_SCP_HD)
		return (0);
	off = lex->i;
	if (!(dhd_key = ft_dastrget_i(lex->hd_key, -1)))
	{
		lex->st = TSERR;
		return (1);
	}
	ft_printf(C_BLU"--- > I'm here < ---\n"T_END);
	ft_printf("In:\n++++\n%s\n++++\n", lex->in->str + off);
	if (!(hd_val = sh_lex_seek_hd_getval(lex, dhd_key->str, off)))
	{
		ft_printf(C_BLU"Here-DOC: <%s>\n%s\n-------\n"T_END, dhd_key->str, hd_val);
		lex->in->str[off] = '\0';
//		lex->st = TSERR;
		return (1);
	}
	ft_printf(C_BLU"Here-DOC: <%s>\n%s\n-------\n"T_END, dhd_key->str, hd_val);
	lex->i = off + ft_strlen(dhd_key->str) + ft_strlen(hd_val);
	ft_dstrdel_n(lex->scope, -1, 1);
	ft_dastrdel_n(lex->hd_key, -1, 1);
	return (1);
}

/*
int 		sh_lex_seek_hdv(t_lex *lex, int op)
{
	int 	off;
	char	*hd_val;
	char 	*hd_key;

	(void)op;
	if (lex->in->str[lex->i] != '\n'
		|| ft_dstrget_ch(lex->scope, -1) != RL_SCP_HD)
		return (0);
	off = lex->i + 1;
	hd_key = ft_dastrget_i(lex->hd_key, -1)->str;
	if (!(hd_val = sh_lex_seek_hd_getval(lex, hd_key, off)))
	{
		lex->in->str[off] = '\0';
		return (0);
	}
	//ft_dstrdel_n(lex->in, off, ft_strlen(hd_val) + ft_strlen(hd_key));
	lex->i = off + ft_strlen(hd_key) + ft_strlen(hd_val);
	ft_dstrdel_n(lex->scope, -1, 1);
	ft_dastrdel_n(lex->hd_key, -1, 1);
	return (1);
}
*/

char 		*sh_lex_seek_hd_getval(t_lex *lex, char *hd_key, ssize_t off)
{
	int		hd_klen;
	ssize_t	i;
	char 	*hd_val;
	int 	hd_vlen;

	hd_vlen = 0;
	hd_klen = ft_strlenz(hd_key);
	while (ft_strncmp(lex->in->str + off + hd_vlen, hd_key, hd_klen))
	{
		if ((i = ft_strichr(lex->in->str + off + hd_vlen, '\n')) < 0)
			return (NULL);
		else
			hd_vlen += i + 1;
	}
	hd_val = ft_strndup(lex->in->str + off, hd_vlen);
	return (hd_val);
}