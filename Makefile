##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## My_Hunter
##

SRC	=	src/main.c			\
		src/clock.c			\
		src/display.c			\
		src/event.c			\
		src/music.c			\
		src/sprite.c			\
		src/sprite_elem.c		\
		src/my_putchar.c		\
		src/my_putstr.c			\
		src/my_put_nbr.c

OBJ	=	$(SRC:.c=.o)

NAME	=	my_hunter

CFLAGS	=	-W -Wall -Wextra -Iinc

LDFLAGS	=	-l c_graph_prog 

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm $(NAME)

re: fclean all

.PHONY: all clean fclean re
