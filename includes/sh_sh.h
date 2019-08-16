#ifndef FT_SH_H
#define FT_SH_H

#include "libft.h"
#include "sh_jobc.h"

/**
 *
 */
typedef struct	s_sh
{
	t_jcon		*jc;
	pid_t		pgid;
	t_termios	tmodes;
	int			term;
	int			inter;
}				t_sh;

#endif
