//
// Created by xbluecode on 17.05.19.
//

#ifndef SH_VAR_H
# define SH_VAR_H

# include "ftsh.h"

# define SH_VAR_MAX 32

# define SH_VN_FTSH "FTSH"
# define SH_VV_FTSH "FTSH"
# define SH_VN_SHLVL "SHLVL"
# define SH_VV_SHLVL "1"

# define SH_VN_SHPID "$"
# define SH_VV_SHPID 0x00
# define SH_VO_SHPID 0x00

# define SH_VN_ESTAT "?"
# define SH_VV_ESTAT 0x00
# define SH_VO_ESTAT 0x00

# define SH_VO_LOC 0x0
# define SH_VO_GLO 0x1
# define SH_VO_RDO 0x2

t_table 		*sh_var(void);
int 			sh_var_start(char **envp);
int 			sh_var_inherit(char **envp);
int 			sh_var_init(void);
int 			sh_var_init_ftsh(void);
int 			sh_var_init_id(void);
int 			sh_var_init_hist(void);
char 			**sh_var_env(void);
int 			sh_var_copy(char **envp);
int 			sh_var_auto(void);

int 			sh_var_tsel_glo(t_trow trow);
char 			*sh_var_tbuild_env(t_trow trow);

t_hset			*sh_varh(void);
int 			sh_varh_start(char **envp);
int 			sh_varh_inherit(char **envp);
int 			sh_varh_init(void);
int 			sh_varh_init_ftsh(void);
int 			sh_varh_init_id(void);
int 			sh_varh_init_hist(void);
char 			**sh_varh_env(void);
int 			sh_varh_copy(char **envp);
int 			sh_varh_auto(void);

int 			sh_varh_tsel_glo(t_trow trow);
char 			*sh_varh_tbuild_env(t_trow trow);

#endif //FTSH_SH_ENV_H
