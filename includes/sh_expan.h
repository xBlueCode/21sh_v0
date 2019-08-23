#ifndef SH_EXPAN_H
# define SH_EXPAN_H

# include "sh_lex.h"
# include "sh_exec.h"

int		sh_xp_start(t_sh *sh, t_dastr *words);

int 	sh_xp_brace(t_sh *sh, t_dastr *words, int *i, int *j, int op);

int 	sh_xp_tilde(t_sh *sh, t_dastr *words, int *i, int *j);

#endif
