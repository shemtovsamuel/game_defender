/*
** EPITECH PROJECT, 2020
** my_strupcase.c
** File description:
** STRUP
*/

char *my_strupcase(char *str)
{
    int i = 0;

    while (str[i] != '\0'){
        if (str[i] < 123 && str[i] > 96)
            str[i] = str[i] - 32;
        i++;
    }
    return (str);
}
