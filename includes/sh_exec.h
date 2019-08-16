#ifndef SH_EXEC_H
# define SH_EXEC_H

#include "sh_parser.h"
/*
int			sh_e_loop(void *gr);
int			sh_e_for(void *gr);
int			sh_e_com_cmds(void *gr);
int			sh_e_com_cmd(void *gr);
int			sh_e_and_or(void *gr);
int			sh_e_pipe(void *gr);
int			sh_e_cmd(void *gr);
int			sh_e_cmd_core(int t);
int			sh_e_simp_cmd(void *gr);
int			sh_e_comp_cmd(void *gr);
int			sh_e_group(void *gr);
*/


int			sh_e_loop(t_jcon *jc, void *gr);
int			sh_e_for(t_jcon *jc, void *gr);
int			sh_e_com_cmds(t_jcon *jc, void *gr);
int			sh_e_com_cmd(t_jcon *jc, void *gr);
int			sh_e_and_or(t_jcon *jc, void *gr);
int			sh_e_pipe(t_jcon *jc, void *gr);
int			sh_e_cmd(t_jcon *jc, void *gr);
int			sh_e_cmd_core(int t);
int			sh_e_simp_cmd(t_jcon *jc, void *gr);
int			sh_e_comp_cmd(t_jcon *jc, void *gr);
int			sh_e_group(t_jcon *jc, void *gr);

#endif
