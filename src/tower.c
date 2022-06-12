/*
** EPITECH PROJECT, 2020
** undefined
** File description:
** tower.c
*/

#include "../include/defender.h"

void display_towers(game_t *game)
{
    background_t *bg = game->scenes[1].background;
    sfRenderWindow *window = game->window;
    int index = 0;

    for (int i = 0; bg->slots[i].pos.x != 0; i++) {
        index = find_index(bg->slots[i].type);
        if (bg->slots[i].type != 0)
            square(window, bg->sprites[index],
            bg->slots[i].pos.x, bg->slots[i].pos.y);
    }
}

void click_tower(sfEvent event, game_t *game, int *placed, int type)
{
    background_t *bg = game->scenes[1].background;
    slots_t *slot = game->scenes[1].background->slots;
    sfVector2i click_pos = sfMouse_getPositionRenderWindow(game->window);

        if (event.mouseButton.button == sfMouseLeft)
            for (int i = 0; slot[i].pos.x != 0 && slot[i].pos.y != 0; i++) {
                if (click_pos.x >= slot[i].pos.x && click_pos.x <= slot[i].pos.x + 80 &&
                click_pos.y >= slot[i].pos.y && click_pos.y <= slot[i].pos.y + 80) {
                    if (game->scenes[1].background->slots[i].type == 0) {
                        game->scenes[1].background->slots[i].type = type;
                        game->money -= game->prices[type-1];
                        sfSound_play(game->sounds[e_sell]);
                    }
                    *placed = 1;
                }
            }
        if (event.mouseButton.button == sfMouseRight)
            *placed = 1;
}

void tower_follow(game_t *game, int type) {
    background_t *bg = game->scenes[1].background;
    sfVector2i click_pos = sfMouse_getPositionRenderWindow(game->window);
    int index = find_index(type);

    sfRenderWindow_clear(game->window, sfBlack);
    display(game);
    square(game->window, bg->sprites[30],
    click_pos.x - 200,  click_pos.y - 200);
    square(game->window, bg->sprites[index],
    click_pos.x - 40,  click_pos.y - 40);
    sfRenderWindow_display(game->window);
}

void place_tower(game_t *game, int type)
{
    int placed = 0;
    sfEvent event;

    if (game->money < game->prices[type-1]) {
        my_putstr("NOT ENOUGH MONEY TO BUY TURRET !!!\n");
        return;
    }
    if (type == 4) {
        sfSound_play(game->sounds[e_heal]);
        game->life += 20;
        game->money -= 200;
        return;
    }
    while (placed == 0) {
        tower_follow(game, type);
        while (sfRenderWindow_pollEvent(game->window, &event))
            if (event.type == sfEvtMouseButtonPressed) {
                click_tower(event, game, &placed, type);
            }
    }
}

void click_sell_tower(sfEvent event, game_t *game, int *placed)
{
    background_t *bg = game->scenes[1].background;
    slots_t *slot = game->scenes[1].background->slots;
    sfVector2i click_pos = sfMouse_getPositionRenderWindow(game->window);

        if (event.mouseButton.button == sfMouseLeft)
            for (int i = 0; slot[i].pos.x != 0 && slot[i].pos.y != 0; i++) {
                if (click_pos.x >= slot[i].pos.x &&
                click_pos.x <= slot[i].pos.x + 80 &&
                click_pos.y >= slot[i].pos.y &&
                click_pos.y <= slot[i].pos.y + 80) {
                    if (game->scenes[1].background->slots[i].type != 0) {
                        game->scenes[1].background->slots[i].type = 0;
                        game->money += 100;
                    }
                    *placed = 1;
                }
            }
        if (event.mouseButton.button == sfMouseRight)
            *placed = 1;
}