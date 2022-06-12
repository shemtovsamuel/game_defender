/*
** EPITECH PROJECT, 2020
** undefined
** File description:
** size_map.c
*/

#include "../include/defender.h"

int counter_rows(char *str)
{
    int rows = 0;

    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == '\n') {
            rows++;
        }
    return (rows);
}

int counter_cols(char *str)
{
    int i = 0;

    while (str[i] != '\n')
        i++;
    return (i);
}

int size_map (int argc, char **argv)
{
    char c = 0;
    int fd = open(argv[1], O_RDONLY);
    int i = 0;

    while (read(fd, &c, 1) > 0) {
        i++;
    }
    return (i);
}