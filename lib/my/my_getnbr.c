/*
** EPITECH PROJECT, 2020
** my_getnbr
** File description:
** my_getnbr
*/

int	my_getnbr(char *str)
{
    int	nb, neg, i;

    neg = 1;
    nb = 0;
    i = 0;
    while (str[i] == '+' || str[i] == '-') {
        if (str[i] == '-')
            i = i + 1;
            neg = neg * -1;
    }
    while (str[i] != '\0') {
        if (str[i] >= '0' && str[i] <= '9') {
            nb = nb * 10;
            nb = nb + str[i] - '0';
            i = i + 1;
        }
        else
            return (neg * nb);
    }
    return (nb * neg);
}
