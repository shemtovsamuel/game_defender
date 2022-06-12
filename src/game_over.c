/*
** EPITECH PROJECT, 2020
** undefined
** File description:
** game_over.c
*/

#include "../include/defender.h"

void game_overclick(sfEvent *event, game_t *game, int *clicked)
{
    sfVector2f click_pos;
    click_pos.x = event->mouseButton.x;
    click_pos.y = event->mouseButton.y;
    if (event->mouseButton.button == sfMouseLeft)
        if (click_pos.x >= 863 && click_pos.x <= 863 + 255 &&
            click_pos.y >= 646 && click_pos.y <= 646 + 88) {
                exit(0);
                *clicked += 1;
        } else if (click_pos.x >= 863 && click_pos.x <= 863 + 255 &&
            click_pos.y >= 484 && click_pos.y <= 484 + 88) {
                menu(game->scenes, game);
                clear_map(game);
                game_loop(game);
                *clicked += 1;
        }
}

void game_over(game_t *game)
{
    sfEvent event;
    int clicked = 0;

    background_t *bg = game->scenes[1].background;
    sfSound_play(game->sounds[e_game_over]);
    while (clicked == 0 && sfRenderWindow_isOpen(game->window)) {
        square(game->window, bg->sprites[31], 0,  0);
        sfRenderWindow_display(game->window);
        while (sfRenderWindow_pollEvent(game->window, &event))
            if (event.type == sfEvtMouseButtonPressed) {
                game_overclick(&event, game, &clicked);
            }
    }
}