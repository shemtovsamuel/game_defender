/*
** EPITECH PROJECT, 2020
** Project
** File description:
** Project
*/

#include "../include/defender.h"
#include "../include/game.h"
#include "../include/ui.h"
#include "../include/my.h"
#include "../include/sound.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <stdarg.h>
#include <SFML/Audio.h>
#include <stdbool.h>
#include <math.h>
#define abs(x)  ( (x<0) ? -x : x )

sfIntRect init_rect(void)
{
    sfIntRect rect;

    rect.top = 0;
    rect.left = 0;
    rect.width = 40;
    rect.height = 40;
    return rect;
}

void game_loop(game_t *game)
{
    game->clock = sfClock_create();
    sfClock *turretClock = sfClock_create();
    sfClock *anim_clock = sfClock_create();
    background_t *bg = game->scenes[1].background;
    sfEvent event;
    sfIntRect rect = init_rect();

    sfSound_play(game->sounds[e_music]);
    sfSprite_setPosition(game->scenes[1].objs[2].sprite, (sfVector2f){2000, 1100});
    while (sfRenderWindow_isOpen(game->window)) {
        sfRenderWindow_clear(game->window, sfBlack);
        handle_enemies(game);
        check_life(game);
        turrets_attack(game, turretClock);
        anim_player(game->window, &rect, anim_clock, game);
        sfSprite_setRotation(game->scenes[1].background->sprites[15],
        sfSprite_getRotation(game->scenes[1].background->sprites[15]) + 2);
        display(game);
        while (sfRenderWindow_pollEvent(game->window, &event))
            event_management(event, game);
    }
}