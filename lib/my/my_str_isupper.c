/*
** EPITECH PROJECT, 2020
** my_str_isupper.c
** File description:
** is string only uppercase ?
*/

int my_str_isupper(char const *str)
{
    int i = 0;
    int x = 0;

    while (str[i] != '\0') {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            x++;
        }
    i++;
    }
    if (x == i) {
        return 1;
    }else {
        return 0;
    }
}
