/*
** EPITECH PROJECT, 2020
** concat_params.c
** File description:
** put all parameters on one string divided by '\O's
*/

#include <stdlib.h>
char *my_strcat(char *dest, char const *src);
char *my_strdup(char const *src);
int my_strlen(char const *str);

char *concat_params(int argc, char **argv)
{
    int total_length = 0;
    char *new;
    int i = 0;

    while (i < argc) {
        total_length = (total_length + my_strlen(argv[i]) + 1);
        i++;
    }
    i = 0;
    new = malloc(sizeof(char) * total_length);
    while (i < argc) {
        my_strcat(new, argv[i]);
        if (i == argc - 1) {
            my_strcat(new, "\0");
        }else
            my_strcat(new, "\n");
        i++;
    }
    return (new);
}
