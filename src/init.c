/*
** EPITECH PROJECT, 2020
** undefined
** File description:
** init.c
*/

#include "../include/defender.h"

slots_t *init_slots(scene_s *scene)
{
    slots_t *slots =
        malloc(sizeof(slots_t) * check_number_slots(scene[1].background) + 1);
    int count = 0;

    for (int i = 0; i < scene[1].background->rows; i++) {
        for (int j = 0; j < scene[1].background->cols; j++) {
            if (scene[1].background->map_2d[i][j] == 'T') {
                slots[count].pos.x = j * 40;
                slots[count].pos.y = i * 40;
                slots[count].type = 0;
                count++;
            }
        }
    }
    slots[count].pos.x = 0;
    slots[count].pos.y = 0;
    return (slots);
}

void init_game(int argc, char **argv, game_t *game)
{
    game->scenes[1].background->str = load_map(argc, argv);
    game->scenes[1].background->cols = counter_cols(
        game->scenes[1].background->str) + 1;
    game->scenes[1].background->rows = counter_rows(
        game->scenes[1].background->str) + 1;
    game->scenes[1].background->map_2d = str_to_2d(
        game->scenes[1].background->str,
        game->scenes[1].background->rows,
        game->scenes[1].background->cols);
    game->scenes[1].background->slots = init_slots(game->scenes);
}