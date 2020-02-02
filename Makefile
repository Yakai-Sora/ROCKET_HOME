##
## EPITECH PROJECT, 2020
## undefined
## File description:
## Makefile
##

CC			=		g++

RM			=		rm -f

SRC			=		main.cpp					\
					characters/Character.cpp	\
					gui/Stuff.cpp				\
					gui/Menu.cpp				\
					gui/Craft.cpp				\
					gui/Button.cpp				\
					objects/Items.cpp			\
					objects/Ressources.cpp		\
					objects/Object.cpp			\
					graphical/Camera.cpp		\
					map/TilesMap.cpp 			\
					tools/PerlinNoise2d.cpp 	\

OBJ			=		$(SRC:.cpp=.o)

NAME		=		game

all:		$(NAME)

$(NAME):	$(OBJ)
			$(CC)  -Wall -Wextra -Werror -std=c++14 -o $(NAME) $(OBJ) -lsfml-system -lsfml-graphics -lsfml-window -lsfml-audio

clean:
		$(RM) $(OBJ)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

bin:		fclean all
			$(RM) $(OBJ)