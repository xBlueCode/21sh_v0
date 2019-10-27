# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/31 18:49:49 by abbesbes          #+#    #+#              #
#    Updated: 2019/04/11 10:51:04 by abbesbes         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a

CC = gcc
#FLAGS = -W -Wall -Werror -Wextra -fsanitize="address" -g
FLAGS = #-W -Wall -Werror -Wextra
INC = ./includes/

T_BLK = \033[5m
T_NRM = \033[25m
T_CLR = \033[K
C_YLW = \033[33m
C_GRN = \033[32m
C_LYLW = \033[93m
C_LGRN = \033[92m
C_LMGN = \033[95m
C_END = \033[0m

ARR := ft_arr_foreachij.c ft_arr_free.c ft_arr_new.c ft_arr_print.c \
	ft_arr_strdup.c ft_arr_iter.c

CHAR := ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isblank.c ft_iscntrl.c \
	ft_isdigit.c ft_islower.c ft_isprint.c ft_isspace.c ft_isupper.c \
	ft_tolower.c ft_toupper.c ft_wchar_len.c

CONV := ft_atoi.c ft_itoa.c ft_itoa_base.c

GNL := get_next_line.c

LST := ft_lst_addlast.c ft_lst_free.c ft_lst_getby_content.c \
	ft_lst_getby_csize.c ft_lst_getby_i.c ft_lst_putone.c \
	ft_lst_putone_nl.c ft_lstadd.c ft_lstappend.c ft_lstdel.c ft_lstdelone.c \
	ft_lstiter.c ft_lstiter_option.c ft_lstlen.c ft_lstmap.c  ft_lstnew.c

MATH := ft_pgcd.c ft_sqrt.c ft_swap.c ft_pow.c

MEM := ft_bzero.c ft_memalloc.c ft_memccpy.c ft_memchr.c ft_memcmp.c \
	ft_memcpy.c ft_memdel.c ft_memmove.c ft_memset.c

PRINT := ft_putchar.c ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c \
	ft_putnbr.c ft_putnbr_fd.c ft_putstr.c ft_putstr_fd.c ft_putnstr_fd.c\
	ft_putuint_base_fd.c ft_putwchar.c ft_putwchar_fd.c ft_putwstr_fd.c \
	ft_putnwstr_fd.c

PRINTF := ft_printf.c pf_badconv.c pf_c.c pf_double.c pf_init.c \
	pf_int.c pf_oxu.c pf_p.c pf_percent.c pf_s.c processing.c \
	token.c utils.c

STR := ft_count_sep_words.c ft_strcat.c ft_strchr.c ft_strclr.c \
	ft_strcmp.c ft_strcontains.c ft_strcontains_all.c ft_strcpy.c \
	ft_strdel.c ft_strdup.c ft_strequ.c ft_striter.c ft_striteri.c \
	ft_strjoin.c ft_strlcat.c ft_strlen.c ft_strlenz.c ft_strmap.c \
	ft_strmapi.c ft_strncat.c ft_strncmp.c ft_strncpy.c ft_strndup.c \
	ft_strndup_i.c ft_strnequ.c ft_strnew.c ft_strnstr.c ft_strrchr.c \
	ft_strrev.c ft_strsplit.c ft_strstr.c ft_strsub.c ft_strtrim.c \
	ft_wstrlenz.c \
	ft_strconnect.c

DSTR := ft_dstr_basic.c ft_dstr_del.c ft_dstr_extend.c ft_dstr_insert.c \
	ft_dstr_get.c ft_dstr_join.c

DASTR := ft_dastr_basic.c ft_dastr_extend.c ft_dastr_get.c ft_dastr_insert.c \
	ft_dastr_replace.c ft_dastr_del.c ft_dastr_print.c

TABLE := ft_tab_del.c ft_tab_get.c ft_tab_insert.c ft_tab_basic.c ft_tab_put.c \
	ft_tab_to.c ft_tab_iter.c

LOGGER := ft_logger.c ft_logger_update.c

CELL := ft_cell.c

HASH := ft_hcode_str.c

HSET := ft_hset_basics.c ft_hset_manip.c

HTAB := ft_htab_basics.c ft_htab_manip.c ft_htab_hash_str.c

BTREE := ft_btree_basics.c ft_btree_manip.c ft_btree_traverse.c \
    ft_btree_app.c

VECTOR := ft_vec_basics.c ft_vec_insert.c ft_vec_delete.c

DIRENT := ft_dirent.c

FIO := ft_dup.c ft_stat.c ft_read.c ft_dir.c

FILES := $(addprefix arr/,  $(ARR)) \
	$(addprefix char/, $(CHAR)) \
	$(addprefix conv/, $(CONV)) \
	$(addprefix gnl/, $(GNL)) \
	$(addprefix lst/, $(LST)) \
	$(addprefix math/, $(MATH)) \
	$(addprefix mem/, $(MEM)) \
	$(addprefix print/, $(PRINT)) \
	$(addprefix printf/, $(PRINTF)) \
	$(addprefix str/, $(STR)) \
	$(addprefix dstr/, $(DSTR)) \
	$(addprefix dastr/, $(DASTR)) \
	$(addprefix table/, $(TABLE)) \
	$(addprefix logger/, $(LOGGER)) \
	$(addprefix cell/, $(CELL)) \
	$(addprefix hash/, $(HASH)) \
	$(addprefix hset/, $(HSET)) \
	$(addprefix htab/, $(HTAB)) \
	$(addprefix btree/, $(BTREE)) \
	$(addprefix vector/, $(VECTOR)) \
	$(addprefix dirent/, $(DIRENT)) \
	$(addprefix fio/, $(FIO))

SRC := $(addprefix src/, $(FILES))
OBJ := $(SRC:.c=.o)

NB = $(words $(FILES))
IND = 0
PER = 0

all: $(NAME)

$(OBJ): %.o: %.c
	@$(CC) $(FLAGS) -c $< -o $@ -I $(INC)
	@$(eval IND=$(shell echo $$(($(IND) + 1))))
	@$(eval PER=$(shell echo $$((($(IND) * 100) / $(NB)))))
	@printf "$(T_CLR)$(C_LYLW)➜ ➜ progress: %3d %% $(C_END)\n\033[1A$(C_END)" $(PER);

$(NAME):
	@echo "$(C_LYLW)➜ [$(NAME)] Compiling objects ... $(C_END)"
	@make $(OBJ)
	@echo "\033[1A$(T_CLR)$(C_LGRN)➜ [$(NAME)] Objects have been compiled successfully ! $(C_END)"
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)	
	@echo "$(C_LGRN)➜ [$(NAME)] Library has been Compiled Successfully !$(C_END)"

clean:
	@rm -f $(OBJ)
	@echo "$(C_LMGN)➜ [$(NAME)] Objects have been cleaned Successfully !$(C_END)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(C_LMGN)➜ [$(NAME)] Library has been deleted Successfully !$(C_END)"

re: fclean all	
	@echo "$(C_LGRN)➜ [$(NAME)] Library has been re-builded\
	 Successfully !$(C_END)"

norm:
	@norminette -R CheckForbiddenSourceHeader $(SRC) $(INC)

.PHONY: clean fclean re
