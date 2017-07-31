# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apoisson <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/03 11:29:15 by apoisson          #+#    #+#              #
#    Updated: 2017/07/31 07:37:19 by apoisson         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ASM = asm
VM = corewar
FLAGS = -Wall -Wextra -g
SRCASM = add.c automaton.c check.c get_instruction.c asm.c \
parse_header.c tools.c write_champ.c write_header.c \
ftasm_free.c
SRCVM = champ_infos.c op_2.c set_env.c corewar.c op_3.c tools_cor.c\
end_prog.c op_4.c tools_cor_2.c ftncu_main.c player_infos.c tools_op_cor.c\
ftncu_print_info.c proc_fun.c op_1.c proc_fun_2.c
SRCBUILDER = builder.c asm/write_header.c
SRCDECOMPILO = decompilo.c decomp_2.c corewar/champ_infos.c corewar/tools_cor_2.c

all: $(ASM)

$(ASM): libft.a $(addprefix srcs/asm/, $(SRCASM))
	@printf "\033[0;36m> Compiling asm\033[0m"
	@gcc $(FLAGS) $(addprefix srcs/asm/, $(SRCASM)) -L. -lft -I includes/ -o $(ASM)
	@printf "\033[0;32m OK\n\033[0m"

$(VM): libft.a $(addprefix srcs/corewar/, $(SRCVM))
	@printf "\033[0;36m> Compiling corewar\033[0m"
	@gcc $(FLAGS) $(addprefix srcs/corewar/, $(SRCVM)) -L. -lft -lncurses -I includes/ -o $(VM)
	@printf "\033[0;32m OK\n\033[0m"

builder: libft.a $(addprefix srcs/, $(SRCBUILDER))
	@printf "\033[0;36m> Compiling builder\033[0m"
	@gcc $(FLAGS) $^ -L. -lft -I includes/ -o builder
	@printf "\033[0;32m OK\n\033[0m"

decompilo: libft.a $(addprefix srcs/, $(SRCDECOMPILO))
	@printf "\033[0;36m> Compiling decompilo\033[0m"
	@gcc $(FLAGS) $^ -L. -lft -I includes/ -o decompilo
	@printf "\033[0;32m OK\n\033[0m"

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
