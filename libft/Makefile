# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: egaliber <egaliber@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/03 14:11:33 by elliotgalib       #+#    #+#              #
#    Updated: 2022/10/06 19:58:39 by egaliber         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libft.a

SRC = 	ft_atoi.c \
		ft_strlen.c \
		ft_strdup.c \
		ft_strcpy.c\
		ft_strncpy.c \
		ft_strcat.c \
		ft_strncat.c \
		ft_strlcat.c \
		ft_strchr.c \
		ft_strrchr.c\
		ft_isalpha.c \
		ft_isdigit.c \
		ft_isalnum.c\
		ft_isascii.c \
		ft_isprint.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_strstr.c \
		ft_memset.c \
		ft_bzero.c \
		ft_memcpy.c \
		ft_memccpy.c\
		ft_memmove.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_strcmp.c \
		ft_strncmp.c \
		ft_strnstr.c\
		ft_memalloc.c \
		ft_memdel.c \
		ft_strnew.c \
		ft_strdel.c \
		ft_strclr.c \
		ft_striter.c \
		ft_striteri.c \
		ft_strmap.c \
		ft_strmapi.c \
		ft_strequ.c \
		ft_strnequ.c \
		ft_strsub.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_strsplit.c \
		ft_itoa.c \
		ft_putchar.c \
		ft_putstr.c \
		ft_putendl.c \
		ft_putnbr.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_lstnew.c \
		ft_lstdelone.c \
		ft_lstdel.c \
		ft_lstadd.c \
		ft_lstiter.c \
		ft_lstmap.c \
		ft_lst_addback_extra.c \
		ft_strjoin_f1.c \
		ft_strjoin_f2.c \
		ft_rounding.c \
		ft_power.c \
		ft_itoa_signed.c \
		ft_lstat_extra.c \
		ft_lstlast_extra.c \
		ft_power_to_extra.c \
		ft_lstsize_extra.c \
		get_next_line.c \
		
OBJ = $(SRC:.c=.o)

PRINTF_LIB = ft_printf/libftprintf.a

all: $(NAME)

$(NAME):
	@gcc -Wall -Wextra -Werror -c $(SRC)
	@ar rc $(NAME) $(OBJ)
	@make -C ft_printf
	@cp $(PRINTF_LIB) $(NAME)

clean:
	@rm -f $(OBJ)
	@make -C ft_printf clean

fclean: clean
	@rm -f $(NAME)
	@make -C ft_printf fclean

re: fclean all