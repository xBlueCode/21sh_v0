#include "ftsh.h"

int 	sh_e_check_exec(char *cmd_name)
{
	if (access(cmd_name, F_OK))
		FT_STDE_RET(127, "ftsh: Command not found !")
	else if (access(cmd_name, X_OK))
		FT_STDE_RET(126, "ftsh: Command not found !");
	return (OK);
}

int 	sh_e_check_built(char *cmd_name)
{

}