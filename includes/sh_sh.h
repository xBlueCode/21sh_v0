#ifndef FT_SH_H
# define FT_SH_H

# include "sh_jctype.h"
//# include "sh_jobc.h"
# include "libft.h"

/**
 *
 */
typedef struct	s_sh
{
	t_jcon		*jc;
	pid_t		pgid;
	t_termios	*tmodes;
	int			term;
	int			inter;
	int 		stdi;
	int 		stdo;
}				t_sh;

t_sh 			*sh_sh(void);
int 			sh_sh_init(t_sh **sh);
int 			sh_sh_new(t_sh **sh);
int 			sh_sh_free(t_sh **sh);

#endif
