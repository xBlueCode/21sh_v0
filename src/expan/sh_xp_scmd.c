#include "ftsh.h"

int 	sh_xp_bq(t_sh *sh, t_dastr *words, int *i, int *j)
{
	t_dstr	*word;
	t_sh	*nsh;
	char 	*script;
	int 	off;

	DF0
	word = words->a[*i];
	if (word->str[*j] != '`')
		return (0);
	off = (*j)++;
//	ft_dstrdel_n(word, *j, 1);
	while (word->str[*j] && word->str[*j] != '`')
		(*j)++;
	if (word->str[*j] != '`')
		return (-1);
	script = ft_strndup(word->str + off + 1, *j - off - 1);
	ft_printf("BQ Script: <%s>\n", script);
	ft_dstrdel_n(word, off, *j - off + 1);
	*j = off;
	nsh = sh_sh_clone(sh, SH_MODE_SCMD);
	sh_script_run(nsh, script);
	//ft_printf(C_GRN"RES SUBST:\n%s\n++++++++++++++++++\n", nsh->sub_out->str);
	ft_dstrins_str(word, *j, nsh->sub_out->str);
	*j += ft_strlenz(nsh->sub_out->str);
	ft_printf(C_RED"After BQ: %s"T_END, word->str + *j);
	// TODO: free nsh
	return (1);
}
