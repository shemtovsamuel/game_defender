/*
** EPITECH PROJECT, 2020
** my_revstr.c
** File description:
** reverse a string
*/

char *my_revstr(char *str)
{
    int i = 0;
    int char_count = 0;
    int t = 0;

    while (str[char_count] != '\0'){
        char_count++;
    }
    char_count--;
    while (i < char_count)
    {
        t = str[i];
        str[i] = str[char_count];
        str[char_count] = t;
        char_count--;
        i++;
    }
    return (str);
}
