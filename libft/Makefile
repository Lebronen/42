# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lebronen <lebronen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/03 16:09:44 by rshay             #+#    #+#              #
#    Updated: 2022/12/08 22:27:16 by lebronen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS                    =       ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_is_lower.c ft_is_upper.c ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_memcmp.c ft_strlcpy.c ft_strlcat.c \
					ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c \
					ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putnbr_base.c ft_putaddr.c ft_printf.c ft_putstr_len.c ft_putstr_free.c ft_sizetoa.c ft_ustoa.c ft_itoa_ns.c
BONUS			=	ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c \
				ft_lstmap_bonus.c 

OBJS			= $(SRCS:.c=.o)

B_OBJS			= $(BONUS:.c=.o)

CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -I.

NAME			= libft.a

all:			$(NAME)

$(NAME):		$(OBJS)
				ar rcs $(NAME) $(OBJS)

bonus:			$(B_OBJS)
				ar rcs $(NAME) $(B_OBJS)
so:
	$(CC) -nostartfiles -fPIC $(CFLAGS) $(SRCS) $(BONUS)
	gcc -nostartfiles -shared -o libft.so $(OBJS) $(B_OBJS)


clean:
				$(RM) $(OBJS) $(B_OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re bonus
