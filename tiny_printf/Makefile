# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apoisson <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/26 11:58:55 by apoisson          #+#    #+#              #
#    Updated: 2017/04/17 05:18:41 by apoisson         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
FLAGS = -Wall -Wextra -Werror
PRINTFSRC = ft_printf.c ft_data.c ft_color.c ft_get_arg.c ft_adjust.c\
ft_get_format.c ft_process.c ft_set.c ft_case.c
LFTSRC = ft_absolute.c ft_memccpy.c ft_strequ.c ft_atoi.c ft_memchr.c ft_striter.c\
ft_atoi_base.c ft_memcmp.c ft_striteri.c ft_bspace.c ft_memcpy.c ft_strjoin.c\
ft_bzero.c ft_memdel.c ft_strjoinf.c ft_check_spaces.c ft_memmove.c ft_strlcat.c\
ft_count_digit.c ft_memset.c ft_strlen.c ft_fill_zero.c ft_min.c ft_strmap.c\
ft_free_rect.c ft_new_coord.c ft_strmapi.c ft_isalnum.c ft_new_rect.c ft_strncat.c\
ft_isalpha.c ft_putchar.c ft_strncmp.c ft_isascii.c ft_putchar_fd.c ft_strncpy.c\
ft_isdigit.c ft_putendl.c ft_strnequ.c ft_islower.c ft_putendl_fd.c ft_strnew.c\
ft_isprint.c ft_putnbr.c ft_strnstr.c ft_isspace.c ft_putnbr_endl.c ft_strrchr.c\
ft_isupper.c ft_putnbr_fd.c ft_strrev.c ft_itoa.c ft_putstr.c ft_strspace.c\
ft_itoa_base.c ft_putstr_fd.c ft_strsplit.c ft_lltoa_base.c ft_recursive_power.c\
ft_strstr.c ft_lslen.c ft_set_coord.c ft_strsub.c ft_lstadd.c ft_straddchar.c\
ft_strtrim.c ft_lstdel.c ft_strcat.c ft_strzero.c ft_lstdelone.c ft_strchr.c\
ft_tolower.c ft_lstiter.c ft_strclr.c ft_toupper.c ft_lstmap.c ft_strcmp.c\
ft_ulltoa_base.c ft_lstnew.c ft_strcpy.c get_next_line.c ft_max.c ft_strdel.c\
ft_memalloc.c ft_strdup.c
OBJS1 = $(LFTSRC:.c=.o)
OBJS2 = $(PRINTFSRC:.c=.o)
OBJS = $(OBJS2) $(OBJS1)

all: $(NAME)

$(NAME): $(addprefix objs/, $(OBJS2)) $(addprefix objs/, $(OBJS1))
	@printf "\033[0;35m> Compiling libftprintf.a\033[0m"
	@ar rc $(NAME) $(addprefix objs/, $(OBJS))
	@printf "\033[0;32m > OK\n\033[0m"

$(addprefix objs/, $(OBJS1)): $(addprefix libft/, $(LFTSRC))
	@printf "\033[0;35m.\033[0m"
	@gcc $(FLAGS) -c $(addprefix libft/, $(addsuffix .c, $(basename $(notdir $@)))) -o objs/$(notdir $@) -I includes/

$(addprefix objs/, $(OBJS2)): $(addprefix srcs/, $(PRINTFSRC))
	@test -d objs || mkdir objs
	@printf "\033[0;35m.\033[0m"
	@gcc $(FLAGS) -c $(addprefix srcs/, $(addsuffix .c, $(basename $(notdir $@)))) -o objs/$(notdir $@) -I includes/

main: a.out
	@printf "\033[0;31m- Executing a.out -\n\033[0m"
	@./a.out
	@printf "\033[0;31m-- End of a.out --\n\033[0m"

a.out: $(NAME) main.c
	@gcc -Wall -Wextra main.c -L. -lftprintf -I includes/

test: test.out
	@printf "\033[0;31m- Executing test.out -\n\033[0m"
	@./test.out $(ARGS)
	@printf "\033[0;31m-- End of test.out --\n\033[0m"

test.out: $(NAME) test.c
	@gcc -Wall -Wextra test.c -L. -lftprintf -I includes/ -o test.out

clean:
	@rm -rdf objs/

fclean: clean
	@rm -f $(NAME)

mainclean:
	@rm -f a.out

testclean:
	@rm -f test.out

cleanall: mainclean testclean fclean

re: fclean all
