# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lcharbon <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/21 11:21:25 by lcharbon          #+#    #+#              #
#    Updated: 2017/07/22 20:44:18 by lcharbon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ncurse

CC = gcc
FLAG = -Wall -Werror -Wextra -g

SRC_P = ./src/
OBJ_P = ./obj/
INC_P = ./include/ ./libft/include/
LIB_P = ./libft/.

SRC_N = main.c ftncu_print_info.c

OBJ_N = $(SRC_N:.c=.o)
LIB_N = -lft

SRC = $(addprefix $(SRC_P),$(SRC_N))
OBJ = $(addprefix $(OBJ_P),$(OBJ_N))
INC = $(addprefix -I,$(INC_P))
LIB = $(addprefix -L,$(LIB_P))

all : lib
	@make $(NAME)

$(NAME) : $(OBJ)
	@$(CC) $(LIB) $(LIB_N) -lncurses $^ -o $@
	@echo
	@echo "\x1b[33mCompilation.... $(NAME) |\x1b[32m| done\x1b[37m"

$(OBJ_P)%.o: $(SRC_P)%.c $(INCLUDE)
	@mkdir -p $(OBJ_P)
	@$(CC) $(FLAG) $(INC) -o $@ -c $<
	@echo "\x1b[33mCompilation.... $@ $< |\x1b[32m| done\x1b[37m"

lib:
	@echo "Make libft"
	@make -C $(LIB_P)

clean:
	@rm -rf $(OBJ) $(OBJ_P)
	@make -C $(LIB_P) clean

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIB_P) fclean

re : fclean all
