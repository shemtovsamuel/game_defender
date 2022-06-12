/*
** EPITECH PROJECT, 2020
** undefined
** File description:
** init_sprite.c
*/

#include "../include/defender.h"

void init_sprites_1(game_t *game)
{
    background_t *bg = game->scenes[1].background;
    sfTexture *a = sfTexture_createFromFile("images/1.png", NULL);
    sfTexture *b = sfTexture_createFromFile("images/2.png", NULL);
    sfTexture *c = sfTexture_createFromFile("images/3.png", NULL);
    sfTexture *d = sfTexture_createFromFile("images/4.png", NULL);
    sfTexture *e = sfTexture_createFromFile("images/5.png", NULL);
    sfTexture *f = sfTexture_createFromFile("images/6.png", NULL);
    sfTexture *g = sfTexture_createFromFile("images/7.png", NULL);
    sfTexture *h = sfTexture_createFromFile("images/8.png", NULL);
    sfTexture *i = sfTexture_createFromFile("images/9.png", NULL);
    sfSprite_setTexture(bg->sprites[1], a, sfFalse);
    sfSprite_setTexture(bg->sprites[2], b, sfFalse);
    sfSprite_setTexture(bg->sprites[3], c, sfFalse);
    sfSprite_setTexture(bg->sprites[4], d, sfFalse);
    sfSprite_setTexture(bg->sprites[5], e, sfFalse);
    sfSprite_setTexture(bg->sprites[6], f, sfFalse);
    sfSprite_setTexture(bg->sprites[7], g, sfFalse);
    sfSprite_setTexture(bg->sprites[8], h, sfFalse);
    sfSprite_setTexture(bg->sprites[9], i, sfFalse);

}

void init_sprites_2(game_t *game)
{
    background_t *bg = game->scenes[1].background;
    sfTexture *j = sfTexture_createFromFile("images/10.png", NULL);
    sfTexture *k = sfTexture_createFromFile("images/11.png", NULL);
    sfTexture *l = sfTexture_createFromFile("images/12.png", NULL);
    sfTexture *m = sfTexture_createFromFile("images/13.png", NULL);
    sfTexture *n = sfTexture_createFromFile("images/14.png", NULL);
    sfTexture *o = sfTexture_createFromFile("images/15.png", NULL);
    sfTexture *p = sfTexture_createFromFile("images/16.png", NULL);
    sfTexture *q = sfTexture_createFromFile("images/17.png", NULL);
    sfTexture *r = sfTexture_createFromFile("images/18.png", NULL);
    sfSprite_setTexture(bg->sprites[10], j, sfFalse);
    sfSprite_setTexture(bg->sprites[11], k, sfFalse);
    sfSprite_setTexture(bg->sprites[12], l, sfFalse);
    sfSprite_setTexture(bg->sprites[13], m, sfFalse);
    sfSprite_setTexture(bg->sprites[14], n, sfFalse);
    sfSprite_setTexture(bg->sprites[15], o, sfFalse);
    sfSprite_setTexture(bg->sprites[16], p, sfFalse);
    sfSprite_setTexture(bg->sprites[17], q, sfFalse);
    sfSprite_setTexture(bg->sprites[18], r, sfFalse);
    sfSprite_setOrigin(game->scenes[1].background->sprites[15],
    (sfVector2f){40, 40});
}

void init_sprites_3(game_t *game)
{
    background_t *bg = game->scenes[1].background;
    sfTexture *s = sfTexture_createFromFile("images/lifebar.png", NULL);
    sfTexture *t = sfTexture_createFromFile("images/cancel_tower.png", NULL);
    sfTexture *u = sfTexture_createFromFile("images/sell.png", NULL);
    sfTexture *x = sfTexture_createFromFile("images/heal.png", NULL);
    sfTexture *y = sfTexture_createFromFile("images/slow.png", NULL);
    sfTexture *two = sfTexture_createFromFile("images/27.png", NULL);
    sfTexture *three = sfTexture_createFromFile("images/28.png", NULL);
    sfTexture *hover = sfTexture_createFromFile
    ("images/menu_buy/hover.png", NULL);
    sfSprite_setTexture(bg->sprites[19], s, sfFalse);
    sfSprite_setTexture(bg->sprites[20], t, sfFalse);
    sfSprite_setTexture(bg->sprites[21], u, sfFalse);
    sfSprite_setTexture(bg->sprites[24], x, sfFalse);
    sfSprite_setTexture(bg->sprites[25], y, sfFalse);
    sfSprite_setTexture(bg->sprites[26], two, sfFalse);
    sfSprite_setTexture(bg->sprites[27], three, sfFalse);
    sfSprite_setTexture(bg->sprites[28], hover, sfFalse);
}

void init_sprites(game_t *game)
{
    background_t *bg = game->scenes[1].background;
    bg->sprites = malloc(sizeof(*bg->sprites) * 35);
    for (int i = 0; i < 35; i++)
        bg->sprites[i] = sfSprite_create();
    init_sprites_1(game);
    init_sprites_2(game);
    init_sprites_3(game);
    sfTexture *neg = sfTexture_createFromFile("images/menu_buy/hover_neg.png", NULL);
    sfTexture *hov = sfTexture_createFromFile("images/turret_hover.png", NULL);
    sfTexture *gmo = sfTexture_createFromFile("images/menu_game_over.png", NULL);
    sfTexture *pause = sfTexture_createFromFile("images/menu_pause.png", NULL);
    sfTexture *enemy = sfTexture_createFromFile("images/target.png", NULL);
    sfSprite_setTexture(bg->sprites[29], neg, sfFalse);
    sfSprite_setTexture(bg->sprites[30], hov, sfFalse);
    sfSprite_setTexture(bg->sprites[31], gmo, sfFalse);
    sfSprite_setTexture(bg->sprites[32], pause, sfFalse);
    sfSprite_setTexture(bg->sprites[33], enemy, sfFalse);
}