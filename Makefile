# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: egaliber <egaliber@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/27 11:07:27 by egaliber          #+#    #+#              #
#    Updated: 2022/10/03 21:51:24 by egaliber         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := egaliber.filler

SRCSPATH = src/

SRCS = main_filler.c \
player_and_map.c \
get_piece.c \
make_board.c \
make_heatmap.c \
helpers.c \
solver.c \



LIBFT_FUNCTIONS = $(addprefix libft/, ft_atoi.o \
		ft_strlen.o \
		ft_strdup.o \
		ft_strcpy.o\
		ft_strncpy.o \
		ft_strcat.o \
		ft_strncat.o \
		ft_strlcat.o \
		ft_strchr.o \
		ft_strrchr.o\
		ft_isalpha.o \
		ft_isdigit.o \
		ft_isalnum.o\
		ft_isascii.o \
		ft_isprint.o \
		ft_toupper.o \
		ft_tolower.o \
		ft_strstr.o \
		ft_memset.o \
		ft_bzero.o \
		ft_memcpy.o \
		ft_memccpy.o\
		ft_memmove.o \
		ft_memchr.o \
		ft_memcmp.o \
		ft_strcmp.o \
		ft_strncmp.o \
		ft_strnstr.o\
		ft_memalloc.o \
		ft_memdel.o \
		ft_strnew.o \
		ft_strdel.o \
		ft_strclr.o \
		ft_striter.o \
		ft_striteri.o \
		ft_strmap.o \
		ft_strmapi.o \
		ft_strequ.o \
		ft_strnequ.o \
		ft_strsub.o \
		ft_strjoin.o \
		ft_strtrim.o \
		ft_strsplit.o \
		ft_itoa.o \
		ft_putchar.o \
		ft_putstr.o \
		ft_putendl.o \
		ft_putnbr.o \
		ft_putchar_fd.o \
		ft_putstr_fd.o \
		ft_putendl_fd.o \
		ft_putnbr_fd.o \
		ft_lstnew.o \
		ft_lstdelone.o \
		ft_lstdel.o \
		ft_lstadd.o \
		ft_lstiter.o \
		ft_lstmap.o \
		ft_lst_addback_extra.o \
		ft_strjoin_f1.o \
		ft_strjoin_f2.o \
		ft_rounding.o \
		ft_power.o \
		ft_itoa_signed.o \
		ft_lstat_extra.o \
		ft_lstlast_extra.o \
		ft_power_to_extra.o \
		get_next_line.o \
		ft_lstsize_extra.o)

FLAGS = -c -Wall -Wextra -Werror

INCLUDES = -I ./includes

OBJS = $(SRCS:.o=.o)

P_SRCS = $(addprefix $(SRCSPATH), $(SRCS))


all : $(NAME)

$(NAME):
	@make -C libft
	@gcc $(FLAGS) $(INCLUDES) $(P_SRCS)
	@ar -rc $(NAME) $(OBJS) $(LIBFT_FUNCTIONS)

clean :
	@make clean -C libft
	@rm -f $(OBJS)

fclean : clean
	@rm -f $(NAME)
	@make fclean -C libft

re : fclean all