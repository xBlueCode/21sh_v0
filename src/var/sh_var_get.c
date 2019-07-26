#include "libft.h"
#include "ftsh.h"

char	*sh_var_getval(char *name)
{
	t_trow	trow;

	trow = ft_tabget_n(sh_var(), name);
	return (trow.value);
}
