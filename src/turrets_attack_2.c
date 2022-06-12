/*
** EPITECH PROJECT, 2020
** undefined
** File description:
** turrets_attack_2.c
*/

#include "../include/defender.h"

void turrets_attack(game_t *game, sfClock *clock)
{
    background_t *bg = game->scenes[1].background;
    enemy_l *list = game->scenes[1].enemy_list;
    enemy_t *current = list->first;

    if (get_time(clock) > 0.2){
        check_turrets_attack(game);
        sfClock_restart(clock);
    }
    if (game->life <= 0)
        game_over(game);
}