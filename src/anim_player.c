/*
** EPITECH PROJECT, 2020
** undefined
** File description:
** rect.c
*/

#include"../include/defender.h"

float get_time(sfClock *clock)
{
    sfTime time;
    float seconds;

    time = sfClock_getElapsedTime(clock);
    seconds = time.microseconds / 1000000.0;
    return (seconds);
}

void move_rect(sfIntRect *rect, int shifft, int max_value, sfClock *clock)
{
    float time;

    time = get_time(clock);
    if (time >= 0.12) {
        rect->left += shifft;
        if (rect->left > max_value)
            rect->left = 0;
        sfClock_restart(clock);
    }
}

void anim_player(sfRenderWindow *window,
sfIntRect *rect, sfClock *clock, game_t *game)
{
    background_t *bg = game->scenes[1].background;
    enemy_l *list = game->scenes[1].enemy_list;
    enemy_t *current = list->first;
    enemy_t *previous;
    sfVector2f *currentpos;

    move_rect(rect, 40, 140, clock);
    while (current != NULL) {
        sfSprite_setTextureRect(current->sprite, *rect);
        previous = current;
        current = current->next;
    }
}