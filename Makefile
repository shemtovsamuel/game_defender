##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## build infini_add
##

.PHONY: all clean fclean re

SRC	= 	src/anim_player.c\
	src/check.c\
	src/defender.c\
	src/display.c\
	src/enemy.c\
	src/find.c\
	src/game_loop.c\
	src/game_over.c\
	src/handle.c\
	src/init.c\
	src/init_sprite.c\
	src/main.c\
	src/management.c\
	src/map.c\
	src/pause.c\
	src/sell.c\
	src/size_map.c\
	src/sound.c\
	src/tower.c\
	src/turrets_attack_2.c\
	src/turrets_attack.c\
	src/utils/utils.c\
	src/utils/lib_utils.c\
	src/utils/button.c\
	src/utils/game_utils.c\
	src/utils/game_utils_2.c\
	src/utils/list.c\

OBJ = $(SRC:.c=.o)

NAME = my_defender

CFLAGS += -I./include/

LDFLAGS = -lcsfml-graphics -lcsfml-audio -lcsfml-window -lcsfml-system -g3 -lm

all:	$(NAME)

$(NAME): $(OBJ)
	cd lib/my && make
	gcc -o $(NAME) $(OBJ)  -lm -L./lib -lmy $(LDFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	cd lib/my && make fclean
	cd lib && rm -f libmy.a

re:	fclean all