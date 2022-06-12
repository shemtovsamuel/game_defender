/*
** EPITECH PROJECT, 2020
** ui.h
** File description:
** prototypes of my lib
*/

#include <SFML/Graphics.h>
#include <stdlib.h>


#ifndef DEFENDER_H_
#define DEFENDER_H_
#define abs(x)  ( (x<0) ? -x : x )
#include "game.h"
#include "ui.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <math.h>
#include <unistd.h>

sfIntRect init_rect(void);
sfRenderWindow *my_create_window(int width, int height);
void volume(game_t *game);
void init_sound(game_t *game);
int find_index(int type);
int counter_rows(char *str);
int counter_cols(char *str);
int size_map (int argc, char **argv);
char **mem_char_2d_array(int rows, int cols);
float get_time(sfClock *clock);
char *load_map(int argc, char **argv);
char **str_to_2d(char const *str, int rows, int cols);
int check_number_slots(background_t *bg);
slots_t *init_slots(scene_s *scene);
void init_game(int argc, char **argv, game_t *game);
void init_sprites_1(game_t *game);
void init_sprites_2(game_t *game);
void init_sprites_3(game_t *game);
void init_sprites(game_t *game);
void square(sfRenderWindow *window, sfSprite *sprite, int x, int y);
void display_towers(game_t *game);
void check_ui_hover(game_t *game);
void display_1(game_t * game, sfRenderWindow *window);
void display_2(game_t * game, sfRenderWindow *window);
void display(game_t *game);
void click_tower(sfEvent event, game_t *game, int *placed, int type);
void tower_follow(game_t *game, int type);
void click_sell_tower(sfEvent event, game_t *game, int *placed);
void place_tower(game_t *game, int type);
void sell_follow(game_t *game);
void sell_tower(game_t *game, int type);
void check_ui(sfEvent event, button *button, game_t *game);
void event_management(sfEvent event, game_t *game);
sfVector2f find_spawner(game_t *game);
void move_enemy(enemy_t *current, sfVector2f off, game_t *game, sfVector2i pos);
void handle_enemy_movement(enemy_t *current, game_t *game);
void handle_enemies(game_t *game);
void clear_map(game_t *game);
void game_overclick(sfEvent *event, game_t *game, int *clicked);
void game_over(game_t *game);
void pause_click_2(sfVector2f click_pos, int *clicked);
void pause_click(sfEvent *event, game_t *game, int *clicked);
void pause_menu(game_t *game);
int check_enemy_collision(game_t *game, enemy_t *current, enemy_t *previous);
void check_life(game_t *game);
void turrets_attack(game_t *game, sfClock *clock);
void move_rect(sfIntRect *rect, int shifft, int max_value, sfClock *clock);
void anim_player(sfRenderWindow *window,
sfIntRect *rect, sfClock *clock, game_t *game);
void game_loop(game_t *game);
int defender(int argc, char **argv, game_t *game);
void check_life(game_t *game);
int distance_cal(sfVector2f a, sfVector2f b);
enemy_t *find_nearest(game_t *game, sfVector2f turpos,
    enemy_t *n_previous, sfVector2f *nearestpos);
void check_enemy_life(game_t *game, enemy_t *nearest, enemy_t *n_previous);
void shoot(game_t *game, enemy_t *nearest, enemy_t *n_previous, int i);
void check_turrets_attack(game_t *game);

#endif