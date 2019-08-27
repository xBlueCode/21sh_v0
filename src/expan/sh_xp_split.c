#include "ftsh.h"

int		sh_xp_word_split(t_sh *sh, t_dastr *words)
{
	char	*ifs;
	t_dastr	*split;
	int 	si;
	t_lex	*lex;
	int 	new;
	int 	off;
	int 	i;
	int		j;

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
		sh_lex_init(&lex, words->a[i]->str);
		new = 1;
		j = -1;
		while (++j < words->a[i]->len)
		{
			off = lex->i;
			//if (sh_lex_seek_dq(lex, 0))
			//	continue;
			if (ft_strchr(ifs, lex->in->str[lex->i]))
				new = 1;
			else
			{
				if (sh_lex_seek_dq(lex, 0))
					lex->i--;
				if (new)
					ft_dastrins_str(split, ++si, "");
				while (off < lex->i + 1)
					ft_dstrins_ch(split->a[si], -1, lex->in->str[off++]);
				new = 0;
			}
			lex->i++;
		}
	}
	ft_printf(C_MGN"Split:\n");
	ft_dastrprint_all(split, "\n");
	ft_printf("\n----------\n"T_END);
}
