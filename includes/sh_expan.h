#ifndef SH_EXPAN_H
# define SH_EXPAN_H

# include "sh_lex.h"
# include "sh_exec.h"

int		sh_xp_start(t_sh *sh, t_dastr *words);
int		sh_xp_assign(t_sh *sh, t_dastr *assigns);

int 	sh_xp_brace(t_sh *sh, t_dastr *words, int *i, int *j);

int 	sh_xp_param(t_sh *sh, t_dastr *words, int *i, int *j);

int 	sh_xp_var(t_sh *sh, t_dastr *words, int *i, int *j);

int 	sh_xp_dq(t_sh *sh, t_dastr *words, int *i, int *j);
int 	sh_xp_sq(t_sh *sh, t_dastr *words, int *i, int *j);
int 	sh_xp_esc(t_sh *sh, t_dastr *words, int *i, int *j);

int 	sh_xp_tilde(t_sh *sh, t_dastr *words, int *i, int *j);

#endif
