# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apoisson <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/03 11:29:15 by apoisson          #+#    #+#              #
#    Updated: 2016/11/17 08:24:23 by apoisson         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
FLAGS = -Wall -Wextra -Werror
SRC = ft_atoi.c ft_lstnew.c ft_putnbr_fd.c ft_strmapi.c ft_bzero.c ft_putstr.c ft_strncat.c ft_check_spaces.c ft_max.c ft_putstr_fd.c ft_strncmp.c ft_isalnum.c ft_memalloc.c ft_strcat.c ft_strncpy.c ft_isalpha.c ft_memccpy.c ft_strchr.c ft_strnequ.c ft_isascii.c ft_memchr.c ft_strclr.c ft_strnew.c ft_isdigit.c ft_memcmp.c ft_strcmp.c ft_strnstr.c ft_islower.c ft_memcpy.c ft_strcpy.c ft_strrchr.c ft_isprint.c ft_memdel.c ft_strdel.c ft_strrev.c ft_isspace.c ft_memmove.c ft_strdup.c ft_strsplit.c ft_isupper.c ft_memset.c ft_strequ.c ft_strstr.c ft_itoa.c ft_min.c ft_striter.c ft_strsub.c ft_lstadd.c ft_putchar.c ft_striteri.c ft_strtrim.c ft_lstdel.c ft_putchar_fd.c ft_strjoin.c ft_tolower.c ft_lstdelone.c ft_putendl.c ft_strlcat.c ft_toupper.c ft_lstiter.c ft_putendl_fd.c ft_strlen.c ft_lstmap.c ft_putnbr.c ft_strmap.c
OBJS = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	gcc $(FLAGS) -c $(SRC)
	ar rc $(NAME) $(OBJS)

main:
	gcc $(FLAGS) main.c -L. -lft

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

mainclean:
	rm -f a.out

re: fclean all
