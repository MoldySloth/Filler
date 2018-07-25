NAME		= libft.a

CC			= gcc

CFLAGS		= -Wall -Werror -Wextra

SRCS		= ft_strtrim.c ft_strnequ.c ft_strmapi.c ft_strncat.c \
		  		ft_atoi.c ft_strnstr.c ft_isprint.c ft_putendl.c ft_isascii.c \
		  		ft_memalloc.c ft_strrchr.c ft_isalnum.c ft_memcpy.c ft_strncmp.c \
		  		ft_strsplit.c ft_strnew.c ft_tolower.c ft_strsub.c ft_strdup.c \
		  		ft_strdel.c ft_memset.c ft_strmap.c ft_itoa.c ft_strcpy.c \
		  		ft_putnbr_fd.c ft_strlen.c ft_memdel.c ft_putchar_fd.c \
		  		ft_memmove.c ft_strclr.c ft_putstr.c ft_strcat.c ft_strstr.c \
		  		ft_putstr_fd.c ft_strjoin.c ft_bzero.c ft_strequ.c ft_isdigit.c \
		  		ft_toupper.c ft_isalpha.c ft_memccpy.c ft_strnlen.c ft_striter.c \
		  		ft_memchr.c ft_putnbr.c ft_putendl_fd.c ft_strncpy.c ft_memcmp.c \
		  		ft_strlcat.c ft_strchr.c ft_strcmp.c ft_putchar.c ft_striteri.c \
				ft_isspace.c get_next_line.c

SRCS		= $(shell find . -name "*.c")
 
INCLUDES	= -I ./includes

#OBJ		= ft_strtrim.o ft_strnequ.o ft_strmapi.o ft_strncat.o \
		  	ft_atoi.o ft_strnstr.o ft_isprint.o ft_putendl.o ft_isascii.o \
		  	ft_memalloc.o ft_strrchr.o ft_isalnum.o ft_memcpy.o ft_strncmp.o \
		  	ft_strsplit.o ft_strnew.o ft_tolower.o ft_strsub.o ft_strdup.o \
		  	ft_strdel.o ft_memset.o ft_strmap.o ft_itoa.o ft_strcpy.o \
		  	ft_putnbr_fd.o ft_strlen.o ft_memdel.o ft_putchar_fd.o \
		  	ft_memmove.o ft_strclr.o ft_putstr.o ft_strcat.o ft_strstr.o \
		  	ft_putstr_fd.o ft_strjoin.o ft_bzero.o ft_strequ.o ft_isdigit.o \
		  	ft_toupper.o ft_isalpha.o ft_memccpy.o ft_strnlen.o ft_striter.o \
		  	ft_memchr.o ft_putnbr.o ft_putendl_fd.o ft_strncpy.o ft_memcmp.o \
		  	ft_strlcat.o ft_strchr.o ft_strcmp.o ft_putchar.o ft_striteri.o \
			ft_isspace.o get_next_line.o

#OBJ			= $(patsubst %.c, %.o, $(SRC))

OBJ			= $(SRCS:.c=.o)

.PHONY: clean fclean re

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) -c $(SRCS) $(INCLUDES)
	ar -rc $(NAME) $(OBJ)
	ranlib $(NAME)
clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

