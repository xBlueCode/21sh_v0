NAME = 21sh

TEST_LOG = test_log

LIBFT_DIR = ./libft/
LIBFT := $(addprefix $(LIBFT_DIR), libft.a)
INC_DIR = $(LIBFT_DIR)includes/ ./includes/

CC = gcc
CC_FLAGS = -W -Wall -Werror -Wextra

T_BLK = \033[5m
T_NRM = \033[25m
C_GRN = \033[32m
C_YLW = \033[33m
C_BLU = \033[34m
C_LGRN = \033[92m
C_LYLW = \033[93m
C_LBLU = \033[54m
C_LMGN = \033[95m
C_END = \033[0m

FTSH := ftsh.c

ALIAS := sh_als.c

VAR := sh_var.c sh_var_utils.c sh_var_get.c

BIN := sh_bin.c sh_bin_manip.c

TERM := term_config.c

PROMPT := prompt.c

READLINE := rl.c rl_scope.c  rl_scope_scan.c \
	rl_scope_scan_q.c rl_scope_scan_s.c rl_scope_scan_h.c \
	rl_scope_scan_op.c rl_scope_scan_ssh.c \
	rl_scope_prompt.c rl_scope_prompt_ps.c \
	rl_ctrl.c rl_ctrl_move.c rl_ctrl_jump.c rl_ctrl_kill.c rl_ctrl_kill_w.c\
	rl_ctrl_save.c rl_ctrl_paste.c rl_ctrl_reg.c\
	rl_edit.c rl_edit_utils.c\
	rl_utils.c \
	rl_cur.c \
	rl_put.c \
	rl_autoc.c rl_autoc_utils.c rl_autoc_match.c \
	rl_autoc_menu.c rl_autoc_xmenu.c rl_autoc_xmenu_move.c \
	rl_hist.c rl_hist_io.c rl_hist_request.c

GLOB := sh_glob.c sh_glob_match.c

LEX := sh_lex.c sh_lex_tok.c sh_lex_manip.c sh_lex_print.c \
	sh_lex_seek.c sh_lex_seek_start.c sh_lex_seek_bs.c sh_lex_seek_q.c \
	sh_lex_seek_op.c sh_lex_seek_s.c sh_lex_seek_hd.c \
	sh_lex_seek_op_gl.c sh_lex_seek_ion.c sh_lex_seek_ssh.c \
	sh_lex_seek_add.c

UTILS := utils_str.c

SRC_FILES := $(addprefix ftsh/,  $(FTSH)) \
	$(addprefix lex/,  $(LEX)) \
	$(addprefix alias/,  $(ALIAS)) \
	$(addprefix var/,  $(VAR)) \
	$(addprefix bin/,  $(BIN)) \
	$(addprefix term/,  $(TERM)) \
	$(addprefix prompt/,  $(PROMPT)) \
	$(addprefix readline/,  $(READLINE)) \
	$(addprefix utils/,  $(UTILS)) \
	$(addprefix glob/,  $(GLOB)) \

SRC_DIR := ./src/
SRC := $(addprefix $(SRC_DIR), $(SRC_FILES))

NB = $(words $(SRC_FILES))
IND = 0
PER = 0

OBJ := $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT)
	@echo "$(C_LYLW)➜ [$(NAME)] Compiling objects ...$(C_END)"
	@make $(OBJ)
	@echo "\033[1A$(T_CLR)$(C_LGRN)➜ [$(NAME)] Objects have been compiled successfully ! $(C_END)"
	@$(CC) $(CC_FLAGS) $(OBJ) $(LIBFT) -ltermcap -o $(NAME)
	@echo "$(C_LGRN)➜ [$(NAME)] The program $(C_LBLU)$(NAME)$(C_LGRN)\
	 has been Compiled Successfully !$(C_END)"

$(OBJ): %.o: %.c  $(LIBFT)
	@$(CC) $(CC_FLAGS) -c $< -o $@ $(addprefix -I , $(INC_DIR))
	@$(eval IND=$(shell echo $$(($(IND) + 1))))
	@$(eval PER=$(shell echo $$((($(IND) * 100) / $(NB)))))
	@printf "$(T_CLR)$(C_LYLW)➜ ➜ progress: %3d %% $(C_END)\n\033[1A$(C_END)" $(PER);

$(LIBFT):
	@make -C $(LIBFT_DIR)
	@echo "$(C_LYLW)=================================================\
	===================$(C_END)"

clean:
	@rm -f $(OBJ)
	@make clean -C $(LIBFT_DIR)
	@echo "$(C_LMGN)➜ [$(NAME)] Objects have been cleaned\
	 Successfully !$(C_END)"

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT_DIR)
	@echo "$(C_LMGN)➜ [$(NAME)] The Executable has been deleted\
	 Successfully !$(C_END)"

re: fclean all
	@echo "$(C_LGRN)➜ [$(NAME)] The Program has been re-builded\
	 Successfully !$(C_END)"

norm:
	@norminette -R CheckForbiddenSourceHeader $(SRC) $(INC)
	@make norm -C $(LIBFT_DIR)

quick: clean
	@rm $(NAME) & make $(NAME)
	@echo "READY !!!"

.PHONY: all, re, clean, fclean, norm
