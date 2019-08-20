#ifndef SH_GRAM_TYPE_H
# define SH_GRAM_TYPE_H

#include "libft.h"
#include "sh_sh.h"

typedef int (t_exec)(t_sh*, void*);

typedef struct	s_redir
{
	int 	ion;
	int 	op;
	char 	*word;
}				t_redir;

typedef struct	s_simp_cmd // process
{
	t_list	*lst_assign;
	t_dastr	*lst_words;
	t_list	*lst_redir;
	pid_t 	pid;
	char 	state;
	int 	status;
//	int 	cnt_op;
}				t_simp_cmd;

typedef struct	s_cmd
{
	void 	*core; // simp_cmd, com_cmd, for, loop
	t_list	*lst_redir;
	int16_t	type;
	t_exec	*exec;
	int 	stdioe[3];
//	int 	stdi;
//	int 	stdo;
//	int 	stde;
}				t_cmd;

typedef struct	s_pipe
{
	t_list	*lst_cmd;
	int8_t	neg;
}				t_pipe;

typedef struct	s_and_or
{
	t_list	*lst_pipe;
	t_dstr	*sep; // &&, ||
}				t_and_or;

typedef struct	s_com_cmd // comp_list
{
	t_list	*lst_and_or;
	int 	gr; // it can be _COM_CMD, _SUBSH, _CB_GROUP, _DO_GROUP  // gr=group
	t_dstr	*sep; // ;, &
}				t_com_cmd;

typedef struct	s_com_cmds
{
	t_list	*lst_com_cmd;
}				t_com_cmds;

typedef struct	s_for
{
	t_dstr		*name;
	t_list		*lst_wordlist;
	t_com_cmd	*do_group;
}				t_for;

typedef struct	s_loop
{
	t_com_cmd	*cond;
	t_com_cmd	*do_group;
}				t_loop;

#endif
