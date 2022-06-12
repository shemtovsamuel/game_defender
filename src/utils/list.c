/*
** EPITECH PROJECT, 2020
** undefined
** File description:
** enemy_l.c
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


enemy_l *init_enemy_list()
{
    enemy_l *list = malloc(sizeof(list));
    if (list == NULL)
    {
        exit(84);
    }
    
    list->first = NULL;

    return list;
}

int init_enemy(enemy_l *liste, sfSprite *sprite)
{
    enemy_t *new = malloc(sizeof(*new));

    if (liste == NULL || new == NULL)
        return(84);
    new->health = 100;
    new->hidden = 0;
    new->sprite = sprite;
    new->next = liste->first;
    liste->first = new;
    return (0);
}

int get_list_length(enemy_l *l_a)
{
    enemy_t *current = NULL;
    int length = 0;

    if (l_a->first != NULL)
        current = l_a->first;
    else 
        return (0);
    while (current != NULL) {
        length++;
        current = current->next;
    }
    return length;
}