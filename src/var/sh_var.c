//
// Created by xbluecode on 17.05.19.
//

#include "libft.h"
#include "ftsh.h"

t_table		*g_var;

t_table		*sh_var(void)
{
	return (g_var);
}

int 		sh_var_start(char **envp)
{
	if (!(g_var = ft_tabnew_max(33)))
		ft_printf("sh_var_init: Failed to create Env Table\n");
	sh_var_inherit(envp);
	sh_var_init();
	return (0);
}

int 		sh_var_inherit(char **envp)
{
	int		i;
	char 	*eq;
	t_trow	trow;

	if (!envp)
		return (-1);
	i = -1;
	while (envp[++i])
	{
		if (!(eq = ft_strchr(envp[i], '=')))
			continue;
		trow = ft_tabrow_set(i,
			ft_strndup(envp[i], eq - envp[i]), ft_strdup(eq + 1), SH_VO_GLO);
		ft_tabins(g_var, trow, 0);
	}
}

int 		sh_var_init(void)
{
	sh_var_init_ftsh();
	sh_var_init_id();
	return (0);
}

int 		sh_var_init_id(void)
{
	char 	*vpid;

	vpid = ft_itoa((int)getpid());
	ft_tabins(g_var, ft_tabrow_set(-1, SH_VN_SHPID, vpid, SH_VO_SHPID), 1);
	ft_memdel((void**)&vpid);
	ft_tabins(g_var, ft_tabrow_set(-1, SH_VN_ESTAT, 0, SH_VO_ESTAT), 1);
}

int 		sh_var_init_ftsh(void)
{
	t_trow	trow;
	char 	*vshlvl;

	trow = ft_tabget_n(g_var, SH_VN_FTSH);
	if (trow.i < 0)
	{
		ft_tabins(g_var, ft_tabrow_set(-1, SH_VN_FTSH, SH_VV_FTSH, 0x3), 0);
		vshlvl = NULL;
	}
	trow = ft_tabget_n(g_var, SH_VN_SHLVL);
	if (trow.i < 0 || !vshlvl)
		ft_tabins(g_var, ft_tabrow_set(-1, SH_VN_SHLVL, SH_VV_SHLVL, 0x3), 1);
	else if ((vshlvl = ft_itoa(ft_atoi(trow.value) + 1)))
		ft_tabins(g_var, ft_tabrow_set(-1, SH_VN_SHLVL, vshlvl, 0x3), 1);
	ft_memdel((void**)&vshlvl);
	return (0);
}
