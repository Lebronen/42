SRC = push_swap.c  push_utils.c rotate_utils.c swap_utils.c algo.c\
  libft/ft_atoi.c libft/ft_memcpy.c libft/ft_printf.c

CC = gcc

CFLAGS = -Wall -Wextra -Werror

OBJ = $(SRC:.c=.o)

NAME = push_swap

RM = rm -f

all:		$(NAME)

$(NAME): 	$(OBJ)

clean:
			$(RM) $(OBJ)

fclean:		clean
			$(RM) $(NAME)

re:			fclean $(NAME)

.PHONY:		all clean fclean re
