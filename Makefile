##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## File required for the compilation of the my_hunter project
##

SRC=	main.c	\
		initializer.c	\
		window_manager.c	\

CFLAGS+=	-I.

OBJ=	$(SRC:.c=.o)

NAME=	my_hunter

all=	$(NAME)

$(NAME):	$(OBJ)
	gcc -lcsfml-graphics -lcsfml-window -lcsfml-system -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm $(NAME)

re:	fclean

.PHONY:	all re clean fclean
