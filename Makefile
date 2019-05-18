##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

NAME	= my_radar

CC	= gcc

RM	= rm -f

SRC	= 	./src/lib/int_to_char.c \
	  	./src/lib/my_getnbr.c \
	  	./src/lib/my_putstr.c \
	  	./src/lib/my_revstr.c \
	  	./src/lib/my_strcat.c \
	  	./src/lib/my_strcmp.c \
	  	./src/lib/my_strlen.c \
	  	./src/lib/my_strcpy.c \
		./src/lib/add_zero.c \
		./src/create/sprites.c \
		./src/create/window.c \
		./src/destroy/all.c \
		./src/draw/aircrafts.c \
		./src/draw/timer.c \
		./src/draw/towers.c \
		./src/events/aircrafts_colliding.c \
		./src/events/aircrafts_other.c \
		./src/events/all.c \
		./src/file/read.c \
		./src/initializations/aircrafts.c \
		./src/initializations/struct_chain.c \
		./src/initializations/struct.c \
		./src/initializations/towers.c \
		./src/main.c

OBJ	= $(SRC:.c=.o)

FLAG	= -l csfml-graphics -l csfml-system -l csfml-window -l csfml-audio -lm

all: $(NAME)

$(NAME):
	$(CC) $(SRC) -o $(NAME) $(FLAG)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
