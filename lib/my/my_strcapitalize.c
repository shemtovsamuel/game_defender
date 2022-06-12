/*
** EPITECH PROJECT, 2020
** my_strcapitalize.c
** File description:
** 'Capitalize every first letter of each word in the str string'
*/

int check_previous_char(char c)
{
    if (c >= ' ' && c <= '/') {
        return (1);
    }else
        return (0);
}

void check_lowercase_char(char *str, int i)
{
    if (i == 0) {
        str[i] = str[i] - 32;
    }
    else if (check_previous_char(str[i - 1]) == 1) {
        str[i] = str[i] - 32;
    }
}

void check_uppercase_char(char *str, int i)
{
    if (i == 0) {
        return;
    }
    else if (check_previous_char(str[i - 1]) == 0) {
        str[i] = str[i] + 32;
    }
}

char *my_strcapitalize(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] >= 'a' && str[i] <= 'z')
            check_lowercase_char(str, i);
        if (str[i] >= 'A' && str[i] <= 'Z')
            check_uppercase_char(str, i);

        i++;
    }
    return (str);
}
