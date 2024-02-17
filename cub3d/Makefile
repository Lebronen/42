SRC = main.c

OBJ = $(SRC:.c=.o)

CC = gcc
RM = rm -f
NAME = cub3d

all: $(NAME)

%.o: %.c
	$(CC) -Iinclude/ -Imlx_linux -O3 -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(OBJ) -Lmlx_linux -lmlx_Linux -Llib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

clean: 
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re