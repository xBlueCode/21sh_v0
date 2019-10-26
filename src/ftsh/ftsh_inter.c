#include "ftsh.h"
#include <fcntl.h>

t_sh	*g_sh;

int		sh_valid_stdin(void)
{
	int		c;

	if (read(STDIN_FILENO, &c, 0) < 0)
		return (KO);
	return (OK);
}
