/*
** EPITECH PROJECT, 2020
** undefined
** File description:
** find.c
*/

#include "../include/defender.h"

int find_index(int type)
{
    int index;

    if (type == 1)
        index = 17;
    if (type == 2)
        index = 26;
    if (type == 3)
        index = 27;
    if (type == 4)
        index = 24;
    if (type == 5)
        index = 25;
    return (index);
}

sfVector2f find_spawner(game_t *game)
{
    background_t *bg = game->scenes[1].background;
    sfVector2f pos;
    sfVector2f pos2;

    for (int i = 0; i < bg->rows; i++)
        for (int j = 0; j < bg->cols; j++)
            if (bg->map_2d[i][j] == 'S') {
                pos.x = j * 40;
                pos.y = i * 40;
            }
    for (int i = 0; i < bg->rows; i++)
        for (int j = 0; j < bg->cols; j++)
            if (bg->map_2d[i][j] == 'E') {
                pos2.x = j * 40;
                pos2.y = i * 40;
            }
    bg->end_pos = pos2;
    return (pos);
}