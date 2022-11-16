SRC	=	ft_printf.c ft_itoa.c ft_putaddr.c ft_putchar_fd.c ft_putnbr_base.c \
		ft_putstr_fd.c ft_putstr_len.c ft_is_lower.c ft_strlen.c ft_putstr_free.c \
		ft_itoa_ns.c ft_sizetoa.c ft_ustoa.c

OBJS	=	$(SRC:.c=.o)

CC	=	gcc
RM	=	rm -f
CFLAGS	=	-Wall -Wextra -Werror -c -I

NAME	=	libftprintf.a

all:		$(NAME)

$(NAME):	$(OBJS)
			ar rc $(NAME) $(OBJS)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean $(NAME)

.PHONY:		all clean fclean re
