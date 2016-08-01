NAME = eval_expr
CC = gcc
FLAGS = -Wall -Wextra -Werror
FILES =	./main.c \
		./ft_putchar_nbr.c \
		./ft_atoi.c \
		./parse_atom.c \
		./eval_expr.c
HEADER = eval.h

all: $(NAME)

$(NAME):
		$(CC) $(FLAGS) -o $(NAME) -I $(HEADER) $(FILES)

.PHONY: clean fclean all re

fclean:
		rm ./$(NAME)

re: fclean	all

