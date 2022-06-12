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
#include "../../include/ui.h"
#include "../../include/game.h"
#include "../../include/my.h"
#include <stdio.h>


void drawScene(game_t *game, scene_s *scenes, int current_scene)
{
    sfRenderWindow *window = game->window;
    scene_s *scene = &scenes[current_scene];
    sfVector2f lifePos;
    enemy_t *current;

    if (current_scene == 0)
        sfRenderWindow_clear(window, sfBlack);


    for (int i = 0; scene->objs[i].sprite != NULL; i++) {
        if (scene->objs[i].hidden != 1)
            sfRenderWindow_drawSprite(window, scene->objs[i].sprite, NULL);
    }
    
    for (int i = 0; scene->buttons[i].sprite != NULL; i++) {
        sfRenderWindow_drawSprite(window, scene->buttons[i].sprite, NULL);
    }  
    if (current_scene == 1) {
        lifePos = scenes[current_scene].background->end_pos;
        draw_enemies(window, scenes, current_scene);
        draw_lifebar(window, scenes[current_scene].background, game->life, 
            (sfVector2f){lifePos.x, lifePos.y - 20});
        draw_money(game);
    }
    
}

void create_background(scene_s *scenes, sfVector2f size, int i, char *path)
{
    scenes->objs[i].hidden = 0;
    scenes->objs[i].rect.top = 0;
    scenes->objs[i].rect.left = 0;
    scenes->objs[i].rect.height = size.x;
    scenes->objs[i].rect.width = size.y;
    scenes->objs[i].image = sfImage_createFromFile(path);
    scenes->objs[i].sprite = sfSprite_create();
    scenes->objs[i].texture = sfTexture_createFromImage(scenes->objs[i].image, &scenes->objs[i].rect);
    sfTexture_setRepeated(scenes->objs[i].texture, sfFalse);
    sfSprite_setTexture(scenes->objs[i].sprite, scenes->objs[i].texture, sfTrue);
    sfSprite_setTextureRect(scenes->objs[i].sprite, scenes->objs[i].rect);
}

void init_menu(scene_s *gameScenes)
{
    button *buttons = malloc(sizeof(button) * 4);

    init_button(&buttons[0], (sfVector2f){847, 420},
    (sfVector2f){300, 88}, "images/20.png");
    init_button(&buttons[1],  (sfVector2f){797, 582},
    (sfVector2f){400, 88}, "images/21.png");
    init_button(&buttons[2],  (sfVector2f){863, 743},
    (sfVector2f){255, 88}, "images/22.png");
    gameScenes[0].objs = malloc(sizeof(game_object_s) * 3);
    gameScenes[0].buttons = buttons;
    gameScenes[0].buttons[3].sprite = NULL;
    create_background(gameScenes, (sfVector2f){1920, 2000},
    0, "images/19.png");
    printf("...\n");
    gameScenes[0].objs[1].sprite = NULL;
    gameScenes[0].enemy_list = NULL;
}

void init_specs(scene_s *scenes)
{
    scenes[1].background = malloc(sizeof(background_t));

    background_t *bg = scenes[1].background;
    scenes[1].background->slot_specs = malloc(sizeof(specs_t) * 5);
    bg->slot_specs[0].damage = 8;
    bg->slot_specs[0].range = 250;
    bg->slot_specs[1].damage = 15;
    bg->slot_specs[1].range = 250;
    bg->slot_specs[2].damage = 20;
    bg->slot_specs[2].range = 300;
    bg->slot_specs[3].damage = 0;
    bg->slot_specs[3].range = 0;
    bg->slot_specs[4].damage = 0;
    bg->slot_specs[4].range = 300;
}

void init_game_scene(scene_s *gameScenes)
{
    button *buttons = malloc(sizeof(button) * 7);
    init_button(&buttons[0], (sfVector2f){1360, 250},
    (sfVector2f){447, 84}, "images/menu_buy/level_1.png");
    buttons[0].callback = &place_tower;
    init_button(&buttons[1],  (sfVector2f){1360, 380},
    (sfVector2f){447, 84}, "images/menu_buy/level_2.png");
    buttons[1].callback = &place_tower;
    init_button(&buttons[2],  (sfVector2f){1360, 510},
    (sfVector2f){447, 84}, "images/menu_buy/level_3.png");
    buttons[2].callback = &place_tower;
    init_button(&buttons[3],  (sfVector2f){1360, 640},
    (sfVector2f){447, 84}, "images/menu_buy/heal.png");
    buttons[3].callback = &place_tower;
    init_button(&buttons[4],  (sfVector2f){1360, 770},
    (sfVector2f){447, 84}, "images/menu_buy/slow.png");
    buttons[4].callback = &place_tower;
    init_button(&buttons[5],  (sfVector2f){1330, 125},
    (sfVector2f){80, 80}, "images/menu_buy/sell.png");
    buttons[5].callback = &sell_tower;
    gameScenes[1].objs = malloc(sizeof(game_object_s) * 4);
    gameScenes[1].buttons = buttons;
    gameScenes[1].buttons[6].sprite = NULL;
    gameScenes[1].objs[3].sprite = NULL;
    gameScenes[1].enemy_list = init_enemy_list();
    create_background(gameScenes + 1, (sfVector2f){880, 560},
    0, "images/menu_buy/background.png");
    sfSprite_setPosition(gameScenes[1].objs[0].sprite, (sfVector2f){1300, 80});
    create_background(gameScenes + 1, (sfVector2f){85, 292},
    1, "images/menu_buy/bulle.png");
    sfSprite_setPosition(gameScenes[1].objs[1].sprite, (sfVector2f){1434, 119});
    init_specs(gameScenes);
    create_background(gameScenes + 1, (sfVector2f){80, 80},
    2, "images/target.png");
    sfSprite_setPosition(gameScenes[1].objs[2].sprite, (sfVector2f){2000, 1100});
}

scene_s *init_scenes()
{
    scene_s *gameScenes = malloc(sizeof(scene_s) * 4);

    init_menu(gameScenes);
    init_game_scene(gameScenes);
    
    return (gameScenes);
}