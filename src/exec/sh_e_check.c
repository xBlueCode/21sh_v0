#include "ftsh.h"
#include <sys/stat.h>

int 	sh_e_check_exec(char *cmd_name)
{
	char *tail;

	//ft_printf("cmd_name: %s\n", cmd_name);
	if (!(tail = ft_strchr_inv(cmd_name, '/')) || !(++tail))
		tail = cmd_name;
	if (ft_stat_is(cmd_name, S_IFDIR) == OK)
	{
		ft_dprintf(2, C_RED"ftsh: %s: is a directory !\n"T_END, tail);
		return (126);
	}
	if (access(cmd_name, F_OK))
	//	FT_STDE_RET(127, "ftsh: Command not found !")
	{
		ft_dprintf(2, C_RED"ftsh: %s: Command not found !\n"T_END, tail);
		return (126);
	}
	else if (access(cmd_name, X_OK))
	//	FT_STDE_RET(126, "ftsh: Permission denied !")
	{
		ft_dprintf(2, C_RED"ftsh: %s: Permission denied !\n"T_END, tail);
		return (126);
	}
	return (OK);
}

int 	sh_e_check_built(char *cmd_name)
{

}