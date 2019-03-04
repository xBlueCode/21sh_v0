/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_lex.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 16:53:18 by abbesbes          #+#    #+#             */
/*   Updated: 2019/03/04 20:32:15 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LEX_H
# define FT_LEX_H

# define XTK_START_GL		"><=!&|"
# define XTK_START_ENAO		"><=!&|"
# define XTK_START_ARITH	"+-*%/"
# define XTK_START_PONCT	"\\$;\n"
# define XTK_START_CLOSURE	"([{)]}"
# define XTK_START_QUOTE	"\"\'`"

# define XTK_ISWS(ch)		(ch == ' ' || ch == '\t')

typedef enum		e_token_state
{
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
}					t_token_state;

typedef struct		s_token
{
	int		ts;
	char	*xme;
}					t_token;

t_list	*x_tokenize(char *in);
int		xtk_recognize(char *in, int off, t_list	**tklist);
int		xtk_add(t_list **tklist, int ts, char *xme);

int		xtk_start_arith(char *in, int off, t_list **tklist);
int		xtk_start_closure(char *in, int off, t_list **tklist);
int		xtk_start_enao(char *in, int off, t_list **tklist);
int		xtk_start_gl(char *in, int off, t_list **tklist);
int		xtk_start_g(char *in, int off, t_list **tklist);
int		xtk_start_l(char *in, int off, t_list **tklist);
int		xtk_start_ponct(char *in, int off, t_list **tklist);
int		xtk_start_esc(char *in, int off, t_list **tklist);

int		xtk_start_quote(char *in, int off, t_list **tklist);
int		xtk_start_squote(char *in, int off, t_list **tklist);
int		xtk_start_dquote(char *in, int off, t_list **tklist);

#endif
