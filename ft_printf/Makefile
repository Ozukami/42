# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apoisson <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/03 11:29:15 by apoisson          #+#    #+#              #
#    Updated: 2016/12/15 09:25:04 by apoisson         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
FLAGS = -Wall -Wextra -Werror
PRINTFSRC = ft*.c
#PRINTFSRC = ft_a_ranger.c ft_fun_1.c ft_fun_3.c ft_itoa_base.c ft_conv.c ft_fun_2.c ft_get.c ft_printf.c
LFTSRC = ft_straddchar.c ft_strjoinf.c ft_atoi.c ft_lstnew.c ft_putnbr_fd.c ft_strmapi.c ft_bzero.c ft_putstr.c ft_strncat.c ft_check_spaces.c ft_max.c ft_putstr_fd.c ft_strncmp.c ft_isalnum.c ft_memalloc.c ft_strcat.c ft_strncpy.c ft_isalpha.c ft_memccpy.c ft_strchr.c ft_strnequ.c ft_isascii.c ft_memchr.c ft_strclr.c ft_strnew.c ft_isdigit.c ft_memcmp.c ft_strcmp.c ft_strnstr.c ft_islower.c ft_memcpy.c ft_strcpy.c ft_strrchr.c ft_isprint.c ft_memdel.c ft_strdel.c ft_strrev.c ft_isspace.c ft_memmove.c ft_strdup.c ft_strsplit.c ft_isupper.c ft_memset.c ft_strequ.c ft_strstr.c ft_itoa.c ft_min.c ft_striter.c ft_strsub.c ft_lstadd.c ft_putchar.c ft_striteri.c ft_strtrim.c ft_lstdel.c ft_putchar_fd.c ft_strjoin.c ft_tolower.c ft_lstdelone.c ft_putendl.c ft_strlcat.c ft_toupper.c ft_lstiter.c ft_putendl_fd.c ft_strlen.c ft_lstmap.c ft_putnbr.c ft_strmap.c
OBJS1 = $(LFTSRC:.c=.o)
OBJS2 = $(PRINTFSRC:.c=.o)

all: $(NAME)

$(NAME):
	@gcc $(FLAGS) -c $(addprefix libft/, $(LFTSRC)) $(addprefix srcs/, $(PRINTFSRC)) -I includes/
	@test -d objs || mkdir objs
	@mv $(OBJS1) objs/
	@mv $(OBJS2) objs/
	@ar rc $(NAME) $(addprefix objs/, $(OBJS1) $(OBJS2))

main: re
	@gcc $(FLAGS) main.c -L. -lftprintf -I includes/
	@rm -rdf objs/
	@printf "\033[0;31m- Executing a.out -\n\033[0m"
	@./a.out
	@printf "\033[0;31m-- End of a.out --\n\033[0m"

clean:
	@rm -rdf objs/

fclean: clean
	@rm -f $(NAME)

mainclean:
	@rm -f a.out

cleanall: mainclean fclean

re: fclean all
