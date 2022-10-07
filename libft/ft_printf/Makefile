LIBFT = ./libft/libft.a

NAME = libftprintf.a

SRCSPATH = src/

SRCS =  ft_printf.c \
		ft_treatment.c \
		ft_tools.c \
		ft_tools2.c \
		ft_tools3.c \
		ft_treat_string.c \
		ft_treat_char.c \
		ft_treat_flags.c \
		ft_treat_float.c \
		ft_treat_percent.c \
		ft_treat_int.c \
		ft_treat_hex.c \
		ft_itoa_signed.c \
		ft_itoa_unsigned.c \
		ft_treat_uint.c \
		ft_treat_oct.c \
		ft_treat_pointer.c \
		ft_helpers.c \

		
LIBFT_FUNCTIONS = $(addprefix libft/, ft_atoi.o \
		ft_bzero.o \
		ft_isalnum.o \
		ft_isalpha.o \
		ft_isascii.o \
		ft_isdigit.o \
		ft_isprint.o \
		ft_itoa.o \
		ft_lstadd.o \
		ft_lst_addback_extra.o \
		ft_lstdel.o \
		ft_lstdelone.o \
		ft_lstiter.o \
		ft_lstmap.o \
		ft_lstnew.o \
		ft_memalloc.o \
		ft_memccpy.o \
		ft_memchr.o \
		ft_memcmp.o \
		ft_memcpy.o \
		ft_memdel.o \
		ft_memmove.o \
		ft_memset.o \
		ft_putchar.o \
		ft_putchar_fd.o \
		ft_putendl.o \
		ft_putendl_fd.o \
		ft_putnbr.o \
		ft_putnbr_fd.o \
		ft_putstr.o \
		ft_putstr_fd.o \
		ft_strcat.o \
		ft_strchr.o \
		ft_strclr.o \
		ft_strcmp.o \
		ft_strcpy.o \
		ft_strdel.o \
		ft_strdup.o \
		ft_strequ.o \
		ft_striter.o \
		ft_striteri.o \
		ft_strjoin.o \
		ft_strlcat.o \
		ft_strlen.o \
		ft_strmap.o \
		ft_strmapi.o \
		ft_strncat.o \
		ft_strncmp.o \
		ft_strncpy.o \
		ft_strnequ.o \
		ft_strnew.o \
		ft_strnstr.o \
		ft_strrchr.o \
		ft_strsplit.o \
		ft_strstr.o \
		ft_strsub.o \
		ft_strtrim.o \
		ft_tolower.o \
		ft_toupper.o)


FLAGS = -c -Wall -Wextra -Werror

INCLUDES = -I ./includes

OBJS = $(SRCS:.c=.o)

P_SRCS = $(addprefix $(SRCSPATH), $(SRCS))

LIB_A = ../libft.a

all : $(NAME)

$(NAME):
	@gcc $(FLAGS) $(INCLUDES) $(P_SRCS)
	@cp $(LIB_A) $(NAME)
	@ar -rc $(NAME) $(OBJS) 

clean :
	@rm -f $(OBJS)

fclean : clean
	@rm -f $(NAME)

re : fclean all
