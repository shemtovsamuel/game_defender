/*
** EPITECH PROJECT, 2020
** undefined
** File description:
** sound.c
*/

#include "../include/defender.h"

void volume(game_t *game)
{
    sfSound_setVolume(game->sounds[e_music], 40);
    sfSound_setVolume(game->sounds[e_sell], 50);
    sfSound_setVolume(game->sounds[e_laser], 10);
    sfSound_setVolume(game->sounds[e_game_over], 40);
    sfSound_setVolume(game->sounds[e_heal], 40);
    sfSound_setVolume(game->sounds[e_tower], 40);
}

void init_sound(game_t *game)
{
    game->sounds = malloc(sizeof(*game->sounds) * e_nb_sounds);
    for (int i = 0; i < e_nb_sounds; i++)
        game->sounds[i] = sfSound_create();
    game->sound_buffers = malloc(sizeof(*game->sound_buffers) * e_nb_sounds);
    game->sound_buffers[e_music] = sfSoundBuffer_createFromFile("sounds/music.wav");
    game->sound_buffers[e_click] = sfSoundBuffer_createFromFile("sounds/click.wav");
    game->sound_buffers[e_laser] = sfSoundBuffer_createFromFile("sounds/laser.wav");
    game->sound_buffers[e_sell] = sfSoundBuffer_createFromFile("sounds/sell.wav");
    game->sound_buffers[e_game_over] = sfSoundBuffer_createFromFile("sounds/game_over.wav");
    game->sound_buffers[e_heal] = sfSoundBuffer_createFromFile("sounds/heal.wav");
    game->sound_buffers[e_tower] = sfSoundBuffer_createFromFile("sounds/tower.wav");
    sfSound_setBuffer(game->sounds[e_click], game->sound_buffers[e_click]);
    sfSound_setBuffer(game->sounds[e_music], game->sound_buffers[e_music]);
    sfSound_setBuffer(game->sounds[e_laser], game->sound_buffers[e_laser]);
    sfSound_setBuffer(game->sounds[e_sell], game->sound_buffers[e_sell]);
    sfSound_setBuffer(game->sounds[e_game_over], game->sound_buffers[e_game_over]);
    sfSound_setBuffer(game->sounds[e_heal], game->sound_buffers[e_heal]);
    sfSound_setBuffer(game->sounds[e_tower], game->sound_buffers[e_tower]);
    volume(game);
}