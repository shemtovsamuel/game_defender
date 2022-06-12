/*
** EPITECH PROJECT, 2020
** my_is_prime.c
** File description:
** my_is_prime
*/

int my_is_prime(int nb)
{
    int i = 5;

    if (nb <= 3){
        if (nb == 1 || nb == 0)
            return 0;
        else
            return 1;
    } else if (nb %2 == 0 || nb %3 == 0) {
        return 0;
    }
    while (i * i <= nb ) {
        if (nb %i == 0 || nb % (i + 2) == 0) {
            return 0;
        }
        i = i + 6;
    }
    return 1;
}
