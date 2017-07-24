# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apoisson <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/03 11:29:15 by apoisson          #+#    #+#              #
#    Updated: 2017/05/24 04:00:47 by apoisson         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in
VISUAL = Visu.jar
FLAGS = -Wall -Wextra -Werror
SRC = ant.c check.c main.c ppt_pgt.c way.c\
	  bfs.c get_data.c misc.c room.c way_list.c
JAVA = PopUp.java SpriteAnimation.java Env.java Move.java Pipe.java\
		  Room.java Visual.java

all: $(NAME)

$(NAME): libft.a $(addprefix srcs/, $(SRC))
	@printf "\033[0;36m> Compiling lem-in\033[0m"
	@gcc $(FLAGS) -I includes/ -L. -lft $(addprefix srcs/, $(SRC)) -o $(NAME)
	@printf "\033[0;32m OK\n\033[0m"

libft.a:
	@make -C libft/
	@mv libft/libft.a .
	@make clean -C libft/

$(VISUAL):
	@printf "\033[0;36m> Compiling Visual\033[0m"
	@javac -d . $(addprefix Visual/src/, $(JAVA))
	@jar cmf META-INF/MANIFEST.MF Visu.jar *.class
	@rm *.class
	@printf "\033[0;32m OK\n\033[0m"

run: $(VISUAL)
	./lem-in < $(ARGS) | java -jar Visu.jar

clean:
	@rm -f libft.a

fclean: clean
	@rm -f $(NAME)
	@rm -f $(VISUAL)

re: fclean all
