/*
** EPITECH PROJECT, 2020
** my_put_nbr
** File description:
** ptzrg
*/

void my_putchar(char c);

int my_put_nbr(int nb)
{
    int	temp;

    if (nb < 0) {
        my_putchar('-');
        nb = nb * (-1);
    }
    if (nb >= 0) {
        if (nb >= 10) {
            temp = (nb % 10);
            nb = (nb - temp) / 10;
            my_put_nbr(nb);
            my_putchar('0' + temp);
        } else
            my_putchar('0' + nb % 10);
    }
}
