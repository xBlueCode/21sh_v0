#ifndef FT_SH_H
# define FT_SH_H

# include "sh_jctype.h"
//# include "sh_jobc.h"
# include "libft.h"

/**
 * bin_ht:		hash-table of bins <name, path>
 * bin_nl:		list of bin names
 */
typedef struct	s_sh
{
	t_jcon		*jc;
	pid_t		pgid;
	t_termios	tmodes;
	int			term;
	int			inter;
	int 		stdi;
	int 		stdo;
	t_hset		*bin_ht;
	t_dastr		*bin_nl;
}				t_sh;

t_sh 			*sh_sh(void);
int 			sh_sh_init(t_sh **sh, int mode);
int 			sh_sh_new(t_sh **sh);
int 			sh_sh_free(t_sh **sh);

#endif
