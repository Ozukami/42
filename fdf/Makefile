# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apoisson <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/03 11:29:15 by apoisson          #+#    #+#              #
#    Updated: 2017/04/12 05:35:59 by apoisson         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
FLAGS = -Wall -Wextra -Werror
SRC = ft_init.c ft_draw.c main.c free_map.c
#SRC = fdf.c free_map.c

all: $(NAME)

$(NAME): libft.a $(addprefix srcs/, $(SRC))
	@printf "\033[0;36m> Compiling filler\033[0m"
	@gcc $(FLAGS) -g -I includes/ -L. -lft $(addprefix srcs/, $(SRC)) -o $(NAME) -lmlx -framework OpenGL -framework AppKit
	@printf "\033[0;32m OK\n\033[0m"

libft.a:
	@make -C libft/
	@mv libft/libft.a .
	@make clean -C libft/

test: $(NAME)
	@printf "\033[0;31m- Executing $(NAME) -\n\033[0m"
	@./$(NAME) $(ARGS)
	@printf "\033[0;31m-- End of $(NAME) --\n\033[0m"

clean:
	@rm -f libft.a

fclean: clean
	@rm -f $(NAME)

re: fclean all
