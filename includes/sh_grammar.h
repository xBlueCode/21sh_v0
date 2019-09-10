#ifndef SH_GRAMMAR_H
#define SH_GRAMMAR_H

# include "libft.h"
# include "sh_lex.h"
# include "sh_parser.h"
# include "sh_gram_type.h"
//# include "sh_gr_type.h"
//#include "sh_exec.h"

# define SHG_CHECK_MALL(g) {if (!(g = ft_memalloc(sizeof(*g)))) return (NULL);};
# define SHG_LSTADD(g, lst, ncont) ft_lst_addlast(&(g->lst), ft_lstnew(ncont, sizeof(*ncont)));
# define SHG_LSTADD_FREE(g, lst, ncont) {ft_lst_addlast(&(g->lst), ft_lstnew(ncont, sizeof(*ncont)));FT_MEMDEL(ncont)}
# define SHG_LSTADDS(g, lst, nc, ns) ft_lst_addlast(&(g->lst), ft_lstnew(nc, ns));

# define SHG_CHECK_AST(node, gt) {if (!node || node->op != gt) return (NULL);};

# define SHG_AST_TOK(ast) ((t_token*)(ast)->data)

# define SHG_PUT_CASTVAR(v, g, t, op) v = op ? ((t)(((t_list*)g)->content)) : (t)g;

# define SHG_PUT_CASTFUN(f) ((void(*)(t_list*, int))&f)

# define SHG_PUT_PRINTF(str, l) ft_printf("%*c %s", l * 4, '-', str);

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
	SH_GR_ELIF,
	SH_GR_IFBODY,
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


typedef void *(t_g_new)(void);
typedef void *(t_g_seek)(t_btree*);
typedef void (put)(void*, int);
//typedef int (t_exec)(t_sh*, gr);

typedef struct	s_gr
{
	int		t;
	void	*(*n)(void);
	void	*(*parse)(t_btree*);
	void	(*put)(void*, int);
}				t_gr;

/*
int				sh_g_com_cmds(t_btree *ast, void *);
int				sh_g_com_cmd(t_btree *ast, void *);
int				sh_g_and_or(t_btree *ast, void *);
int				sh_g_pipe(t_btree *ast, void *);
int				sh_g_cmd(t_btree *ast, void *);
int				sh_g_redir(t_btree *ast, void *);
*/

void			*sh_g_loop_new(void);
void			*sh_g_for_new(void);
void			*sh_g_com_cmds_new(void);
void			*sh_g_com_cmd_new(void);
void			*sh_g_and_or_new(void);
void			*sh_g_pipe_new(void);
void			*sh_g_cmd_new(void);
void			*sh_g_cmd_core_new(int t);
void			*sh_g_simp_cmd_new(void);
void			*sh_g_comp_cmd_new(void);
void			*sh_g_redir_new(void);

void			sh_g_loop_free(void**g);
void			sh_g_for_free(void**g);
void			sh_g_com_cmds_free(void**g);
void			sh_g_com_cmd_free(void**g);
void			sh_g_and_or_free(void**g);
void			sh_g_pipe_free(void**g);
void			sh_g_cmd_free(void**g);
void			sh_g_cmd_core_free(int t);
void			sh_g_simp_cmd_free(void**g);
void			sh_g_comp_cmd_free(void**g);
void			sh_g_redir_free(void**g);

void			*sh_g_loop(t_btree *ast);
void			*sh_g_for(t_btree *ast);
void			*sh_g_com_cmds(t_btree *ast);
void			*sh_g_com_cmd(t_btree *ast);
void			*sh_g_and_or(t_btree *ast);
void			*sh_g_pipe(t_btree *ast);
void			*sh_g_cmd(t_btree *ast);
void			*sh_g_cmd_core(int t);
void			*sh_g_simp_cmd(t_btree *ast);
void			*sh_g_comp_cmd(t_btree *ast);
void			*sh_g_group(t_btree *ast);
void			*sh_g_redir(t_btree *ast);

void			sh_g_loop_put(void*g, int op);
void			sh_g_for_put(void*g, int op);
void			sh_g_com_cmds_put(void*g, int op);
void			sh_g_com_cmd_put(void*g, int op);
void			sh_g_and_or_put(void*g, int op);
void			sh_g_pipe_put(void*g, int op);
void			sh_g_cmd_put(void*g, int op);
void			*sh_g_cmd_core_put(int t);
void			sh_g_simp_cmd_put(void*g, int op);
void			sh_g_comp_cmd_put(void*g, int op);
void			sh_g_redir_put(void*g, int op);

void			sh_g_wordput(t_list *elem);

int 			sh_g_cmd_core_type(int gr_enum);
t_exec			*sh_g_cmd_core_get_exec(int grt);
t_free			sh_g_cmd_core_get_free(int grt);
#endif
