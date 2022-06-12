/*
** EPITECH PROJECT, 2020
** ui.h
** File description:
** prototypes of my lib
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "game.h"

#ifndef UI_H_
#define UI_H_

typedef struct button button;
struct button{
    sfFont *font;
    sfText *text;
    const sfImage *image;
    sfTexture *texture;
    sfSprite *sprite;
    sfIntRect rect;
    sfVector2i state;
    void (*callback)(game_t *game, int type);
};

void init_button(button *button, sfVector2f position,
sfVector2f size, char *);
int button_is_clicked(button button, sfVector2f click_pos);
void check_buttons(sfEvent event, button *button, int *current);

void init_font(button *button, char *name);

sfVector2f my_create_sfVector2f(float x, float y);
sfVector2i my_create_sfVector2i(int x, int y);
sfColor my_create_Color(char r, char g, char b, char a);


#endif