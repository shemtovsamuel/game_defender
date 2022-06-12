/*
** EPITECH PROJECT, 2020
** my_str_isprintable.c
** File description:
** is string printable?
*/

int my_str_isprintable(char const *str)
{
    int i = 0;
    int x = 0;

    while (str[i] != '\0') {
        if (str[i] >= ' ' && str[i] <= 127) {
            x = x + 1;
        }
        i++;
    }
    if (x == i) {
        return 1;
    }else {
        return 0;
    }
}
