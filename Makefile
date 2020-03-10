
##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

CC	=	gcc

SRC	=	src/main.c	\
		src/my_hunter.c	\
		src/init_struct.c	\
		src/my_strcmp.c	\
		src/anim_enm.c	\
		src/anim_back.c	\
		src/set_enm.c	\
		src/set_back.c	\
		src/loop_game.c	\
		src/set_menu.c	\
		src/loop_menu.c	\
		src/events_menu.c	\
		src/destroy_struct.c	\
		src/set_opt.c	\
		src/loop_opt.c	\
		src/events_opt.c	\
		src/loop_leaderboard.c	\
		src/set_ldb.c	\
		src/print_descr.c	\
		src/get_from_file.c	\
		src/loop_end.c	\
		src/my_itoa.c	\
		src/my_atoi.c	\
		src/check_score.c	\
		src/put_in_file.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	my_hunter

CFLAGS	=	-W -Wall -I include/

CSFML	=	-lcsfml-audio -lcsfml-window -lcsfml-system -lcsfml-graphics

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(CSFML) $(OBJ)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
