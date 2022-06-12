/*
** EPITECH PROJECT, 2020
** my_showstr.c
** File description:
** show strings splus quoi
*/

void my_putchar(char c);

int my_putstr(char const *str);

int my_strlen(char const *str);

char *my_revstr(char *str);

int my_putnbr_base(int nbr, char const *base)
{
    int baseLength = my_strlen(base);
    int i = 0;
    char converted[50] = {0};
    int res = nbr;
    int remainder = 0;

    while (res != 0) {
        remainder = res % baseLength;
        res = res / baseLength;
        converted[i] = base[remainder];
        my_putchar('\\');
        my_putchar('0');
        my_putchar(converted[i]);
        i++;
    }
    converted[i] = '\0';
}

int my_showstr(char const *str)
{
    int i  = 0;

    while (str[i] != '\0') {
        if (str[i] >= 0 && str[i] <= 31) {
            my_putnbr_base(str[i], "0123456789abcdef");
        }else {
            my_putchar(str[i]);
        }
    i++;
    }
    return 0;
}
