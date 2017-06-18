# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apoisson <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/03 11:29:15 by apoisson          #+#    #+#              #
#    Updated: 2017/05/29 04:44:33 by qumaujea         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ASM = asm
VM = corewar
NC = ncurses
FLAGS = -Wall -Wextra
SRCASM = add.c automaton.c check.c get_instruction.c main.c \
parse_header.c tools.c write_champ.c write_header.c
SRCVM = 
SRCNC = test_ncurses.c
CHAMPDIR =

all: $(ASM)

$(ASM): libft.a $(addprefix srcs/, $(SRCASM))
	@printf "\033[0;36m> Compiling asm\033[0m"
	@gcc $(FLAGS) $(addprefix srcs/, $(SRCASM)) -L. -lft -I includes/ -o $(ASM)
	@printf "\033[0;32m OK\n\033[0m"

$(VM): libft.a $(addprefix srcs/, $(SRCVM))
	@printf "\033[0;36m> Compiling corewar\033[0m"
	@gcc $(FLAGS) $(addprefix srcs/, $(SRCVM)) -L. -lft -I includes/ -o $(VM)
	@printf "\033[0;32m OK\n\033[0m"

$(NC): libft.a $(addprefix srcs/, $(SRCNC))
	@printf "\033[0;36m> Compiling ncurses testing program\033[0m"
	@gcc $(FLAGS) $(addprefix srcs/, $(SRCNC)) -L. -lft -lncurses -I includes/ -o $(NC)
	@printf "\033[0;32m OK\n\033[0m"

libft.a:
	@make -C libft/
	@mv libft/libft.a .
	@make clean -C libft/

run-asm: $(ASM)
ifeq ($(ARGS),)
	./$(ASM) test_champ.s
else
	./$(ASM) $(ARGS)
endif

run-corewar: $(VM)
ifeq ($(ARGS),)
	./$(VM) test_champ.s
else
	./$(VM) $(ARGS)
endif

clean:
	@rm -f libft.a

clean-cor:
	@rm -f *.cor

fclean: clean
	@rm -f $(ASM)

re: fclean all
