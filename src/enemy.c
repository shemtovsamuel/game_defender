/*
** EPITECH PROJECT, 2020
** undefined
** File description:
** enemy.c
*/

#include "../include/defender.h"

void move_enemy(enemy_t *current, sfVector2f off, game_t *game, sfVector2i pos)
{
    background_t *bg = game->scenes[1].background;

    if ((bg->map_2d[pos.y - 1][pos.x] == ' ' ||
    bg->map_2d[pos.y - 1][pos.x] == 'E' ) && off.y <= 0)
        sfSprite_move(current->sprite, (sfVector2f){0, -4});
    else if ((bg->map_2d[pos.y + 1][pos.x] == ' ' ||
    bg->map_2d[pos.y + 1][pos.x] == 'E' ) && off.y >= 0 )
        sfSprite_move(current->sprite, (sfVector2f){0, +4});
    if ((bg->map_2d[pos.y][pos.x + 1] == ' ' ||
    bg->map_2d[pos.y][pos.x + 1] == 'E' ) && off.x >= 0)
        sfSprite_move(current->sprite, (sfVector2f){4, 0});
    else if ((bg->map_2d[pos.y][pos.x - 1] == ' '  ||
    bg->map_2d[pos.y][pos.x - 1] == 'E') && off.x <= 0)
        sfSprite_move(current->sprite, (sfVector2f){-4, 0});
}

void check_enemy_life(game_t *game, enemy_t *nearest, enemy_t *n_previous)
{
    enemy_l *list = game->scenes[1].enemy_list;

    if (nearest->health <= 0) {
        if (list->first == nearest)
            list->first = NULL;
        else {
            n_previous->next = nearest->next;
        }
        free(nearest);
        nearest = NULL;
        game->money += 50;
    }
    nearest = NULL;
}