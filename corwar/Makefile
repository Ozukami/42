# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apoisson <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/03 11:29:15 by apoisson          #+#    #+#              #
#    Updated: 2017/05/29 04:35:14 by apoisson         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ASM = corewar-asm
FLAGS = -Wall -Wextra
SRCASM = *.c

all: $(ASM)

$(ASM): libft.a $(addprefix srcs/, $(SRCASM))
	@printf "\033[0;36m> Compiling corewar-asm\033[0m"
	@gcc $(FLAGS) -I includes/ -L. -lft $(addprefix srcs/, $(SRCASM)) -o $(ASM)
	@printf "\033[0;32m OK\n\033[0m"

libft.a:
	@make -C libft/
	@mv libft/libft.a .
	@make clean -C libft/

run: $(ASM)
ifeq ($(ARGS),)
	./$(ASM) < fichier
else
	./$(ASM) < $(ARGS)
endif

clean:
	@rm -f libft.a

fclean: clean
	@rm -f $(ASM)

re: fclean all
