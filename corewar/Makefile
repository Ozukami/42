# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apoisson <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/03 11:29:15 by apoisson          #+#    #+#              #
#    Updated: 2017/07/27 02:05:00 by lcharbon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ASM = asm
VM = corewar
FLAGS = -Wall -Wextra -g
SRCASM = add.c automaton.c check.c get_instruction.c asm.c \
parse_header.c tools.c write_champ.c write_header.c
SRCVM = corewar.c ftncu_main.c ftncu_print_info.c
CHAMPDIR =

all: $(ASM)

$(ASM): libft.a $(addprefix srcs/, $(SRCASM))
	@printf "\033[0;36m> Compiling asm\033[0m"
	@gcc $(FLAGS) $(addprefix srcs/, $(SRCASM)) -L. -lft -I includes/ -o $(ASM)
	@printf "\033[0;32m OK\n\033[0m"

$(VM): libft.a $(addprefix srcs/, $(SRCVM))
	@printf "\033[0;36m> Compiling corewar\033[0m"
	@gcc $(FLAGS) $(addprefix srcs/, $(SRCVM)) -L. -lft -lncurses -I includes/ -o $(VM)
	@printf "\033[0;32m OK\n\033[0m"

champ_builder: champ_builder.c
	@gcc $(FLAGS) $^ -L. -lft -I includes/ -o champ_builder

libft.a:
	@make -C libft/
	@mv libft/libft.a .
	@make clean -C libft/

run-asm: $(ASM)
ifeq ($(ARGS),)
	./$(ASM) zork.s
else
	./$(ASM) $(ARGS)
endif

run-corewar: $(VM)
ifeq ($(ARGS),)
	./$(VM) zork.cor
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
