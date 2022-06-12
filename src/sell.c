/*
** EPITECH PROJECT, 2020
** undefined
** File description:
** sell.c
*/

#include "../include/defender.h"

void sell_follow(game_t *game) {
    background_t *bg = game->scenes[1].background;
    sfVector2i click_pos = sfMouse_getPositionRenderWindow(game->window);

    sfRenderWindow_clear(game->window, sfBlack);
    display(game);
    sfSprite_setScale(bg->sprites[21], (sfVector2f){0.5, 0.5});
    square(game->window, bg->sprites[21], click_pos.x - 37,  click_pos.y - 37);
    sfRenderWindow_display(game->window);
}

void sell_tower(game_t *game, int type)
{
    int placed = 0;
    sfEvent event;

    while (placed == 0) {
        sell_follow(game);
        while (sfRenderWindow_pollEvent(game->window, &event))
            if (event.type == sfEvtMouseButtonPressed) {
                click_sell_tower(event, game, &placed);
            }
    }
}