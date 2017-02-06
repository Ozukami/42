# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apoisson <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/26 11:58:55 by apoisson          #+#    #+#              #
#    Updated: 2017/02/06 01:28:47 by apoisson         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
FLAGS = -Wall -Wextra -Werror
PRINTFSRC = ft_va_arg_p.c ft_sprintf.c ft_va_arg_o.c ft_va_arg_x.c ft_va_arg_d.c ft_c.c ft_get.c ft_putchar_v2.c ft_x.c ft_conv.c ft_o.c ft_s.c ft_d.c ft_printf.c ft_va_arg_u.c
LFTSRC = ft_lslen.c ft_ultoa_base.c ft_ulltoa_base.c ft_stoa_unsigned.c ft_ltoa_unsigned.c ft_lltoa_unsigned.c ft_stoa_base.c ft_ltoa_base.c ft_lltoa_base.c ft_itoa_unsigned.c ft_bspace.c ft_strspace.c ft_recursive_power.c ft_atoi.c ft_bzero.c ft_check_spaces.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_islower.c ft_isprint.c ft_isspace.c ft_isupper.c ft_itoa.c ft_itoa_base.c ft_lstadd.c ft_lstdel.c ft_lstdelone.c ft_lstiter.c ft_lstmap.c ft_lstnew.c ft_max.c ft_memalloc.c ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memdel.c ft_memmove.c ft_memset.c ft_min.c ft_putchar.c ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c ft_putnbr.c ft_putnbr_endl.c ft_putnbr_fd.c ft_putnbr_long.c ft_putnbr_short.c ft_putnbr_u_int.c ft_putnbr_u_long.c ft_putnbr_u_short.c ft_putstr.c ft_putstr_fd.c ft_straddchar.c ft_strcat.c ft_strchr.c ft_strclr.c ft_strcmp.c ft_strcpy.c ft_strdel.c ft_strdup.c ft_strequ.c ft_striter.c ft_striteri.c ft_strjoin.c ft_strjoinf.c ft_strlcat.c ft_strlen.c ft_strmap.c ft_strmapi.c ft_strncat.c ft_strncmp.c ft_strncpy.c ft_strnequ.c ft_strnew.c ft_strnstr.c ft_strrchr.c ft_strrev.c ft_strsplit.c ft_strstr.c ft_strsub.c ft_strtrim.c ft_tolower.c ft_toupper.c
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
	@./a.out $(ARGS)
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
