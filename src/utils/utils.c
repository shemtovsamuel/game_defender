/*
** EPITECH PROJECT, 2020
** utils.c
** File description:
** prototypes of my lib
*/

#include <SFML/Graphics.h>

sfVector2f my_create_sfVector2f(float x, float y)
{
    sfVector2f vector;
    vector.x = x;
    vector.y = y;
    return vector;
}

sfVector2i my_create_sfVector2i(int x, int y)
{
    sfVector2i vector;
    vector.x = x;
    vector.y = y;
    return vector;
}

sfColor my_create_Color(char r, char g, char b, char a)
{
    sfColor color;
    color.r = r;
    color.g = g;
    color.b = b;
    color.a = a;
    return color;
}
