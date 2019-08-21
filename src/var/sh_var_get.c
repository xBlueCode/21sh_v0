#include "libft.h"
#include "ftsh.h"

char	*sh_var_getval(t_table *var, char *name)
{
	t_trow	trow;

	trow = ft_tabget_n(var, name);
	return (trow.value);
}
