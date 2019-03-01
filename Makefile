# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abbesbes <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/27 14:30:39 by abbesbes          #+#    #+#              #
#    Updated: 2019/02/28 13:47:33 by abbesbes         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

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
C_END = \033[0m

LOGGER :=

LEXER :=

SRC_FILES := $(addprefix logger/,  $(LOGGER)) \

SRC_DIR := ./src/
SRC := $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ := $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	@$(CC) $(CC_FLAGS) $(OBJ) $(LIBFT) -ltermcap  -o $(NAME)
	@echo "$(C_GRN)--> [$(NAME)] The program $(C_BLU)$(NAME)$(C_GRN)\
	 has been Compiled Successfully !$(C_END)"

$(OBJ): %.o: %.c  $(LIBFT)
	@$(CC) $(CC_FLAGS) -c $< -o $@ $(addprefix -I , $(INC_DIR))

$(LIBFT):
	@make -C $(LIBFT_DIR)
	@echo "$(C_YLW)=================================================\
	===================$(C_END)"

clean:
	@rm -f $(OBJ)
	@make clean -C $(LIBFT_DIR)
	@echo "$(C_GRN)--> [$(NAME)] Objects have been cleaned\
	 Successfully !$(C_END)"

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT_DIR)
	@echo "$(C_GRN)--> [$(NAME)] The Executable has been deleted\
	 Successfully !$(C_END)"

re: fclean all
	@echo "$(C_GRN)--> [$(NAME)] The Program has been re-builded\
	 Successfully !$(C_END)"

norm:
	@norminette -R CheckForbiddenSourceHeader $(SRC) $(INC)
	@make norm -C $(LIBFT_DIR)

.PHONY: all, re, clean, fclean, norm
