/*
** EPITECH PROJECT, 2020
** my_strdup
** File description:
** aloocate memory for a string and return the copy
*/

#include <stdlib.h>

int my_strlen(char const *str);

char *my_strdup(char *src)
{
    char *final;
    int i = 0;
    int length = my_strlen(src);

    final = malloc(sizeof(char) * length);
    while (i <= length) {
        final[i] = src[i];
        i++;
    }
    return (final);
}
