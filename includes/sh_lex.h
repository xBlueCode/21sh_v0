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

# include "ft_rl.h"

# define SH_LEX_SEPSET "'\"`<>&|;\n$)(" // !
# define SH_LEX_SEPSET_X "<>&|;\n)(" // !
# define SH_LEX_OPSET "<>&|;" // !
# define SH_LEX_TOK_FORB "})" // !

# define SH_LEX_RETERR(lex, error) {lex->err = error; return (-1);}

typedef enum	e_token_state
{
	TSNONE = 0,
	TSSTART = 28,
	TSSTOP,
	TSCONT,
	TSSEP,
	TSWS,
	TSBLANK,
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
	TSO_A,
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
	TSBANG,
	TSION,
	TSNAME,
	TSTOK,
	TSTOK_NAME,
	TSTOK_ASS_WORD,
	TSTOK_WORD,
	TSRW,
	TSRW_IF,
    TSRW_THEN,
    TSRW_ELSE,
    TSRW_ELIF,
    TSRW_FI,
    TSRW_DO,
    TSRW_DONE,
    TSRW_CASE,
    TSRW_ESAC,
	TSRW_WHILE,
    TSRW_UNTIL,
    TSRW_FOR,
    TSRW_IN,
    TSRW_BANG,
    TSRW_LBRACE,
    TSRW_RBRACE,
    TSRW_MAX,
    TSALIAS,
    TSERR,
    TSFAKE,
    TSS_BRACE,
    TSMAX = 223 // TODO: MAX it must be
}				t_token_state;

typedef enum    e_token_context
{
    TCTX_NONE,
    TCTX_FIRSTW,
	TCTX_ALIAS
}               t_tooken_context;

typedef struct	s_token
{
	int		t;
	ssize_t p;
	int 	assi;
	int 	l;
	t_dstr	*val;
}				t_token;

typedef struct	s_lex
{
	//t_dstr	*buf;
	t_dstr	*in;
	ssize_t	off;
	ssize_t i;
	t_dstr	*scope;
	uint8_t st;
	uint8_t ctx;
	uint8_t err;
	t_list	*tlst;
	t_token	*tokend;
	t_list 	*toff;
	t_list  *tclass;
	t_dastr	*hd_key;
	t_dastr *hd_val; // TODO: Transfer to Hashmap<hd_key, hd_val>
	t_hset	*alias_chain;
	int 	alias_off;
	int 	alias_rec;
	int 	assi;
}				t_lex;

typedef int (*t_sh_lex_seeker)(t_lex *lex, int op);

t_lex 			sh_lex(void);
int				sh_lex_init(t_lex **plex, char *input);
t_lex 			*sh_lex_new(char *input);
int 			sh_lex_free(t_lex **plex);
int 			sh_lex_start(t_lex *lex);
int 			sh_lex_tok_add(t_lex *lex, t_token *tok);
t_token 		*sh_lex_tok_eat(t_lex *lex);
t_token			*sh_lex_tok_get(t_lex *lex);
int 			sh_lex_tok_next(t_lex *lex);
int 			sh_lex_tok_setoff(t_lex *lex);

t_token			*sh_lex_tok_new(int type, ssize_t pos, int len, char *xme);
t_token			*sh_lex_tok_set(int type, ssize_t pos, int len, char *xme);
int				sh_lex_tok_free(t_token **ptok);
void			sh_lex_tok_tfree(t_token **ptok);

int 			sh_lex_seek(t_lex *lex, int op);
int 			sh_lex_seek_all(t_lex *lex, int op);
int 			sh_lex_seek_ctx(t_lex *lex, int op);

int				sh_lex_seek_start(t_lex *lex, int op);
int 			sh_lex_seek_tok(t_lex *lex, int op);
int             sh_lex_seek_rescope(t_lex *lex, int op);

int 			sh_lex_seek_blank(t_lex *lex, int op);
int 			sh_lex_seek_escape(t_lex *lex, int op);
int 			sh_lex_seek_hash(t_lex *lex, int op);
int 			sh_lex_seek_join(t_lex *lex, int op);

int 			sh_lex_seek_nl(t_lex *lex, int op);

int 			sh_lex_seek_op(t_lex *lex, int op);
int 			sh_lex_seek_op_sc(t_lex *lex, int op);
int 			sh_lex_seek_op_a(t_lex *lex, int op);
int 			sh_lex_seek_op_o(t_lex *lex, int op);
int 			sh_lex_seek_op_g(t_lex *lex, int op);
int 			sh_lex_seek_op_l(t_lex *lex, int op);

int 	        sh_lex_seek_op_bang(t_lex *lex, int op); // move to classify

int 			sh_lex_seek_ion(t_lex *lex, int op);

int 			sh_lex_seek_wo(t_lex *lex, int op);

int 			sh_lex_seek_sq(t_lex *lex, int op);
int 			sh_lex_seek_dq(t_lex *lex, int op);
int 			sh_lex_seek_bq(t_lex *lex, int op);
int 			sh_lex_seek_param(t_lex *lex, int op);
int 			sh_lex_seek_smath(t_lex *lex, int op);
int 			sh_lex_seek_scmd(t_lex *lex, int op);
int 			sh_lex_seek_ssh(t_lex *lex, int op);
int 			sh_lex_seek_p(t_lex *lex, int op);
int 			sh_lex_seek_cb(t_lex *lex, int op);

int				sh_lex_seek_brace(t_lex *lex, int op);

int				sh_lex_seek_hd(t_lex *lex, int op);
int				sh_lex_seek_hdk(t_lex *lex, int op);
int				sh_lex_seek_hdv(t_lex *lex, int op);
char 			*sh_lex_seek_hd_getval(t_lex *lex, char *hd_key, ssize_t off);

int				sh_lex_seek_als(t_lex *lex, int op);
int				sh_lex_seek_add(t_lex *lex, int op);

int				sh_lex_seek_rw(t_token *token, int ctx);

int 			sh_lex_skip(char *input, t_sh_lex_seeker lex_seeker, int *len);

int 			sh_lex_tok_ctx(t_token *token);
int 			sh_lex_ctx_last(t_lex *lex, int op);

int 			sh_lex_tok_isdelim(char c);
t_token 		*sh_lex_tok_last(t_lex *lex);
int 			sh_lex_isinname(char c);

t_token			*sh_lex_tokdup(t_token *);

int             sh_lex_class_name(t_lex *lex, int op);

int				sh_lex_print(t_lex *lex);

#endif
