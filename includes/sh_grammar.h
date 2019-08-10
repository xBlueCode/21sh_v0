#ifndef SH_GRAMMAR_H
#define SH_GRAMMAR_H

# include "libft.h"
# include "sh_lex.h"
# include "sh_parser.h"

# define SHG_MALLCHECK(g) {if (!(g = ft_memalloc(sizeof(*g)))) return (NULL);};
# define SHG_LSTADD(g, lst, ncont) ft_lst_addlast(&(g->lst), ft_lstnew(ncont, sizeof(*ncont)));

typedef enum	e_grammar_rules
{
	SH_GR_START = TSMAX + 1,
	SH_GR_PROGRAM,
	SH_GR_COMPLETE_CMDS,
	SH_GR_COMPLETE_CMDS_SUB,
	SH_GR_COMPLETE_CMD,
	SH_GR_LIST,
	SH_GR_LIST_SUB,
	SH_GR_AND_OR,
	SH_GR_AND_OR_SUB,
	SH_GR_PIPELINE,
	SH_GR_PIPE_SEQ,
	SH_GR_PIPE_SEQ_SUB,
	SH_GR_CMD,
	SH_GR_COMP_CMD,
	SH_GR_SUBSH,
	SH_GR_COMP_LIST,
	SH_GR_TERM,
	SH_GR_TERM_SUB,
	SH_GR_FOR_CLAUSE,
	SH_GR_NAME,
	SH_GR_IN,
	SH_GR_WORDLIST,
	SH_GR_WORDLIST_SUB,
	SH_GR_CASE_CLAUSE,
	SH_GR_CASE_LIST_NS,
	SH_GR_CASE_LIST,
	SH_GR_CASE_LIST_SUB,
	SH_GR_CASE_ITEM_NS,
	SH_GR_CASE_ITEM,
	SH_GR_PATT,
	SH_GR_PATT_SUB,
	SH_GR_IF_CLAUSE,
	SH_GR_ELSE_PART,
	SH_GR_WHILE_CLAUSE,
	SH_GR_UNTIL_CLAUSE,
	SH_GR_FUNC_DEF,
	SH_GR_FUNC_BOD,
	SH_GR_FNAME,
	SH_GR_CB_GROUP,
	SH_GR_DO_GROUP,
	SH_GR_SIMP_CMD,
	SH_GR_CMD_NAME,
	SH_GR_CMD_WORD,
	SH_GR_CMD_PREF,
	SH_GR_CMD_PREF_SUB,
	SH_GR_CMD_SUFF,
	SH_GR_CMD_SUFF_SUB,
	SH_GR_REDIR_LIST,
	SH_GR_REDIR_LIST_SUB,
	SH_GR_IO_REDIR,
	SH_GR_IO_FILE,
	SH_GR_FILENAME,
	SH_GR_IO_HERE,
	SH_GR_HERE_END,
	SH_GR_NL_LIST,
	SH_GR_NL_LIST_SUB,
	SH_GR_LBREAK,
	SH_GR_SEP_OP,
	SH_GR_SEP,
	SH_GR_SEQ_SEP
}				t_grammar_rules;

typedef struct	s_redir
{
	int 	ion;
	int 	op;
	char 	*word;
}				t_redir;

typedef struct	s_simp_cmd
{
	t_list	*lst_assign;
	t_list	*lst_words;
	t_list	*lst_redirect;
//	int 	cnt_op;
}				t_simp_cmd;

typedef struct	s_cmd
{
	void 	*core;
	t_list	*lst_redirect;
	int16_t	type;
}				t_cmd;

typedef struct	s_pipe
{
	t_list	*lst_cmd;
	int8_t	neg;
}				t_pipe;

typedef struct	s_and_or
{
	t_list	*lst_pipe;
	t_dstr	*sep;
}				t_and_or;

typedef struct	s_com_cmd
{
	t_list	*lst_and_or;
	t_dstr	*sep;
}				t_com_cmd;

typedef struct	s_com_cmds
{
	t_list	*lst_com_cmd;
}				t_com_cmds;

/*
int				sh_g_com_cmds(t_btree *ast, void *);
int				sh_g_com_cmd(t_btree *ast, void *);
int				sh_g_and_or(t_btree *ast, void *);
int				sh_g_pipe(t_btree *ast, void *);
int				sh_g_cmd(t_btree *ast, void *);
int				sh_g_redir(t_btree *ast, void *);
*/

void			*sh_g_com_cmds_new(void);
void			*sh_g_com_cmd_new(void);
void			*sh_g_and_or_new(void);
void			*sh_g_pipe_new(void);
void			*sh_g_cmd_new(void);
void			*sh_g_redir_new(void);

void			*sh_g_com_cmds(t_btree *ast);
void			*sh_g_com_cmd(t_btree *ast);
void			*sh_g_and_or(t_btree *ast);
void			*sh_g_pipe(t_btree *ast);
void			*sh_g_cmd(t_btree *ast);
void			*sh_g_redir(t_btree *ast);

#endif