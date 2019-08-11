#include "ftsh.h"

void			*sh_g_subsh(t_btree *ast)
{
	t_com_cmd	*subsh;

	SHG_CHECK_AST(ast, SH_GR_SUBSH)
	subsh = sh_g_com_cmd(ast->left);
	subsh->gr = SH_GR_SUBSH;
	return (subsh);
}
