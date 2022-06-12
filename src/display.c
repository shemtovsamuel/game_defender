/*
** EPITECH PROJECT, 2020
** undefined
** File description:
** display.c
*/

#include "../include/defender.h"

void square(sfRenderWindow *window, sfSprite *sprite, int x, int y)
{
    sfVector2f background_pos = {x, y};
    sfVector2f background_scale = {1, 1};

    sfSprite_setScale(sprite, background_scale);
    sfSprite_setPosition(sprite, background_pos);
    sfRenderWindow_drawSprite(window, sprite, NULL);
}

void display_1(game_t * game, sfRenderWindow *window)
{
    background_t *bg = game->scenes[1].background;
    for (int j = 0; j < bg->rows; j++)
        for (int i = 0; i < bg->cols; i++) {
            if (bg->map_2d[j][i] == 'x')
                square(window, bg->sprites[1], i * 40, j * 40);
            if (bg->map_2d[j][i] == ' ')
                square(window, bg->sprites[2], i * 40, j * 40);
            if (bg->map_2d[j][i] == 'E')
                square(window, bg->sprites[18], i * 40 + 20, j * 40 + 20);
            if (bg->map_2d[j][i] == 'F')
                square(window, bg->sprites[3], i * 40, j * 40);
            if (square(window, bg->sprites[6], i * 40, j * 40));
            if (bg->map_2d[j][i] == 'H')
                square(window, bg->sprites[4], i * 40, j * 40);
            if (bg->map_2d[j][i] == 'I')
                square(window, bg->sprites[5], i * 40, j * 40);
            if (bg->map_2d[j][i] == 'B')
                square(window, bg->sprites[7], i * 40, j * 40);
        }
}

void display_2(game_t * game, sfRenderWindow *window)
{
    background_t *bg = game->scenes[1].background;
    for (int j = 0; j < bg->rows; j++)
        for (int i = 0; i < bg->cols; i++) {
            if (bg->map_2d[j][i] == 'C')
                square(window, bg->sprites[9], i * 40, j * 40);
            if (bg->map_2d[j][i] == 'D')
                square(window, bg->sprites[10], i * 40, j * 40);
            if (bg->map_2d[j][i] == 'R')
                square(window, bg->sprites[8], i * 40, j * 40);
            if (bg->map_2d[j][i] == 'W')
                square(window, bg->sprites[12], i * 40, j * 40);
            if (bg->map_2d[j][i] == 'P')
                square(window, bg->sprites[11], i * 40, j * 40);
            if (bg->map_2d[j][i] == 'Y')
                square(window, bg->sprites[14], i * 40, j * 40);
            if (bg->map_2d[j][i] == 'Z')
                square(window, bg->sprites[13], i * 40, j * 40);
        }
}

void display(game_t *game)
{
    background_t *bg = game->scenes[1].background;
    sfRenderWindow *window = game->window;

    display_1(game, window);
    display_2(game, window);
    for (int j = 0; j < bg->rows; j++)
        for (int i = 0; i < bg->cols; i++) {
            if (bg->map_2d[j][i] == 'T')
                square(window, bg->sprites[16], i * 40, j * 40);
            if (bg->map_2d[j][i] == 'S')
                square(window,
                bg->sprites[15], i * 40 - 20 + 40, j * 40 - 20 + 40);
            if (bg->map_2d[j][i] == 'E')
                square(window, bg->sprites[18], i * 40 - 20, j * 40);
        }
    display_towers(game);
    drawScene(game, game->scenes, 1);
    check_ui_hover(game);
    sfRenderWindow_display(window);
}