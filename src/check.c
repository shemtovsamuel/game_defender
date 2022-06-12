/*
** EPITECH PROJECT, 2020
** undefined
** File description:
** check.c
*/

#include "../include/defender.h"

int check_number_slots(background_t *bg)
{
    int nb_slot = 0;

    for (int j = 0; j < bg->rows; j++)
        for (int i = 0; i < bg->cols; i++)
            if (bg->map_2d[j][i] == 'T')
                nb_slot++;
    return (nb_slot);
}

void check_ui_hover(game_t *game)
{
    scene_s *scene = game->scenes + 1;
    static int state = 0;
    sfVector2i click_pos = sfMouse_getPositionRenderWindow(game->window);
    sfVector2f pos;
    sfVector2f size;
    int index = 28;

    size.x = 84;
    size.y = 447;
    for (int i = 0; scene->buttons[i].sprite != NULL; i++) {
        if (button_is_clicked(scene->buttons[i],
        (sfVector2f){click_pos.x, click_pos.y + 20})
        && state == 0 && i < 5) {
            if (game->prices[i] > game->money)
                index = 29;
            pos = sfSprite_getPosition(scene->buttons[i].sprite);
            square(game->window,
            scene->background->sprites[index], pos.x, pos.y);
        }
    }
}

void check_ui(sfEvent event, button *button, game_t *game)
{
    sfVector2f pos;
    sfVector2f click_pos;
    click_pos.x = event.mouseButton.x;
    click_pos.y = event.mouseButton.y;

    for (int i = 0; button[i].sprite != NULL; i++) {
        if (button_is_clicked(button[i], click_pos)) {
            pos = sfSprite_getPosition(button[i].sprite);
            button[i].callback(game, i + 1);
        }
    }
}

int check_enemy_collision(game_t *game, enemy_t *current, enemy_t *previous)
{
    background_t *bg = game->scenes[1].background;
    sfVector2f currentpos;
    sfVector2i pos;

    currentpos = sfSprite_getPosition(current->sprite);
    pos.x = currentpos.x / 40;
    pos.y = currentpos.y / 40;

    if (bg->map_2d[pos.y][pos.x] == 'E') {
        game->life -= 5;
        sfSound_play(game->sounds[e_tower]);
        previous->next = current->next;
        free(current);
    }
}

void check_life(game_t *game)
{
    background_t *bg = game->scenes[1].background;
    enemy_l *list = game->scenes[1].enemy_list;
    enemy_t *current = list->first;
    enemy_t *previous;
    sfVector2f *currentpos;

    while (current != NULL) {
        check_enemy_collision(game, current, previous);
        previous = current;
        current = current->next;
    }

    if (game->life <= 0) {
        game_over(game);
    }
}