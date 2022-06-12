/*
** EPITECH PROJECT, 2020
** my_strcpy.c
** File description:
** copy string
*/

#include <stddef.h>

char *my_strcpy(char *dest, char const *src)
{
    char *nul = NULL;
    int i = 0;
    int x = 0;

    while (src[i] != '\0') {
        i++;
    }
    while (x <= i){
        dest[x] = src[x];
        x++;
    }
    return (dest);
}
