/*
** EPITECH PROJECT, 2020
** my_isalpha.c
** File description:
** zfggA
*/

int my_isalpha(char const c)
{
    if (c >= 'a' && c <= 'z' || c >= 'A')
        return (1);
    else
        return (0);
}
