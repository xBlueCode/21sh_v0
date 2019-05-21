#ifndef FT_RL_H
# define FT_RL_H

# include "libft.h"
#include "ftsh.h"
#include "rl_hist.h"

# define RL_SCP_SIZE 1

# define RL_MODE_INS 1
# define RL_MODE_VIM 2

# define RL_TPUTS(str) tputs(tgetstr(str, NULL), 1, rl_ter_putchar);
# define RL_TPUTS_GO(str, x, y) tputs(tgoto(tgetstr(str, NULL), x, y), 1, rl_ter_putchar)

# define RL_PUTSTR_STY(style, inst) {ft_putstr(style); inst; ft_putstr(T_END);}

typedef enum	e_rl_scope
{
	RL_SCP_NONE = 0,
	RL_SCP_START,
	RL_SCP_ESC,
	RL_SCP_JOIN,
	RL_SCP_SQ,
	RL_SCP_DQ,
	RL_SCP_BQ,
	RL_SCP_PARAM,
	RL_SCP_SMATH,
	RL_SCP_SCMD,
	RL_SCP_SSH,
	RL_SCP_MATH
}				t_rl_scope;

typedef	struct	s_rl
{
	t_dastr		*txt;
	t_dastr		*reg;
	ssize_t		regi;
	ssize_t		cl;
	ssize_t		cc;
	int			wc;
	int			wl;
	t_dstr		*scope;
	//int			ctx;
	int			plen;
	int			mode;
}				t_rl;

typedef enum	e_rl_context
{
	RL_CXT_BIN = 1,
	RL_CXT_VAR, // 2
	RL_CXT_GLOB // 3
}				t_rl_context;

t_rl		rl_get(void);

char		*rl_start(void);
void		rl_init(void);
void		rl_reset(t_dastr *ent);
void		rl_read(void);

int			rl_ctrl_perform(int c);
int			rl_vim_perform(int c);
int			rl_mode_toggle(int c);
int			rl_insert_ch(int c);
int			rl_ctrl_del_ch(int c);

int			rl_ctrl_move_up(int c);
int			rl_ctrl_move_do(int c);
int			rl_ctrl_move_ri(int c);
int			rl_ctrl_move_le(int c);

int			rl_ctrl_jump_beg(int c);
int			rl_ctrl_jump_end(int c);
int			rl_ctrl_jump_w_next_end(int c);
int			rl_ctrl_jump_w_next_beg(int c);
int			rl_ctrl_jump_w_prev_beg(int c);

int			rl_ctrl_kill_before(int c);
int			rl_ctrl_kill_after(int c);
int			rl_ctrl_kill_w_before(int c);
int			rl_ctrl_kill_w_after(int c);
int			rl_ctrl_kill_w(int c);
int			rl_ctrl_kill_wf(int c);

int			rl_ctrl_save_before(int c);
int			rl_ctrl_save_after(int c);
int			rl_ctrl_save_w_before(int c);
int			rl_ctrl_save_w_after(int c);

int			rl_ctrl_reg_d(int c);
int			rl_ctrl_reg_da(int c);

int			rl_ctrl_xp_after(int c);
int			rl_ctrl_xo_before(int c);
int			rl_ctrl_x_lend(int c);
int			rl_ctrl_x_lbeg(int c);

int			rl_scope_update(void);
int			rl_scope_prompt(char *str);

int			rl_scope_scan(void);
int			rl_scope_scan_none(char *line, ssize_t *pos);
int			rl_scope_scan_escape(char *line, ssize_t *pos);
int			rl_scope_scan_join(char *line, ssize_t *pos);
int			rl_scope_scan_sq(char *line, ssize_t *pos);
int			rl_scope_scan_dq(char *line, ssize_t *pos);
int			rl_scope_scan_bq(char *line, ssize_t *pos);
int			rl_scope_scan_smath(char *line, ssize_t *pos);
int			rl_scope_scan_scmd(char *line, ssize_t *pos);
int			rl_scope_scan_param(char *line, ssize_t *pos);

int			rl_autoc(int c);
int			rl_autoc_cxt_get(const char *line, ssize_t pos);
int			rl_autoc_isdelim(int c);
int			rl_autoc_cxt_isbin(int c);
int			rl_autoc_get_cw(char *line, ssize_t pos, ssize_t *ilen);

t_dastr		*rl_autoc_match(char *w, int cxt);
t_dastr		*rl_autoc_match_glob(char *w);
t_dastr		*rl_autoc_match_var(char *w);

char		*rl_autoc_menu(t_dastr *res);
int			rl_autoc_menu_clear(t_dstr **list, int nl);
char		*rl_autoc_menu_select(t_dastr *res);
int			rl_autoc_menu_putlist(t_dstr **list);
int			rl_autoc_menu_move(t_dstr **list, int *curl, int action);

