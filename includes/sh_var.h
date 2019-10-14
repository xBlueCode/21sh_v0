/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_var.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 19:34:31 by abbesbes          #+#    #+#             */
/*   Updated: 2019/10/07 19:34:36 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_VAR_H
# define SH_VAR_H

# include "ftsh.h"

# define SH_VAR_MAX 128

# define SH_VO_LOC 0x1
# define SH_VO_GLO 0x2
# define SH_VO_RDO 0x3

# define SH_VN_FTSH "FTSH"
# define SH_VV_FTSH "FTSH"
# define SH_VN_SHLVL "SHLVL"
# define SH_VV_SHLVL "1"

# define SH_VN_SHPID "$"
# define SH_VV_SHPID 0x00
# define SH_VO_SHPID SH_VO_LOC

# define SH_VN_ESTAT "?"
# define SH_VV_ESTAT 0x00
# define SH_VO_ESTAT SH_VO_LOC

# define SH_VN_PS1 "PS1"
# define SH_VV_PS1 "\\h@\\u $ "

t_table			*sh_var(void);
int				sh_var_start(t_table **var, char **envp);
int				sh_var_inherit(t_table *var, char **envp);
int				sh_var_init(t_table *var);
int				sh_var_init_ftsh(t_table *var);
int				sh_var_init_id(t_table *var);
int				sh_var_init_hist(t_table *var);
char			**sh_var_env(void);
int				sh_var_copy(char **envp);
int				sh_var_auto(void);
int				sh_varins(t_table *table, char *str, int m);
int				sh_varins_nv(t_table *table, char *name, char *value, int m);

int				sh_var_tsel_glo(t_trow trow);
char			*sh_var_tbuild_env(t_trow trow);

int				sh_var_geti(char *name);
char			*sh_var_getval(t_table *var, char *name);

int				sh_var_assign(t_table *envt, t_dastr *assigns);
char			*sh_env_getval(char **envp, char *name);

t_hset			*sh_varh(void);
int				sh_varh_start(char **envp);
int				sh_varh_inherit(char **envp);
int				sh_varh_init(void);
int				sh_varh_init_ftsh(void);
int				sh_varh_init_id(void);
int				sh_varh_init_hist(void);
char			**sh_varh_env(void);
int				sh_varh_copy(char **envp);
int				sh_varh_auto(void);

int				sh_varh_tsel_glo(t_trow trow);
char			*sh_varh_tbuild_env(t_trow trow);

#endif
