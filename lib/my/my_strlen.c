/*
** EPITECH PROJECT, 2020
** my_strlen.c
** File description:
** Concatenate 2 strings one after the other for n characters
*/

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }
    return i;
}
