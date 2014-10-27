##
## Makefile for Makefile in /home/givern_f/Modules/Prog-Elem-C
## 
## Made by Florian Givernaud
## Login   <givern_f@epitech.net>
## 
## Started on  Sat Oct 25 19:41:16 2014 Florian Givernaud
## Last update Mon Oct 27 01:13:19 2014 Florian Givernaud
##

NAME	=	bin/MarioKart

SRC	=	sources/main.c \
		sources/my_getnbr.c \
		sources/my_func.c \
		sources/my_init.c \
		sources/the_game.c

OBJ	=	$(SRC:.c=.o)


all	: $(NAME)

$(NAME)	: $(OBJ)
		cc -o $(NAME) $(OBJ)

clean	:
		rm -f $(OBJ)

fclean	: clean
		rm -f $(NAME)

re	: fclean all

.PHONY	: all clean fclean re
