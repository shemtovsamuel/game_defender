/*
** EPITECH PROJECT, 2020
** my_show_word_array
** File description:
** display array of words
*/

#include <stddef.h>

int my_putstr(char const *str);

int my_show_word_array(char * const *tab)
{
    int i = 0;

    while (tab[i] != NULL) {
        my_putstr(tab[i]);
        my_putstr("\n");
        i++;
    }
    return (1);
}
