#include "ftsh.h"

int		sh_xp_word_split(t_sh *sh, t_dastr *words)
{
	char	*ifs;
	t_dastr	*split;
	t_dstr	*word;
	int 	si;
	int 	new;
	int 	off;
	int 	i;
	int		j;
	int 	dql;

	//if (!(ifs = sh_var_getval(sh->var, "IFS")))
	//	return (0);
	ifs = " ";
	i = -1;
	si = -1;
	split = ft_dastrnew_max(2);
	ft_printf(C_MGN"Before Split:\n");
	ft_dastrprint_all(words, "\n");
	ft_printf("\n----------\n"T_END);
	while (++i < words->len)
	{
		new = 1;
		j = -1;
		word = words->a[i];
		off = 0;
		while (++j < words->a[i]->len)
		{
			if (ft_strchr(ifs, word->str[j]) && ++off)
				new = 1;
			else
			{
				if (word->str[j] == '"'
					&& sh_lex_skip(word->str + j, &sh_lex_seek_dq, &dql))
					j += dql - 1;
				if (new)
					ft_dastrins_str(split, ++si, "");
				while (off <= j)
					ft_dstrins_ch(split->a[si], -1, word->str[off++]);
				new = 0;
			}
		}
	}
	ft_printf(C_MGN"Split:\n");
	ft_dastrclear(words);
	ft_dastrprint_all(split, "\n");
	ft_printf("\n----------\n"T_END);
	ft_dastrcpy(words, split);
	FT_MEMDEL(split);
	return (1);
}
