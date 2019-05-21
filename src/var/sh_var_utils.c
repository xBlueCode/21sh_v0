//
// Created by xbluecode on 18.05.19.
//

#include "ftsh.h"

int 	sh_var_tsel_glo(t_trow trow)
{
	if (BIT_IS(trow.opt, SH_VO_GLO))
		return (1);
	return (0);
}

char 	*sh_var_tbuild_env(t_trow trow)
{
	return (ft_strconnect(3, trow.name, "=", trow.value));
}