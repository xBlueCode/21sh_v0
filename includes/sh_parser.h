#ifndef SH_PARSER_H
# define SH_PARSER_H

# include "libft.h"
# include "sh_lex.h"

static int p_lev = 0;

/*
# define DP0 ft_printf("DP0\n");
# define DPM0 ft_printf("  DPM0\n");
# define DPM1 ft_printf("    DPM1\n");
# define DPTOKPUT(tok) ft_printf("Tok");
*/


# define DPTEST if (p->tlook)
# define DP0_STR(dstr) dstr ? dstr->str : "."
# define DPLEV(shift) (p->lev += shift)

# define DP0 DPTEST {DPLEV(2); ft_printf("%3d%*c %-24s : %2d :%s\n",p->lev, p->lev, '-', \
__FUNCTION__, \
((t_token*)p->tlook->content)->t, \
DP0_STR(((t_token*)p->tlook->content)->val)); \
}


# define DPM0 DPTEST {DPLEV(2); ft_printf(C_YLW"%3d%*c %-24s : %2d :%s <%d>\n"T_END, p->lev, p->lev, '-', \
__FUNCTION__, \
((t_token*)p->tlook->content)->t, \
DP0_STR(((t_token*)p->tlook->content)->val), toktype); \
}


# define DPM1 DPTEST {ft_printf(C_GRN"%3d%*c %-24s : %2d :%s <%d>\n"T_END, p->lev, p->lev, '-', \
__FUNCTION__, \
((t_token*)p->tlook->content)->t, \
DP0_STR(((t_token*)p->tlook->content)->val), toktype); \
}

# define DPTOKPUT(tok) ft_printf(C_RED"Tok: %-4d - %-24s %3d\n"T_END, tok->t, tok->val ? tok->val->str : "", tok->assi);

# define PRET(ret) {DPLEV(-2); return (ret);}

typedef struct	s_parser
{
	t_list		*tbase;
	t_list		*tlook;
	t_list		*tlast;
	int			lev;
//	t_btree		***ast;
}				t_parser;

typedef enum	e_grammar_rules
{
	SH_GR_START,
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

int 			sh_p_start(t_lex *lex);
int				sh_p_program(t_parser *p, t_btree **ast);
int				sh_p_complete_cmds(t_parser *p, t_btree **ast);
int				sh_p_complete_cmds_sub(t_parser *p, t_btree **ast);
int				sh_p_complete_cmd(t_parser *p, t_btree **ast);

int				sh_p_list(t_parser *p, t_btree **ast);
int				sh_p_list_sub(t_parser *p, t_btree **ast);

int				sh_p_and_or(t_parser *p, t_btree **ast);
int				sh_p_and_or_sub(t_parser *p, t_btree **ast);

int				sh_p_pipeline(t_parser *p, t_btree **ast);
int				sh_p_pipe_seq(t_parser *p, t_btree **ast);
int				sh_p_pipe_seq_sub(t_parser *p, t_btree **ast);

int				sh_p_cmd(t_parser *p, t_btree **ast);
int				sh_p_comp_cmd(t_parser *p, t_btree **ast);

int				sh_p_subsh(t_parser *p, t_btree **ast);
int				sh_p_comp_list(t_parser *p, t_btree **ast);

int				sh_p_term(t_parser *p, t_btree **ast);
int				sh_p_term_sub(t_parser *p, t_btree **ast);
/*
int				sh_p_for_clause(t_parser *p, t_btree **ast);

int				sh_p_name(t_parser *p, t_btree **ast);
int				sh_p_in(t_parser *p, t_btree **ast);

int				sh_p_wordlist(t_parser *p, t_btree **ast);
int				sh_p_wordlist_sub(t_parser *p, t_btree **ast);

int				sh_p_case_clause(t_parser *p, t_btree **ast);
int				sh_p_case_list_ns(t_parser *p, t_btree **ast);
int				sh_p_case_list(t_parser *p, t_btree **ast);
int				sh_p_case_list_sub(t_parser *p, t_btree **ast);
int				sh_p_case_item_ns(t_parser *p, t_btree **ast);
int				sh_p_case_item(t_parser *p, t_btree **ast);

int				sh_p_patt(t_parser *p, t_btree **ast);
int				sh_p_patt_sub(t_parser *p, t_btree **ast);

int				sh_p_if_clause(t_parser *p, t_btree **ast);
int				sh_p_else_part(t_parser *p, t_btree **ast);

int				sh_p_while_clause(t_parser *p, t_btree **ast);
int				sh_p_until_clause(t_parser *p, t_btree **ast);

int				sh_p_func_def(t_parser *p, t_btree **ast);
int				sh_p_func_bod(t_parser *p, t_btree **ast);
int				sh_p_fname(t_parser *p, t_btree **ast);
*/
int				sh_p_cb_group(t_parser *p, t_btree **ast);
//int				sh_p_do_group(t_parser *p, t_btree **ast);

int				sh_p_simp_cmd(t_parser *p, t_btree **ast);
int				sh_p_cmd_name(t_parser *p, t_btree **ast);
int				sh_p_cmd_word(t_parser *p, t_btree **ast);
int				sh_p_cmd_pref(t_parser *p, t_btree **ast);
int				sh_p_cmd_pref_sub(t_parser *p, t_btree **ast);
int				sh_p_cmd_suff(t_parser *p, t_btree **ast);
int				sh_p_cmd_suff_sub(t_parser *p, t_btree **ast);

int				sh_p_redir_list(t_parser *p, t_btree **ast);
int				sh_p_redir_list_sub(t_parser *p, t_btree **ast);

int				sh_p_io_redir(t_parser *p, t_btree **ast);
int				sh_p_io_file(t_parser *p, t_btree **ast);
int				sh_p_filename(t_parser *p, t_btree **ast);
int				sh_p_io_here(t_parser *p, t_btree **ast);
int				sh_p_here_end(t_parser *p, t_btree **ast);

int				sh_p_nl_list(t_parser *p, t_btree **ast);
int				sh_p_nl_list_sub(t_parser *p, t_btree **ast);

int				sh_p_lbreak(t_parser *p, t_btree **ast);
int				sh_p_sep_op(t_parser *p, t_btree **ast);
int				sh_p_sep(t_parser *p, t_btree **ast);
int				sh_p_seq_sep(t_parser *p, t_btree **ast);

int				sh_p_lookshift(t_parser *p);
int				sh_p_match(t_parser *p, t_btree **ast, int toktype);

#endif
