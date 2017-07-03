# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lcharbon <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/21 11:21:25 by lcharbon          #+#    #+#              #
#    Updated: 2017/06/10 11:46:22 by lcharbon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
FLAG = -Wall -Werror -Wextra
CC = gcc

SRC_P = ./src/
SRCTWO_P = ./src_two/
SRCPF_P = ./ft_printf/srcs/
OBJ_P = ./obj/
OBJTWO_P = ./obj/
OBJPF_P = ./ft_printf/obj/
INC_P = ./include/

SRCTWO_N = free_map.c ft_absolute.c ft_atoi_base.c ft_atol.c ft_bspace.c \
	   	  ft_check_spaces.c ft_count_digit.c ft_fill_zero.c \
		  ft_free_rect.c ft_islower.c ft_isprint.c ft_isspace.c \
		  ft_isupper.c ft_lltoa_base.c ft_max.c ft_memalloc.c \
		  ft_min.c ft_my_printf.c ft_new_coord.c ft_new_rect.c \
		  ft_perror.c ft_putnbr_endl.c ft_recursive_power.c \
		  ft_set_coord.c ft_straddchar.c ft_strclr.c ft_strequ.c \
		  ft_strequf_l.c ft_strjoinf.c ft_strjoinf_l.c ft_strjoinf_r.c \
		  ft_strnequ.c ft_strrev.c ft_strspace.c ft_strsplitf.c \
		  ft_strsplit_whitespaces.c ft_strsubf.c ft_strzero.c \
		  ft_ulltoa_base.c get_next_line.c str_epur.c \
		  str_epurf.c tab_size.c

SRCPF_N = ft_printf.c ftpf_get_data.c ftpf_get.c ftpf_convert.c \
		  ftpf_utils.c ftpf_sign_conv.c ftpf_unsign_conv.c \
		  ftpf_valist_sign.c ftpf_sign_itoa.c ftpf_valist_unsign.c \
		  ftpf_uitoa_base.c ftpf_valist_char.c ftpf_ch_conv.c \
		  ftpf_valist_strings.c ftpf_strings_conv.c ftpf_unsign_p_conv.c \
		  ftpf_float_conv.c ftpf_float_itoa.c ftpf_n_conv.c \
		  ftpf_hexafloat_conv.c ftpf_get_special.c ftpf_apo_flag.c \
		  ftpf_expo_itoa.c ftpf_expo_conv.c ftpf_utils_bis.c \
		  ftpf_gep_conv.c ftpf_gep_itoa.c ftpf_iso_conv.c

SRC_N = ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c \
		ft_memmove.c ft_memchr.c ft_memcmp.c ft_strlen.c \
		ft_strdup.c ft_strcpy.c ft_strncpy.c ft_strcat.c \
		ft_strncat.c ft_strlcat.c ft_strchr.c ft_strrchr.c \
		ft_strstr.c ft_strnstr.c ft_strcmp.c ft_strncmp.c \
		ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c \
		ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c \
		ft_memalloc.c ft_memdel.c ft_strnew.c ft_strdel.c \
		ft_strclr.c ft_striter.c ft_striteri.c ft_strmap.c \
		ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c \
		ft_strjoin.c ft_strtrim.c ft_strsplit.c ft_itoa.c \
		ft_putchar.c ft_putstr.c ft_putendl.c ft_putnbr.c \
		ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
		ft_putnbr_fd.c ft_lstadd.c ft_lstnew.c ft_lstiter.c \
		ft_lstmap.c ft_lstdelone.c ft_lstdel.c ft_strnewch.c \
		ft_str_insert.c ft_putaddr.c ft_uitoa_base.c ft_strjoindel.c \
		ft_uitoa.c ft_uatoi.c ft_count_c_int.c ft_power.c \
		ft_line_reader.c ft_strsubdel.c ft_abs.c \
		ft_int_bigger.c ft_int_lower.c ft_test_memory.c \
		ft_strndup.c ft_atoidel.c

OBJ_N =$(SRC_N:.c=.o)
OBJTWO_N =$(SRCTWO_N:.c=.o)
OBJPF_N =$(SRCPF_N:.c=.o)

SRC = $(addprefix $(SRC_P),$(SRC_N))
SRCTWO = $(addprefix $(SRCTWO_P),$(SRCTWO_N))
SRCPF = $(addprefix $(SRCPF_P),$(SRCPF_N))
OBJ = $(addprefix $(OBJ_P),$(OBJ_N))
OBJTWO = $(addprefix $(OBJTWO_P),$(OBJTWO_N))
OBJPF = $(addprefix $(OBJPF_P),$(OBJPF_N))
INC = $(addprefix -I,$(INC_P))

all : $(NAME)

$(NAME): $(OBJ) $(OBJTWO) $(OBJPF)
	@ar rc $@ $^
	@echo
	@echo "\x1b[33mLibrairie...... libft.a |\x1b[32m| done\x1b[37m"
	@ranlib $@
	@echo
	@echo "\x1b[33mIndex.......... libft.a |\x1b[32m| done\x1b[37m"

$(OBJ_P)%.o: $(SRC_P)%.c
	@mkdir -p $(OBJ_P)
	@$(CC) $(FLAG) $(INC) -o $@ -c $<
	@echo "\x1b[33mCompilation.... $@ $< |\x1b[32m| done\x1b[37m"

$(OBJTWO_P)%.o: $(SRCTWO_P)%.c
	@mkdir -p $(OBJTWO_P)
	@$(CC) $(FLAG) $(INC) -o $@ -c $<
	@echo "\x1b[33mCompilation.... $@ $< |\x1b[32m| done\x1b[37m"

$(OBJPF_P)%.o: $(SRCPF_P)%.c
	@mkdir -p $(OBJPF_P)
	@$(CC) $(FLAG) $(INC) -o $@ -c $<
	@echo "\x1b[33mCompilation.... $@ $< |\x1b[32m| done\x1b[37m"

clean:
	@rm -f $(OBJ)
	@rm -f $(OBJTWO)
	@rm -f $(OBJPF)
	@rmdir $(OBJ_P) 2> /dev/null || echo "" > /dev/null
	@rmdir $(OBJPF_P) 2> /dev/null || echo "" > /dev/null
	@echo "\x1b[33mRemove......... |\x1b[32m| done\x1b[37m"

fclean: clean
	@rm -f $(NAME)
	@echo "\x1b[33mRemove all..... |\x1b[32m| done\x1b[37m"

re: fclean all
