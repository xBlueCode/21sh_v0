#ifndef SH_EXEC_H
# define SH_EXEC_H

#include "sh_parser.h"
#include "sh_grammar.h"
#include "sh_sh.h"


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

typedef int (t_exec)(t_sh*, void*);
t_exec			sh_e_loop;
t_exec			sh_e_for;
t_exec			sh_e_com_cmds;
t_exec			sh_e_com_cmd;
t_exec			sh_e_and_or;
t_exec			sh_e_pipe;
t_exec			sh_e_cmd;
t_exec			sh_e_simp_cmd;
t_exec			sh_e_comp_cmd;
t_exec			sh_e_group;
int				sh_e_cmd_core(int t); // what's wrong with you

/*
int			sh_e_loop(t_sh *sh, void *gr);
int			sh_e_for(t_sh *sh, void *gr);
int			sh_e_com_cmds(t_sh *sh, void *gr);
int			sh_e_com_cmd(t_sh *sh, void *gr);
int			sh_e_and_or(t_sh *sh, void *gr);
int			sh_e_pipe(t_sh *sh, void *gr);
int			sh_e_cmd(t_sh *sh, void *gr);
int			sh_e_cmd_core(int t); // what's wrong with you
int			sh_e_simp_cmd(t_sh *sh, void *gr);
int			sh_e_comp_cmd(t_sh *sh, void *gr);
int			sh_e_group(t_sh *sh, void *gr);
*/

char 		*sh_e_get_binpath(t_sh *sh, char *bin_name);
char		**sh_e_get_argv(t_sh *sh, t_dastr *words);

int 		sh_e_prepare_file(char *fname, int exist, int read, int write);
int 		sh_e_redirect(t_list *redir_lst);
int			sh_e_redirect_g(t_redir *redir);
int			sh_e_redirect_l(t_redir *redir);

#endif
