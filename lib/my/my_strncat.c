/*
** EPITECH PROJECT, 2020
** my_strncat.c
** File description:
** ..
*/

char *my_strncat(char *dest, char const *src, int nb)
{
    int i = 0;
    int x = 0;
    while (dest[i] != '\0') {
        i++;
    }
    for ( ; src[x] != '\0' && x < nb; x++) {
        dest[i + x] = src[x];
    }
    dest[i + x] = '\0';
    return dest;
}
