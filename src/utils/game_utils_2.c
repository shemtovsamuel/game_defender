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

sfText *init_money_text(game_t *game)
{
    sfVector2f pos = (sfVector2f){1500, 125};
    sfFont *font = sfFont_createFromFile("./fonts/Oakle.ttf");
    sfText *text = sfText_create();
    sfColor color = sfColor_fromRGB(10, 38, 63);
    char name[10];
    char *str = itoa(game->money, name+1);

    name[0] = '$';
    sfText_setString(text, name);
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 60);
    sfText_setPosition(text, pos);
    sfText_setColor(text, color);
    return (text);
}

void draw_money(game_t *game)
{
    sfText *text = init_money_text(game);
    sfRenderWindow_drawText(game->window, text, NULL);
}

char* itoa(int i, char b[])
{
    char const digit[] = "0123456789";
    char* p = b;
    if(i<0){
        *p++ = '-';
        i *= -1;
    }
    int shifter = i;
    do{ //Move to where representation ends
        ++p;
        shifter = shifter/10;
    }while(shifter);
    *p = '\0';
    do{ //Move back, inserting digits as u go
        *--p = digit[i%10];
        i = i/10;
    }while(i);
    return b;
}


void draw_lifebar(sfRenderWindow *window, background_t *bg, int life, sfVector2f background_pos)
{
    float delta;
    sfIntRect temp;
    temp.top = 0,
    temp.left = 0;
    temp.height = 10;
    temp.width = 0;

    delta = (40.0 / 100.0) * (float)life;
    temp.width = (int)delta;

    sfSprite_setTextureRect(bg->sprites[19], temp);
    sfSprite_setPosition(bg->sprites[19], background_pos);
    sfRenderWindow_drawSprite(window, bg->sprites[19], NULL);
}

void draw_enemies(sfRenderWindow *window, scene_s *scenes, int current_scene)
{
    scene_s *scene = &scenes[current_scene];
    enemy_t *current;

    if (scenes[current_scene].enemy_list->first != NULL) {
        current = scenes[current_scene].enemy_list->first;
        while (current != NULL) {
            sfVector2f background_pos = sfSprite_getPosition(current->sprite);
            background_pos.y -= 20;
            draw_lifebar(window, scenes[current_scene].background, current->health, background_pos);
            sfRenderWindow_drawSprite(window, current->sprite, NULL);
            current = current->next;
        }
    }
}
