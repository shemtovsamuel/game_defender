/*
** EPITECH PROJECT, 2020
** undefined
** File description:
** turrets_attack.c
*/

#include "../include/defender.h"

int distance_cal(sfVector2f a, sfVector2f b)
{
    int res = sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));

    return (res);
}

enemy_t *find_nearest(game_t *game, sfVector2f turpos,
    enemy_t *n_previous, sfVector2f *nearestpos)
{
    enemy_l *list = game->scenes[1].enemy_list;
    enemy_t *current = list->first;
    enemy_t *nearest = current;
    enemy_t *previous = current;
    sfVector2f currentpos;
    int distance;

    while (current != NULL) {
        *nearestpos = sfSprite_getPosition(nearest->sprite);
        currentpos = sfSprite_getPosition(current->sprite);
        distance = distance_cal(currentpos, turpos);
        if (distance <= distance_cal(*nearestpos, turpos)) {
            nearest = current;
            *nearestpos = sfSprite_getPosition(current->sprite);
            n_previous = previous;
        }
        previous = current;
        current = current->next;
        *nearestpos = sfSprite_getPosition(nearest->sprite);
    }
    return nearest;
}

void shoot(game_t *game, enemy_t *nearest, enemy_t *n_previous, int i)
{
    background_t *bg = game->scenes[1].background;
    sfVector2f nearestpos;
    int distance = bg->distance;

    if (nearest != NULL) {
        nearestpos = sfSprite_getPosition(nearest->sprite);
    }
    if (nearest != NULL && distance <=
    bg->slot_specs[bg->slots[i].type].range) {
        sfSprite_setPosition(game->scenes[1].objs[2].sprite, nearestpos);
        sfSound_play(game->sounds[e_laser]);
        nearest->health -= bg->slot_specs[bg->slots[i].type-1].damage;
        check_enemy_life(game, nearest, n_previous);
    }
}

void check_turrets_attack(game_t *game)
{
    background_t *bg = game->scenes[1].background;
    enemy_t *n_previous;
    enemy_t *nearest;
    sfVector2f nearestpos;
    sfVector2f turpos;
    int distance;

    for (int i = 0; bg->slots[i].pos.x != 0; i++) {
        if (bg->slots[i].type != 0 && bg->slots[i].type != 4) {
            turpos.x = bg->slots[i].pos.x;
            turpos.y = bg->slots[i].pos.y;
            nearest = find_nearest(game, turpos, n_previous, &nearestpos);
            distance = distance_cal(nearestpos, turpos);
            bg->distance = distance_cal(nearestpos, turpos);
            shoot(game, nearest, n_previous, i);
        }
    }
}