char		*rl_autoc_xmenu(t_dastr *res);
int			rl_autoc_xmenu_clear(int i);
char		*rl_autoc_xmenu_select(t_dastr *res);
int			rl_autoc_xmenu_putlist(t_dstr **list, int curl);
int			rl_autoc_xmenu_move_do(t_dstr **list, int *curl, int nl);
int			rl_autoc_xmenu_move_up(t_dstr **list, int *curl, int nl);

int			rl_cur_fromto(int from, int to);
int			rl_cur_move(int from, int to, int plen);

int			rl_putstr_wrap(char *str, ssize_t cc);
int			rl_putnchar_wrap(char c, int n, ssize_t cc);
int			rl_putstr_wrapx(char *str, ssize_t cc, int plen);
int			rl_putstr_nowrapx(char *str, ssize_t cc, int plen);
int			rl_putnchar_wrapx(char c, int n, ssize_t cc, int plen);


int			rl_get_header(void);

int			rl_tputsn(char *param, int n);

int			rl_ter_putchar(int ch);
int			rl_update_win(void);

typedef int	t_rl_scope_scanner(char *line, ssize_t *pos);
typedef int	t_rl_ctrl_action(int c);

static t_rl_scope_scanner *g_rl_scope_scanner[] =
{
	&rl_scope_scan_none,
	NULL,
	&rl_scope_scan_escape,
	&rl_scope_scan_join,
	&rl_scope_scan_sq,
	&rl_scope_scan_dq,
	&rl_scope_scan_bq,
	&rl_scope_scan_param,
	&rl_scope_scan_smath,
	&rl_scope_scan_scmd
};

static char *g_rl_scope_prompt[] =
{
	"NONE",
	"START",
	"ESC",
	"JOIN",
	"squote",
	"dquote",
	"bquote",
	"braceparam",
	"mathsubst",
	"cmdsubst"
};

static int	g_rl_ctrl_keymap[] =
{
	KCA,
	KCB,
//	KCC,
//	KCD,
	KCE,
	KCF,
//	KCG,
//	KCH,
//	KCI,
//	KCK,
//	KCL,
//	KCN,
//	KCP,
//	KCR,
//	KCT,
//	KCU,
//	KCV,
	KCW,
//	KCX,
//	KMA,
//	KMB,
//	KMC,
//	KMD,
//	KMF,
	'\t',
	KESC,
//	KSPC,
//	KRET,
	KBSPC,
	KUP,
	KDOWN,
	KRIGHT,
	KLEFT,
//	KDEL,
	0
};


static int	g_rl_vim_keymap[] =
{
	'0',
	'$',
	'b', // 2
	'f',
	'i',
	'w',
	'h',
	'n',
	('d' << 8) | ']', // 6
	('d' << 8) | '[',
	('d' << 8) | ')',
	('d' << 8) | '(',
	('d' << 8) | 'b', // 10
	('d' << 8) | 'f',
	('d' << 8) | 'w',
	('x' << 8) | 'p',
	('x' << 8) | 'o',
	('x' << 8) | '0',
	('x' << 8) | '$',
	('s' << 8) | ']',
	('s' << 8) | '[', // 15
	('s' << 8) | ')',
	('s' << 8) | '(',
	('s' << 8) | 'd',
	('s' << 8) | 'D',
//	('s' << 8) | 'b',
//	('s' << 8) | 'f', // 18
//	('s' << 8) | 'w',
	0
};

static t_rl_ctrl_action *g_rl_ctrl_action[] =
{
	&rl_ctrl_jump_beg,
	&rl_ctrl_jump_w_prev_beg,
	&rl_ctrl_jump_end,
	&rl_ctrl_jump_w_next_end,
	&rl_ctrl_jump_w_next_beg,
	&rl_autoc,
	&rl_mode_toggle,
//	&rl_ctrl_jump_,
//	&rl_ctrl_jump_beg,
	&rl_ctrl_del_ch,
	&rl_ctrl_move_up,
	&rl_ctrl_move_do,
	&rl_ctrl_move_ri,
	&rl_ctrl_move_le,
	NULL
};

static t_rl_ctrl_action *g_rl_vim_action[] =
{
	&rl_ctrl_jump_beg,
	&rl_ctrl_jump_end,
	&rl_ctrl_jump_w_prev_beg,
	&rl_ctrl_jump_w_next_end,
	&rl_mode_toggle,
	&rl_ctrl_jump_w_next_beg,
	&rl_hist_req_up,
	&rl_hist_req_do,
	&rl_ctrl_kill_before, // 06
	&rl_ctrl_kill_after,
	&rl_ctrl_kill_w_before,
	&rl_ctrl_kill_w_after,
	NULL, // 10
	&rl_ctrl_kill_wf,
	&rl_ctrl_kill_w,
	&rl_ctrl_xp_after,
	&rl_ctrl_xo_before,
	&rl_ctrl_x_lbeg,
	&rl_ctrl_x_lend,
	&rl_ctrl_save_before,
	&rl_ctrl_save_after,
	&rl_ctrl_save_w_before,
	&rl_ctrl_save_w_after,
	&rl_ctrl_reg_d,
	&rl_ctrl_reg_da,
	NULL
};

#endif
