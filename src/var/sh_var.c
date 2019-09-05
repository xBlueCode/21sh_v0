#include "libft.h"
#include "ftsh.h"

//t_table		*g_var;


t_table		*sh_var(void)
{
	return (sh_sh()->var);
}

int 		sh_var_start(t_table **var, char **envp)
{
	if (!(*var = ft_tabnew_max(SH_VAR_MAX)))
		ft_printf("sh_var_init: Failed to create Env Table\n");
	sh_var_inherit(*var, envp);
	sh_var_init(*var);
	return (0);
}

int 		sh_var_inherit(t_table *var, char **envp)
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
			ft_strndup(envp[i], eq - envp[i]), eq + 1, SH_VO_GLO);
		ft_tabins(var, trow, 0);
		FT_MEMDEL(trow.name);
	}
	return (OK);
}

int 		sh_var_init(t_table *var)
{
	sh_var_init_ftsh(var);
	sh_var_init_id(var);
	return (0);
}

int 		sh_var_init_id(t_table *var)
{
	char 	*vpid;

	vpid = ft_itoa((int)getpid());
	ft_tabins(var, ft_tabrow_set(-1, SH_VN_SHPID, vpid, SH_VO_SHPID), 1);
	ft_memdel((void**)&vpid);
	ft_tabins(var, ft_tabrow_set(-1, SH_VN_ESTAT, 0, SH_VO_ESTAT), 1);
	return (OK);
}

int 		sh_var_init_ftsh(t_table *var)
{
	t_trow	trow;
	char 	*vshlvl;

	trow = ft_tabget_n(var, SH_VN_FTSH);
	if (trow.i < 0)
	{
		ft_tabins(var, ft_tabrow_set(-1, SH_VN_FTSH, SH_VV_FTSH, SH_VO_LOC), 0);
		vshlvl = NULL;
	}
	trow = ft_tabget_n(var, SH_VN_SHLVL);
	if (trow.i < 0 || !vshlvl)
		ft_tabins(var, ft_tabrow_set(-1, SH_VN_SHLVL, SH_VV_SHLVL, SH_VO_LOC), 1);
	else if ((vshlvl = ft_itoa(ft_atoi(trow.value) + 1)))
		ft_tabins(var, ft_tabrow_set(-1, SH_VN_SHLVL, vshlvl, SH_VO_LOC), 1);
	ft_memdel((void**)&vshlvl);
	return (0);
}
