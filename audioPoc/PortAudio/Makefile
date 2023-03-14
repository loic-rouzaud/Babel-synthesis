##
## EPITECH PROJECT, 2023
## Makefile of portaudio
## File description:
## Makefile portaudio
##

SRC =	src/PortAudio.c	\
		main.c 	\

OBJ =	$(SRC:.c=.o)

NAME = portaudio

all:	$(NAME)

$(NAME):$(OBJ)
		gcc -o $(NAME) $(OBJ) -g3 -lportaudio

clean:
	rm -rf $(OBJ)

vgclean:
	rm -rf vgcore.*

fclean:	clean vgclean
	rm -rf $(NAME)
	rm -rf libmy.a

re:	fclean all