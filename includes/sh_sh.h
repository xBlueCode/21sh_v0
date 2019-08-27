#ifndef FT_SH_H
# define FT_SH_H

# include "sh_jctype.h"
//# include "sh_jobc.h"
# include "libft.h"

# define SH_MODE_INT	0x01
# define SH_MODE_SCR	0x02
# define SH_MODE_SSH	0x04
# define SH_MODE_SCMD	0x08
# define SH_MODE_INDQ	0x10
// TODO: max is 7

/**
 * bin_ht:		hash-table of bins <name, path>
 * bin_nl:		list of bin names
 */
typedef struct	s_sh
{
	int			mode;
	t_jcon		*jc;
	pid_t		pgid;
	t_termios	tmodes;
	int			term_std;
	t_term		term;
	int			inter;
	int 		stdi;
	int 		stdo;
	t_hset		*bin_ht;
	t_dastr		*bin_nl;
	t_table		*var;
	int 		sub_pipe[2];
	t_dstr		*sub_out;
}				t_sh;

t_sh 			*sh_sh(void);
int 			sh_sh_init(t_sh **sh, char **envp, int mode);
t_sh 			*sh_sh_clone(t_sh *sh, int mode);
int 			sh_sh_new(t_sh **sh);
int 			sh_sh_free(t_sh **sh);

#endif
