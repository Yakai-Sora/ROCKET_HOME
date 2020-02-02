##
## EPITECH PROJECT, 2020
## ex00
## File description:
## Makefile
##

CC	=	gcc

# CFLAGS	=	-std=gnu11 -W -Wall -Wextra -Werror

NAME	=	program

RM	=	rm -rf

SRC	=	main.c			\
		list.c			\
		char.c			\
		int.c			\
		float.c			\
		new.c			\

OBJ	=	$(SRC:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
		$(CC) $(OBJ) -o $(NAME) -g3

clean:
		$(RM) $(OBJ)
		$(RM) .vscode

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

bin:	fclean all
		$(RM) $(OBJ)