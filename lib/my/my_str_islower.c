/*
** EPITECH PROJECT, 2020
** my_str_islower.c
** File description:
** efgrzhs
*/

int my_str_islower(char const *str)
{
    int i = 0;
    int x = 0;

    while (str[i] != '\0') {
        if (str[i] >= 'a' && str[i] <= 'z'){
            x = x + 1;
        }
        i = i + 1;
    }
    if (x == i) {
        return 1;
    }else {
        return 0;
    }
}
