#ifndef SH_EXEC_H
# define SH_EXEC_H

# include "sh_parser.h"
# include "sh_grammar.h"
# include "sh_sh.h"
# include <signal.h>

# define SH_E_STATE_DONE 1
# define SH_E_STATE_STOP 2
# define SH_E_STATE_EXEC 3

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

typedef int (t_wait)(t_sh*, void*, int op, int *state);
t_wait			sh_e_loop_wait;
t_wait			sh_e_for_wait;
t_wait			sh_e_com_cmds_wait;
t_wait			sh_e_com_cmd_wait;
t_wait			sh_e_and_or_wait;
t_wait			sh_e_pipe_wait;
t_wait			sh_e_cmd_wait;
t_wait			sh_e_simp_cmd_wait;
t_wait			sh_e_comp_cmd_wait;
t_wait			sh_e_group_wait;
int				sh_e_cmd_lst_wait(t_sh *sh, t_list *cmd_lst, int op, int *state);

typedef int (t_kill)(t_sh*, void*, int sig);
t_kill			sh_e_loop_kill;
t_kill			sh_e_for_kill;
t_kill			sh_e_com_cmds_kill;
t_kill			sh_e_com_cmd_kill;
t_kill			sh_e_and_or_kill;
t_kill			sh_e_pipe_kill;
t_kill			sh_e_cmd_kill;
t_kill			sh_e_simp_cmd_kill;
t_kill			sh_e_comp_cmd_kill;
t_kill			sh_e_group_kill;

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
char		**sh_e_get_envp(t_sh *sh, t_dastr *assigns);

int 		sh_e_check_exec(char *cmd_name);
int 		sh_e_check_built(char *cmd_name);

int 		sh_e_run_exec(t_sh *sh, t_simp_cmd *simp_cmd);
int 		sh_e_run_built(t_sh *sh, t_simp_cmd *simp_cmd);
int 		sh_e_run_env(t_sh *sh, t_simp_cmd *simp_cmd);

int 		sh_e_prepare_file(char *fname, int exist, int read, int write);
int 		sh_e_redirect(t_list *redir_lst);
int			sh_e_redirect_g(t_redir *redir);
int			sh_e_redirect_l(t_redir *redir);
int			sh_e_redirect_l2(t_redir *redir);

#endif
