/*
** EPITECH PROJECT, 2020
** my_strcat
** File description:
** 'Concatenate 2 strings one after the other'
*/

char *my_strcat(char *dest, char const *src)
{
    int i = 0;
    int x = 0;

    while (dest[i] != '\0') {
        i++;
    }
    for ( ; src[x] != '\0'; x++) {
        dest[i + x] = src[x];
    }
    dest[i + x] = '\0';
    return dest;
}
