##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

SRC	=	my_sokoban.c\
		sokoban_read.c	\
		sokoban_read2.c	\
		sokoban_utils.c	\
		sokoban_game_loop.c	\
		sokoban_print.c	\
		sokoban_flag_h.c\
		sokoban_loose.c \
		my_putstr.c	\
		my_putchar.c\

OBJ	=	$(SRC:.c=.o)

NAME	=	my_sokoban

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -g -o  $(NAME) -Wall -Wextra $(OBJ) -lncurses

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all