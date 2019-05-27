/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_lex.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 16:53:18 by abbesbes          #+#    #+#             */
/*   Updated: 2019/03/16 17:49:42 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_LEX_H
# define SH_LEX_H

# define XTK_START_GL		"><=!&|"
# define XTK_START_ENAO		"><=!&|"
# define XTK_START_ARITH	"+-*%/"
# define XTK_START_PONCT	"\\$;\n"
# define XTK_START_CLOSURE	"([{)]}"
# define XTK_START_QUOTE	"\"\'`"
# define XTK_START_SUB		"`$"

# define SH_LEX_SEPSET "'\"`<>!&|;\n"
# define SH_LEX_OPSET "<>!&|;"

# define XTK_DQ_ESC			"`\"\n"

# define XTK_ISWS(ch)		(ch == ' ' || ch == '\t')

# define SH_LEX(lex, i) lex->in->str[i]

typedef enum	e_token_state
{
	TSNONE = 0,
	TSSTART,
	TSSTOP,
	TSCONT,
	TSSEP,
	TSWS,

	TSG,
	TSL,
	TSE,
	TSN,
	TSA,
	TSO,
	TSP,
	TSM,
	TSAES,
	TSMOD,
	TSSH,
	TSBSH,
	TSD,
	TSSC,
	TSNL,
	TSPL,
	TSPR,
	TSBL,
	TSBR,
	TSCBL,
	TSCBR,
	TSSQ,
	TSDQ,
	TSBQ,
	TSW,

	TSG2,
	TSG_E,
	TSG_A,
	TSG_O,

	TSL_G,
	TSL2,
	TSL2_M,
	TSL_E,
	TSL_A,
	TSL_O,

	TSE2,

	TSN_E,

	TSA_G,
	TSA2,

	TSO2,

	TSP2,
	TSP_E,
	TSM2,
	TSM_E,

	TSAES_E,
	TSMOD_E,
	TSSH_E,

	TSMp,

	TSD_PL,
	TSD_PL2,
	TSD_CBL,

	TSSC2,

	TSPL2,
	TSPR2,

	TSESC,
	TSWSQ,
	TSWDQ,
	TSWBQ,
}				t_token_state;

typedef struct	s_token
{
	int		t;
	ssize_t p;
	int 	l;
	t_dstr	*val;
}				t_token;

typedef struct	s_lex
{
	//char 	*str;
	t_dstr	*buf;
	t_dstr	*in;
	ssize_t	off;
	ssize_t i;
	t_dstr	*scope;
	uint8_t st;
	uint8_t err;
	t_list	*tlst;
	t_list 	*toff;
}				t_lex;


t_lex 			sh_lex(void);
int				sh_lex_init(t_lex **plex, char *input);
int 			sh_lex_free(t_lex **plex);
int 			sh_lex_start(t_lex *lex);
int 			sh_lex_tok_add(t_lex *lex, t_token *tok);
t_token 		*sh_lex_tok_eat(t_lex *lex);
t_token			*sh_lex_tok_get(t_lex *lex);
int 			sh_lex_tok_next(t_lex *lex);
int 			sh_lex_tok_setoff(t_lex *lex);

t_token			*sh_lex_tok_new(int type, ssize_t pos, int len, char *xme);
int				sh_lex_tok_free(t_token **ptok);

int 			sh_lex_seek(t_lex *lex, int op);
int 			sh_lex_seek_all(t_lex *lex, int op);
int 			sh_lex_seek_space(t_lex *lex, int op);
int 			sh_lex_seek_escape(t_lex *lex, int op);
int 			sh_lex_seek_join(t_lex *lex, int op);


int 			sh_lex_seek_nl(t_lex *lex, int op);

int 			sh_lex_seek_op(t_lex *lex, int op);
int 			sh_lex_seek_op_sc(t_lex *lex, int op);
int 			sh_lex_seek_op_a(t_lex *lex, int op);
int 			sh_lex_seek_op_o(t_lex *lex, int op);
int 			sh_lex_seek_op_g(t_lex *lex, int op);
int 			sh_lex_seek_op_l(t_lex *lex, int op);

int 			sh_lex_seek_wo(t_lex *lex, int op);

int 			sh_lex_seek_hd(t_lex *lex, int op);
int 			sh_lex_seek_sq(t_lex *lex, int op);
int 			sh_lex_seek_dq(t_lex *lex, int op);
int 			sh_lex_seek_bq(t_lex *lex, int op);
int 			sh_lex_seek_param(t_lex *lex, int op);
int 			sh_lex_seek_smath(t_lex *lex, int op);
int 			sh_lex_seek_scmd(t_lex *lex, int op);

int				sh_lex_seek_add(t_lex *lex, int op);

/*
t_list			*x_tokenize(char *in, int m);
int				xtk_recognize(char *in, int off, t_list	**tklist, int m);
int				xtk_add(t_list **tklist, int ts, char *xme, int mode);

int				xtk_start_arith(char *in, int off, t_list **tklist, int m);
int				xtk_start_closure(char *in, int off, t_list **tklist, int m);
int				xtk_start_enao(char *in, int off, t_list **tklist, int m);
int				xtk_start_gl(char *in, int off, t_list **tklist, int m);
int				xtk_start_g(char *in, int off, t_list **tklist, int m);
int				xtk_start_l(char *in, int off, t_list **tklist, int m);
int				xtk_start_ponct(char *in, int off, t_list **tklist, int m);
int				xtk_start_esc(char *in, int off, t_list **tklist, int m);

int				xtk_start_quote(char *in, int off, t_list **tklist, int m);
int				xtk_start_squote(char *in, int off, t_list **tklist, int m);
int				xtk_start_dquote(char *in, int off, t_list **tklist, int m);
*/

#endif
