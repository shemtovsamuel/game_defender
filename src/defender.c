/*
** EPITECH PROJECT, 2020
** utils.c
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
#include <stdio.h>

int defender(int argc, char **argv, game_t *game)
{
    init_sprites(game);
    init_sound(game);
    init_game(argc, argv, game);
    game_loop(game);
    return (0);
}