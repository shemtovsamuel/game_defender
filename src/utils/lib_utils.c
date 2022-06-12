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
#include <stdio.h>

sfRenderWindow *my_create_window(int width, int height)
{
    sfRenderWindow *window;
    sfVideoMode video_mode;

    video_mode.width = width;
    video_mode.height = height;
    video_mode.bitsPerPixel = 32;
    window = sfRenderWindow_create(video_mode,
    "MY_DEFENDER", sfDefaultStyle, NULL);
    sfRenderWindow_setFramerateLimit(window, 60);
    return window;
}

void check_buttons(sfEvent event, button *button, int *current)
{
    game_t *game = NULL;
    sfVector2f pos;
    sfVector2f click_pos;
    click_pos.x = event.mouseButton.x;
    click_pos.y = event.mouseButton.y;
    
    for (int i = 0; button[i].sprite != NULL; i++) {
        if (button_is_clicked(button[i], click_pos)) {
            pos = sfSprite_getPosition(button[i].sprite);
            if (pos.y == 420) {
                *current = 1;
            } else if (pos.y > 740) {
                button->callback(game, 0);
            } else {
                button->callback(game, 0);
            }
        }
    }
}

void check_hover(sfRenderWindow *window, scene_s *scene)
{
    static int state = 0;
    sfVector2i click_pos = sfMouse_getPositionRenderWindow(window);
    sfVector2f pos;
    sfVector2f size;
    size.x = 154;
    size.y = 112;

    create_background(scene, size, 1, "images/23.png");
    scene->objs[1].hidden = 1;
    scene->objs[2].sprite = NULL;
    sfSprite_setScale(scene->objs[1].sprite, (sfVector2f){1.5, 1});

    for (int i = 0; scene->buttons[i].sprite != NULL; i++) {
        if (button_is_clicked(scene->buttons[i],
        (sfVector2f){click_pos.x, click_pos.y + 20})
        && state == 0) {
            pos = sfSprite_getPosition(scene->buttons[i].sprite);
            pos.x = (1920 / 2) - 52;
            pos.y -= 13;
            sfSprite_setPosition(scene->objs[1].sprite, pos);
            scene->objs[1].hidden = 0;
        }
    }
}

void my_handle_close_event(sfRenderWindow *window, sfEvent event,
 scene_s *scene, int *current)
{
    check_hover(window, scene);
    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
        }
        if (event.type == sfEvtMouseButtonPressed) {
            if (event.mouseButton.button == sfMouseLeft) {
                check_buttons(event, scene->buttons, current);
            }
        }
}