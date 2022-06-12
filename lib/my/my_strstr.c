/*
** EPITECH PROJECT, 2020
** my_strstr.c
** File description:
** search sring in
*/

#include <stddef.h>

int my_strlen(const char *c);

int my_strncmp(char const *s1, char const *s2, int n);

char *my_strstr(char *str, char const *to_find)
{
    int i = 0;
    char *nul = NULL;
    int aiguille_length = my_strlen(to_find);

    while (str[i] != '\0') {
        if (my_strncmp(&str[i], to_find, aiguille_length) == 0)
            return (&str[i]);
        i++;
    }
    return (nul);
}
