##
## EPITECH PROJECT, 2023
## header*
## File description:
## lolm
##

SRC		=	src/my_sokoban.c				\
			src/action_player.c				\
			src/my_strlen.c					\
			src/my_strdup.c					\
			src/my_strcmp.c					\
			src/algo_win_or_losse.c			\
			src/description.c				\

OBJ		=	$(SRC:.c=.o)
NAME	=	sokoban

CC		=	gcc
CFLAGS	=	-I ./include/ -Wextra -Wall -W -lncurses -lm

all:    	$(NAME)

$(NAME):	$(OBJ)
			$(CC) $(OBJ) -o $@ $(CFLAGS)
%.o: %.c
	$(CC) -c $< -o $@ $(CFLAGS)

clean:
			rm -f $(OBJ)

fclean: 	clean
			rm -f $(OBJ)
			rm -f $(NAME)

debug:	CFLAGS+= -g
debug:	valgrind

re:		fclean all

.PHONY:	all clean fclean re debug
