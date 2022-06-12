/*
** EPITECH PROJECT, 2020
** button.c
** File description:
** prototypes of my lib
*/

#include <SFML/Graphics.h>
#include "../../include/ui.h"
#include "../../include/game.h"
#include <stdio.h>

void start_game(game_t *game)
{
    exit(0);
}

void init_font(button *button, char *name)
{
    sfVector2f pos = sfSprite_getPosition(button->sprite);
    pos.x += 75;
    button->font = sfFont_createFromFile("./fonts/deadly.ttf");
    button->text = sfText_create();
    sfText_setString(button->text, name);
    sfText_setFont(button->text, button->font);
    sfText_setCharacterSize(button->text, 50);
    sfText_setPosition(button->text, pos);
    sfText_setColor(button->text, sfBlack);
}

void init_button(button *button, sfVector2f position, sfVector2f size, char *path)
{
    button->rect.top = 0;
    button->rect.left = 0;
    button->rect.height = size.y;
    button->rect.width = size.x;
    button->image = sfImage_createFromFile(path);
    button->sprite = sfSprite_create();
    button->texture = sfTexture_createFromImage(button->image, &button->rect);
    sfTexture_setRepeated(button->texture, sfFalse);
    sfSprite_setTexture(button->sprite, button->texture, sfTrue);
    sfSprite_setTextureRect(button->sprite, button->rect);
    sfVector2f scale = my_create_sfVector2f(1, 1);
    sfSprite_setScale(button->sprite, scale);
    sfSprite_setPosition(button->sprite, position);
    button->callback = &start_game;
}

int button_is_clicked(button button, sfVector2f click_pos)
{
    sfVector2f button_pos = sfSprite_getPosition(button.sprite);
    sfVector2f button_size = my_create_sfVector2f(button.rect.width, button.rect.height);

    if (click_pos.x >= button_pos.x &&
        click_pos.x <= button_pos.x + button_size.x) {
        if (click_pos.y >= button_pos.y &&
        click_pos.y <= button_pos.y + button_size.y) {
            return (1);
        }
    }
    return (0);
}