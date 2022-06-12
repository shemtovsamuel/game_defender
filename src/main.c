/*
** EPITECH PROJECT, 2020
** main.c
** File description:
** prototypes of my lib
*/

#include <SFML/Graphics.h>
#include <SFML/Window/Event.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "../include/ui.h"
#include "../include/defender.h"
#include "../include/game.h"
#include "../include/my.h"
#include <stdio.h>

void menu(scene_s *gameScenes, game_t *game)
{
    sfRenderWindow *window = game->window;
    sfEvent event;
    int currentScene = 0;

    while (currentScene == 0) {
        my_handle_close_event(window, event, &gameScenes[currentScene]
        , &currentScene);

        drawScene(game, gameScenes, 0);
        sfRenderWindow_display(window);
    }
}

int *init_prices(void)
{
    int *prices = malloc(sizeof(int) * 5);

    prices[0] = 100;
    prices[1] = 250;
    prices[2] = 500;
    prices[3] = 200;
    prices[4] = 300;
    return (prices);
}

int main(int ac, char **av)
{
    game_t *game = malloc(sizeof(game_t));
    game->scenes = init_scenes();
    game->window = my_create_window(1920, 1080);
    game->life = 100;
    game->money = 400;
    game->prices = init_prices();

    if (ac != 2) {
        my_putstr("USAGE: ./my_defender [MAP_PATH]\n");
        return (84);
    }
    my_putstr("STARTUP\n");

    menu(game->scenes, game);

    defender(ac, av, game);

    sfRenderWindow_destroy(game->window);

    return 0;
}