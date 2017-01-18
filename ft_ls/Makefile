# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apoisson <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/03 11:29:15 by apoisson          #+#    #+#              #
#    Updated: 2016/12/26 08:18:15 by apoisson         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls
FLAGS = -Wall -Wextra -Werror
LSSRC = ft*.c

all: $(NAME)

$(NAME): libft.a $(LSSRC)
	@printf "\033[0;36m> Compiling ft_ls\033[0m"
	@gcc $(FLAGS) -I includes/ -L. -lft $(LSSRC) -o $(NAME)
	@printf "\033[0;32m OK\n\033[0m"

libft.a:
	@make -C libft/
	@mv libft/libft.a .
	@make clean -C libft/

test: $(NAME)
	@printf "\033[0;31m- Executing ft_ls -\n\033[0m"
	@./ft_ls
	@printf "\033[0;31m-- End of ft_ls --\n\033[0m"

clean:
	@rm -f libft.a

fclean: clean
	@rm -f $(NAME)

re: fclean all
