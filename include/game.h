  /*
** EPITECH PROJECT, 2020
** game.h
** File description:
** prototypes of my lib
*/

#include "defender.h"
#include "sound.h"
#include <SFML/Audio.h>

#ifndef GAME_H_
#define GAME_H_

typedef struct specs_t specs_t;
struct specs_t {
    int damage;
    int range;
};

typedef struct slots_t slots_t;
struct slots_t {
    sfVector2i pos;
    int type;

};

typedef struct background_t background_t;
struct background_t {
    sfVector2f end_pos;
    specs_t *slot_specs;
    slots_t *slots;
    sfSprite **sprites;
    int distance;
    int cols;
    int rows;
    char *str;
    char **map_2d;
    int x_mouse;
    int y_mouse;
};

typedef struct enemy_t enemy_t;
struct enemy_t {
    int health;
    sfSprite *sprite;
    sfVector2i anim;
    int hidden;
    enemy_t *next;
};

typedef struct enemy_l enemy_l;
struct enemy_l {
    enemy_t *first;
};

typedef struct scene_s scene_s;
struct scene_s {
    enemy_l *enemy_list;
    background_t *background;
    struct game_object_s *objs;
    enemy_t *enemies;
    struct button *buttons;
};

typedef struct game_s game_t;
struct game_s{
    int *prices;
    int life;
    int money;
    scene_s *scenes;
    sfRenderWindow *window;
    sfClock *clock;
    sfSoundBuffer **sound_buffers;
    sfSound **sounds;
};

typedef struct game_object_s game_object_s;
struct game_object_s{
    int health;
    const sfImage *image;
    sfTexture *texture;
    sfSprite *sprite;
    sfIntRect rect;
    sfVector2i anim;
    int hidden;
};

sfText *init_money_text(game_t *game);
void draw_money(game_t *game);
char * itoa(int i, char b[]);
void draw_lifebar(sfRenderWindow *window,
background_t *bg, int life, sfVector2f background_pos);
void draw_enemies(sfRenderWindow *window, scene_s *scenes, int current_scene);
void menu(scene_s *gameScenes, game_t *game);

void place_tower(game_t *game, int type);
void sell_tower(game_t *game, int type);


void my_handle_close_event(sfRenderWindow *window, sfEvent event,
scene_s *scene, int *);
int defender(int argc, char **argv, game_t *game);
void drawScene(game_t *game, scene_s *scenes, int current_scene);
void create_background(scene_s *scenes, sfVector2f size, int i, char *path);

void square(sfRenderWindow *window, sfSprite *sprite, int x, int y);


enemy_l *init_enemy_list();
int init_enemy(enemy_l *liste, sfSprite *sprite);
int print_list(enemy_l *list);
int get_list_length(enemy_l *l_a);

scene_s *init_scenes();
#endif