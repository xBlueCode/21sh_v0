#ifndef SH_PARSER_H
#define SH_PARSER_H

#include "libft.h"
#include "sh_lex.h"

typedef struct	s_parser
{
	t_list		*tokens;
	t_btree		*ast;
}				t_parser;

int				sh_parse_program(t_parser *parser, int op);
int				sh_parse_complete_cmds(t_parser *parser, int op);
int				sh_parse_complete_cmds_sub(t_parser *parser, int op);
int				sh_parse_complete_cmd(t_parser *parser, int op);

int				sh_parse_list(t_parser *parser, int op);
int				sh_parse_list_sub(t_parser *parser, int op);

int				sh_parse_and_or(t_parser *parser, int op);
int				sh_parse_and_or_sub(t_parser *parser, int op);

int				sh_parse_pipeline(t_parser *parser, int op);
int				sh_parse_pipe_seq(t_parser *parser, int op);
int				sh_parse_pipe_seq_sub(t_parser *parser, int op);

int				sh_parse_cmd(t_parser *parser, int op);
int				sh_parse_comp_cmd(t_parser *parser, int op);

int				sh_parse_subshell(t_parser *parser, int op);
int				sh_parse_comp_list(t_parser *parser, int op);

int				sh_parse_term(t_parser *parser, int op);
int				sh_parse_term_sub(t_parser *parser, int op);

int				sh_parse_for_clause(t_parser *parser, int op);

int				sh_parse_name(t_parser *parser, int op);
int				sh_parse_in(t_parser *parser, int op);

int				sh_parse_wordlist(t_parser *parser, int op);
int				sh_parse_wordlist_sub(t_parser *parser, int op);

int				sh_parse_case_clause(t_parser *parser, int op);
int				sh_parse_case_list_ns(t_parser *parser, int op);
int				sh_parse_case_list(t_parser *parser, int op);
int				sh_parse_case_list_sub(t_parser *parser, int op);
int				sh_parse_case_item_ns(t_parser *parser, int op);
int				sh_parse_case_item(t_parser *parser, int op);

int				sh_parse_patt(t_parser *parser, int op);
int				sh_parse_patt_sub(t_parser *parser, int op);

int				sh_parse_if_clause(t_parser *parser, int op);
int				sh_parse_else_part(t_parser *parser, int op);

int				sh_parse_while_clause(t_parser *parser, int op);
int				sh_parse_until_clause(t_parser *parser, int op);

int				sh_parse_func_def(t_parser *parser, int op);
int				sh_parse_func_bod(t_parser *parser, int op);
int				sh_parse_fname(t_parser *parser, int op);

int				sh_parse_cb_group(t_parser *parser, int op);
int				sh_parse_do_group(t_parser *parser, int op);

int				sh_parse_simp_cmd(t_parser *parser, int op);
int				sh_parse_cmd_name(t_parser *parser, int op);
int				sh_parse_cmd_word(t_parser *parser, int op);
int				sh_parse_cmd_pref(t_parser *parser, int op);
int				sh_parse_cmd_pref_sub(t_parser *parser, int op);
int				sh_parse_cmd_suff(t_parser *parser, int op);
int				sh_parse_cmd_suff_sub(t_parser *parser, int op);

int				sh_parse_redir_list(t_parser *parser, int op);
int				sh_parse_redir_list_sub(t_parser *parser, int op);

int				sh_parse_io_redir(t_parser *parser, int op);
int				sh_parse_io_file(t_parser *parser, int op);
int				sh_parse_filename(t_parser *parser, int op);
int				sh_parse_io_here(t_parser *parser, int op);
int				sh_parse_here_end(t_parser *parser, int op);

int				sh_parse_nl_list(t_parser *parser, int op);
int				sh_parse_nl_list_sub(t_parser *parser, int op);

int				sh_parse_lbreak(t_parser *parser, int op);
int				sh_parse_sep_op(t_parser *parser, int op);
int				sh_parse_sep(t_parser *parser, int op);
int				sh_parse_seq_sep(t_parser *parser, int op);

#endif
