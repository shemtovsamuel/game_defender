/*
** EPITECH PROJECT, 2020
** undefined
** File description:
** handle.c
*/

#include "../include/defender.h"

void handle_enemy_movement(enemy_t *current, game_t *game)
{
    background_t *bg = game->scenes[1].background;
    static sfVector2f previous;
    sfVector2f currentpos;
    sfVector2i pos;
    currentpos = sfSprite_getPosition(current->sprite);
    pos.x = currentpos.x / 40;
    pos.y = currentpos.y / 40;

    sfVector2f offset;
    offset.x = currentpos.x - previous.x;
    offset.y = currentpos.y - previous.y;
    move_enemy(current, offset, game, pos);
    previous = currentpos;
}

void handle_enemies(game_t *game)
{
    enemy_l *list = game->scenes[1].enemy_list;
    enemy_t *current = list->first;
    sfVector2f spawn_pos = find_spawner(game);
    float elapsed = 0;
    static int count = 0;
    background_t *bg = game->scenes[1].background;

    elapsed = get_time(game->clock);
    if (elapsed > 2) {
        sfSprite *sprite = sfSprite_create();
        sfTexture *tex = sfTexture_createFromFile("images/26.png", NULL);
        sfSprite_setTexture(sprite, tex, sfFalse);
        sfSprite_setPosition(sprite, spawn_pos);
        init_enemy(game->scenes[1].enemy_list, sprite);
        sfClock_restart(game->clock);
    }
    while (current != NULL) {
        handle_enemy_movement(current, game);
        current = current->next;
    }
}