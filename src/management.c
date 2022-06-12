/*
** EPITECH PROJECT, 2020
** undefined
** File description:
** management.c
*/

#include "../include/defender.h"

void event_management(sfEvent event, game_t *game)
{
    if (event.type == sfEvtClosed)
        sfRenderWindow_close(game->window);
    if (event.type == sfEvtMouseButtonPressed) {
        if (event.mouseButton.button == sfMouseLeft) {
            check_ui(event, game->scenes[1].buttons, game);
        }
        sfSound_play(game->sounds[e_click]);
    }
    if (event.type == sfEvtKeyPressed)
            if (event.key.code == sfKeyEscape)
                pause_menu(game);
}