NAME		= filler

CC			= gcc

CFLAGS		= -g  -Wall -Werror -Wextra

SRCS		= main.c \
			  map_functions.c \
			  player_functions.c \
			  piece_functions.c \
			  init_hmap_func.c \
			  analyse_hmap_func.c \
			  place_piece.c \
			  place_fill.c \
			  free_struct.c

INC			= -I includes/

OBJS		= $(SRCS:.c=.o)

.PHONY: clean fclean re

all: $(NAME)

$(NAME):
	make re -C libft/
	$(CC) $(CFLAGS) -c $(SRCS)
	$(CC) -o $(NAME) $(OBJS) ./libft/libft.a

clean:
	rm -f $(OBJS)
	make clean -C libft/

fclean: clean
	rm -f $(NAME)
	make fclean -C libft/

re: fclean all
