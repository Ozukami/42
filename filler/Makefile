# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apoisson <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/03 11:29:15 by apoisson          #+#    #+#              #
#    Updated: 2017/03/14 02:19:10 by apoisson         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = apoisson.filler
FLAGS = -Wall -Wextra -Werror
SRC = *.c

all: $(NAME)

$(NAME): libft.a $(SRC)
	@printf "\033[0;36m> Compiling filler\033[0m"
	@gcc $(FLAGS) -I includes/ -L. -lft $(SRC) -o $(NAME)
	@printf "\033[0;32m OK\n\033[0m"

libft.a:
	@make -C libft/
	@mv libft/libft.a .
	@make clean -C libft/

test: $(NAME)
	@printf "\033[0;31m- Executing filler -\n\033[0m"
	@rm players/filler
	@cp filler players/
	@./filler_vm -f maps/custom_map -p1 players/filler
	@printf "\033[0;31m-- End of filler --\n\033[0m"

test_map: $(NAME)
	@printf "\033[0;31m- Executing filler -\n\033[0m"
	@rm players/apoisson.filler
	@cp apoisson.filler players/
	@./filler_vm -f maps/$(ARGS) -p1 players/apoisson.filler -p2 players/superjeannot.filler
	@printf "\033[0;31m-- End of filler --\n\033[0m"

clean:
	@rm -f libft.a

fclean: clean
	@rm -f $(NAME)

re: fclean all
