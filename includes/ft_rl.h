/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rl.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 19:33:42 by abbesbes          #+#    #+#             */
/*   Updated: 2019/10/07 19:33:44 by abbesbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_RL_H
# define FT_RL_H

# include "libft.h"
# include "rl_hist.h"

# include <curses.h>
# include <term.h>

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
	RL_SCP_HD,
	RL_SCP_PIPE,
	RL_SCP_AND,
	RL_SCP_OR,
	RL_SCP_SUBSH,
	RL_SCP_CURSH,
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
	t_dastr		*hd;
	int			plen;
	int			mode;
}				t_rl;

typedef enum	e_rl_context
{
	RL_CXT_BIN = 1,
	RL_CXT_VAR,
	RL_CXT_GLOB
}				t_rl_context;

t_rl			rl_get(void);

char			*rl_start(void);
void			rl_init(void);
void			rl_free(void);
void			rl_reset(t_dastr *ent);
void			rl_read(void);
void			xrl_read(void);

int				rl_ctrl_perform(int c);
int				rl_vim_perform(int c);
int				rl_mode_toggle(int c);
int				rl_insert_ch(int c);
int				rl_ctrl_del_ch(int c);

int				rl_ctrl_move_up(int c);
int				rl_ctrl_move_do(int c);
int				rl_ctrl_move_ri(int c);
int				rl_ctrl_move_le(int c);

int				rl_ctrl_jump_beg(int c);
int				rl_ctrl_jump_end(int c);
int				rl_ctrl_jump_w_next_end(int c);
int				rl_ctrl_jump_w_next_beg(int c);
int				rl_ctrl_jump_w_prev_beg(int c);

int				rl_ctrl_kill_before(int c);
int				rl_ctrl_kill_after(int c);
int				rl_ctrl_kill_w_before(int c);
int				rl_ctrl_kill_w_after(int c);
int				rl_ctrl_kill_w(int c);
int				rl_ctrl_kill_wf(int c);

int				rl_ctrl_save_before(int c);
int				rl_ctrl_save_after(int c);
int				rl_ctrl_save_w_before(int c);
int				rl_ctrl_save_w_after(int c);

int				rl_ctrl_reg_d(int c);
int				rl_ctrl_reg_da(int c);

int				rl_ctrl_xp_after(int c);
int				rl_ctrl_xo_before(int c);
int				rl_ctrl_x_lend(int c);
int				rl_ctrl_x_lbeg(int c);

int				rl_ctrl_sig_d(int c);

int				rl_scope_update(void);
int				rl_scope_prompt(char *str);
int				rl_scope_prompt_ps(void);
int				rl_scope_prompt_ps_u(t_dstr *prompt, int ps1i);
int				rl_scope_prompt_ps_h(t_dstr *prompt, int i);
int				rl_scope_prompt_ps_w(t_dstr *prompt, int i);

int				rl_scope_scan(void);
int				rl_scope_scan_start(void);
int				rl_scope_scan_none(char *line, ssize_t *pos);
int				rl_scope_scan_escape(char *line, ssize_t *pos);
int				rl_scope_scan_join(char *line, ssize_t *pos);
int				rl_scope_scan_pipe(char *line, ssize_t *pos);
int				rl_scope_scan_and(char *line, ssize_t *pos);
int				rl_scope_scan_or(char *line, ssize_t *pos);

int				rl_scope_scan_sq(char *line, ssize_t *pos);
int				rl_scope_scan_dq(char *line, ssize_t *pos);
int				rl_scope_scan_bq(char *line, ssize_t *pos);
int				rl_scope_scan_smath(char *line, ssize_t *pos);
int				rl_scope_scan_scmd(char *line, ssize_t *pos);
int				rl_scope_scan_param(char *line, ssize_t *pos);
int				rl_scope_scan_ssh(char *line, ssize_t *pos);
int				rl_scope_scan_hd(char *line, ssize_t *pos);

int				rl_autoc(int c);
int				rl_autoc_cxt_get(const char *line, ssize_t pos);
int				rl_autoc_isdelim(int c);
int				rl_autoc_cxt_isbin(int c);
int				rl_autoc_get_cw(char *line, ssize_t pos, ssize_t *ilen);

t_dastr			*rl_autoc_match(char *w, int cxt);
t_dastr			*rl_autoc_match_glob(char *w);
t_dastr			*rl_autoc_match_var(char *w);
t_dastr			*rl_autoc_match_bin(char *w);

char			*rl_autoc_menu(t_dastr *res);
int				rl_autoc_menu_clear(t_dstr **list, int nl);
char			*rl_autoc_menu_select(t_dastr *res);
int				rl_autoc_menu_putlist(t_dstr **list);
int				rl_autoc_menu_move(t_dstr **list, int *curl, int action);

char			*rl_autoc_xmenu(t_dastr *res);
int				rl_autoc_xmenu_clear(int i);
char			*rl_autoc_xmenu_select(t_dastr *res);
int				rl_autoc_xmenu_putlist(t_dstr **list, int curl);
int				rl_autoc_xmenu_move_do(t_dstr **list, int *curl, int nl);
int				rl_autoc_xmenu_move_up(t_dstr **list, int *curl, int nl);

int				rl_cur_fromto(int from, int to);
int				rl_cur_move(int from, int to, int plen);

int				rl_putstr_wrap(char *str, ssize_t cc);
int				rl_putnchar_wrap(char c, int n, ssize_t cc);
int				rl_putstr_wrapx(char *str, ssize_t cc, int plen);
int				rl_putstr_nowrapx(char *str, ssize_t cc, int plen);
int				rl_putnchar_wrapx(char c, int n, ssize_t cc, int plen);

int				rl_get_header(void);

int				rl_tputsn(char *param, int n);

int				rl_ter_putchar(int ch);
int				rl_update_win(void);
void			rl_sighand_parent(int sn);
void			rl_sighand_child(int sn);
void			rl_sigint(void);

typedef int		t_rl_scp(char *line, ssize_t *pos);
typedef int		t_rl_ctrl(int c);

static t_rl_scp	*g_rl_scope_scanner[] =
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
	&rl_scope_scan_scmd,
	&rl_scope_scan_hd,
	&rl_scope_scan_pipe,
	&rl_scope_scan_and,
	&rl_scope_scan_or,
	&rl_scope_scan_ssh,
};

static char		*g_rl_scope_prompt[] =
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
	"cmdsubst",
	"heredoc",
	"pipe",
	"cmdand",
	"cmdor",
	"subsh",
	"cursh",
	NULL
};

static int		g_rl_ctrl_keymap[] =
{
	KCA,
	KCB,
	KCD,
	KCE,
	KCF,
	KCW,
	'\t',
	KESC,
	KBSPC,
	KUP,
	KDOWN,
	KRIGHT,
	KLEFT,
	0
};

static int		g_rl_vim_keymap[] =
{
	'0',
	'$',
	'b',
	'f',
	'i',
	'w',
	'h',
	'n',
	('d' << 8) | ']',
	('d' << 8) | '[',
	('d' << 8) | ')',
	('d' << 8) | '(',
	('d' << 8) | 'b',
	('d' << 8) | 'f',
	('d' << 8) | 'w',
	('x' << 8) | 'p',
	('x' << 8) | 'o',
	('x' << 8) | '0',
	('x' << 8) | '$',
	('s' << 8) | ']',
	('s' << 8) | '[',
	('s' << 8) | ')',
	('s' << 8) | '(',
	('s' << 8) | 'd',
	('s' << 8) | 'D',
	0
};

static t_rl_ctrl	*g_rl_ctrl_action[] =
{
	&rl_ctrl_jump_beg,
	&rl_ctrl_jump_w_prev_beg,
	&rl_ctrl_sig_d,
	&rl_ctrl_jump_end,
	&rl_ctrl_jump_w_next_end,
	&rl_ctrl_jump_w_next_beg,
	&rl_autoc,
	&rl_mode_toggle,
	&rl_ctrl_del_ch,
	&rl_ctrl_move_up,
	&rl_ctrl_move_do,
	&rl_ctrl_move_ri,
	&rl_ctrl_move_le,
	NULL
};

static t_rl_ctrl	*g_rl_vim_action[] =
{
	&rl_ctrl_jump_beg,
	&rl_ctrl_jump_end,
	&rl_ctrl_jump_w_prev_beg,
	&rl_ctrl_jump_w_next_end,
	&rl_mode_toggle,
	&rl_ctrl_jump_w_next_beg,
	&rl_hist_req_up,
	&rl_hist_req_do,
	&rl_ctrl_kill_before,
	&rl_ctrl_kill_after,
	&rl_ctrl_kill_w_before,
	&rl_ctrl_kill_w_after,
	NULL,
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
