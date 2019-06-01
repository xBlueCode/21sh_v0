//
// Created by xbluecode on 01.06.19.
//

#include "libft.h"
#include "sh_alias.h"

t_table		*g_als;

t_table		*sh_als(void)
{
	return (g_als);
}

int 		sh_als_init(void)
{
	if (!(g_als = ft_tabnew_max(2)))
	{
		ft_printf("sh_als_init: Failed to create a Table");
		return (-1);
	}
	return (0);
}