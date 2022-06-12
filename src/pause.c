/*
** EPITECH PROJECT, 2020
** undefined
** File description:
** pause.c
*/

#include "../include/defender.h"

void pause_click_2(sfVector2f click_pos, int *clicked)
{
    if (click_pos.x >= 863 && click_pos.x <= 863 + 255 &&
            click_pos.y >= 744 && click_pos.y <= 744 + 88) {
                exit(0);
                *clicked += 1;
            }
}

void pause_click(sfEvent *event, game_t *game, int *clicked)
{
    sfVector2f click_pos;

    click_pos.x = event->mouseButton.x;
    click_pos.y = event->mouseButton.y;
    if (event->mouseButton.button == sfMouseLeft)
        if (click_pos.x >= 822 && click_pos.x <= 822 + 255 &&
            click_pos.y >= 419 && click_pos.y <= 419 + 88) {
                *clicked += 1;
        } else if (click_pos.x >= 863 && click_pos.x <= 863 + 255 &&
            click_pos.y >= 582 && click_pos.y <= 582 + 88) {
                menu(game->scenes, game);
                clear_map(game);
                game->life = 100;
                game_loop(game);
                *clicked += 1;
        }
        pause_click_2(click_pos, clicked);
}

void pause_menu(game_t *game)
{
    sfEvent event;
    int clicked = 0;
    background_t *bg = game->scenes[1].background;

    while (clicked == 0 && sfRenderWindow_isOpen(game->window)) {
        square(game->window, bg->sprites[32], 0,  0);
        sfRenderWindow_display(game->window);
        while (sfRenderWindow_pollEvent(game->window, &event))
            if (event.type == sfEvtMouseButtonPressed) {
                pause_click(&event, game, &clicked);
            }
    }
}