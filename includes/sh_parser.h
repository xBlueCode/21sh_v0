/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_parser.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 19:34:17 by abbesbes          #+#    #+#             */
/*   Updated: 2019/10/07 19:34:19 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_PARSER_H
# define SH_PARSER_H

# include "libft.h"
# include "sh_grammar.h"
# include "sh_lex.h"

static int g_p_lev = 0;

# define DPTEST if (p && p->tlook)
# define DP0_STR(dstr) dstr ? dstr->str : "."
# define DPLEV(shift) (p->lev += shift)
# define SHP_CAST_INIT(gr) cast = ft_btreenew(NULL, 0); cast->op = gr;
# define SHP_CAST_L &(cast->left)
# define SHP_CAST_R &(cast->right)

# define DP0

# define DPM0

# define DPM1

# define P1(tok) tok->t, tok->val ? tok->val->str : "", tok->assi
# define DPTOKPUT(tok) ft_printf(C_RED"Tok: %-4d - %-24s %3d\n"T_END, P1(tok));

# define FREE_CAST ft_btreefree(&cast, (t_free)&sh_lex_tok_tfree);

# define P2(r) DPLEV(-2); return (r);
# define PRET(ret) {{if (ast && ret == 1) *ast = cast; else FREE_CAST} P2(ret)}

# define PMRET(ret) {DPLEV(-2); return (ret);}

typedef struct	s_parser
{
	t_list		*tlook;
	int			lev;
	t_dastr		*hd_val;
}				t_parser;

t_com_cmds		*sh_p_start(t_lex *lex);
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

int				sh_p_for_clause(t_parser *p, t_btree **ast);
int				sh_p_loop(t_parser *p, t_btree **ast);

int				sh_p_name(t_parser *p, t_btree **ast);
int				sh_p_in(t_parser *p, t_btree **ast);

int				sh_p_wordlist(t_parser *p, t_btree **ast);
int				sh_p_wordlist_sub(t_parser *p, t_btree **ast);

int				sh_p_if_clause(t_parser *p, t_btree **ast);
int				sh_p_else_part(t_parser *p, t_btree **ast);
int				sh_p_ifbody(t_parser *p, t_btree **ast);

int				sh_p_while_clause(t_parser *p, t_btree **ast);
int				sh_p_until_clause(t_parser *p, t_btree **ast);

int				sh_p_cb_group(t_parser *p, t_btree **ast);
int				sh_p_do_group(t_parser *p, t_btree **ast);

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

int				sh_tok_getrw(char *tokval);
int				sh_tok_distinct(t_token *token, int target);
int				sh_tok_isname_till(char *val, char delim);

void			test_sh_p_astapp(t_btree *root);

#endif
