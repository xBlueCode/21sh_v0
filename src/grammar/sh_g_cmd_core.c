#include "ftsh.h"

extern int 	g_g_putlev;

static int	g_cmd_core_types[] = {
		SH_GR_SIMP_CMD,
		SH_GR_SUBSH,
		SH_GR_CB_GROUP,
		SH_GR_DO_GROUP,
		SH_GR_FOR_CLAUSE,
		SH_GR_WHILE_CLAUSE,
		SH_GR_UNTIL_CLAUSE,
		SH_GR_FUNC_DEF,
		-1
		};

static void	*g_cmd_core_new[] = {
		&sh_g_simp_cmd_new,
//		&sh_g_comp_cmd_new,
		NULL
		};

static void	*g_cmd_core[] = {
		&sh_g_simp_cmd,
		&sh_g_group,
		&sh_g_group,
		&sh_g_group,
		&sh_g_for,
		&sh_g_loop,
		&sh_g_loop,
		NULL
};

static void	*g_cmd_core_put[] = {
		&sh_g_simp_cmd_put,
		sh_g_com_cmd_put,
		sh_g_com_cmd_put,
		sh_g_com_cmd_put,
		sh_g_for_put,
		sh_g_loop_put,
		sh_g_loop_put,
		NULL
};

static void	*g_cmd_core_exec[] = {
		&sh_e_simp_cmd,
		sh_e_com_cmd,
		sh_e_com_cmd,
		sh_e_com_cmd,
//		sh_e_for,
//		sh_e_loop,
//		sh_e_loop,
		NULL
};

static void	*g_cmd_core_wait[] = {
		&sh_e_simp_cmd_wait,
		sh_e_com_cmd_wait,
		sh_e_com_cmd_wait,
		sh_e_com_cmd_wait,
//		sh_e_for_wait,
//		sh_e_loop_wait,
//		sh_e_loop_wait,
		NULL
};

static void	*g_cmd_core_kill[] = {
		&sh_e_simp_cmd_kill,
		sh_e_com_cmd_kill,
		sh_e_com_cmd_kill,
		sh_e_com_cmd_kill,
//		sh_e_for_kill,
//		sh_e_loop_kill,
//		sh_e_loop_kill,
		NULL
};

static void	*g_cmd_core_free[] = {
		&sh_g_simp_cmd_free,
		sh_g_com_cmd_free,
		sh_g_com_cmd_free,
		sh_g_com_cmd_free,
		//sh_g_for_free,
		//sh_g_loop_free,
		//sh_g_loop_free,
		NULL
};

int 		sh_g_cmd_core_type(int gr_enum)
{
	int i;

	i = -1;
	while (g_cmd_core_types[++i] > -1)
		if (g_cmd_core_types[i] == gr_enum)
			return (i);
	return (-1);
}

void		*sh_g_cmd_core_new(int t)
{
	int type;

	if ((type = sh_g_cmd_core_type(t)) < 0)
		return (NULL);
	return (g_cmd_core_new[type]);
}

void		*sh_g_cmd_core(int t)
{
	int type;

//	ft_printf("cmd_core : t=%d\n", t);
	if ((type = sh_g_cmd_core_type(t)) < 0)
		return (NULL);
//	ft_printf("cmd_core : type=%d\n", type);
	return (g_cmd_core[type]);
}
/*
void		*sh_g_group(t_btree *ast, int t)
{

}
*/
void		*sh_g_cmd_core_put(int t)
{
	int type;

	if ((type = sh_g_cmd_core_type(t)) < 0)
		return (NULL);
	return (g_cmd_core_put[type]);
}

t_exec		*sh_g_cmd_core_get_exec(int grt)
{
	int type;

	if ((type = sh_g_cmd_core_type(grt)) < 0)
		return (NULL);
	return (g_cmd_core_exec[type]);
}

t_wait		*sh_g_cmd_core_get_wait(int grt)
{
	int type;

	if ((type = sh_g_cmd_core_type(grt)) < 0)
		return (NULL);
	return (g_cmd_core_wait[type]);
}

t_kill		*sh_g_cmd_core_get_kill(int grt)
{
	int type;

	if ((type = sh_g_cmd_core_type(grt)) < 0)
		return (NULL);
	return (g_cmd_core_kill[type]);
}

t_free		sh_g_cmd_core_get_free(int grt)
{
	int type;

	if ((type = sh_g_cmd_core_type(grt)) < 0)
		return (NULL);
	return (g_cmd_core_free[type]);
}
