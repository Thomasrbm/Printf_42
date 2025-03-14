.PHONY: all clean fclean re

NAME = libftprintf.a

SRC = ft_printf.c ft_printf_utils.c ft_printf_utils2.c
LIBFT_SRC = libft/ft_strlen.c libft/ft_itoa.c libft/ft_putstr.c

ALL_SRC = $(SRC) $(LIBFT_SRC)

OBJS = ${ALL_SRC:.c=.o}

CC = cc
CFLAGS = -Wall -Werror -Wextra -O0 -I ./ -I libft/

%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@

$(NAME): ${OBJS}
	ar -rsc ${NAME} ${OBJS}

all: $(NAME)

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all
