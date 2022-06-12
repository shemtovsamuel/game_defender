/*
** EPITECH PROJECT, 2020
** my_str_isaplha.c
** File description:
** dzfgrhztnes
*/

int my_str_isalpha(char const *str)
{
    int i = 0;
    int x = 0;

    while (str[i] != '\0') {
        if (str[i] >= 'A' && str[i] <= 'Z'
            || str[i] >= 'a' && str[i] <= 'z') {
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
