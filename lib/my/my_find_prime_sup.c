/*
** EPITECH PROJECT, 2020
** my_find_prime_sup.c
** File description:
** my_find_prime_sup for nb
*/

int my_is_prime(int nb);

int my_find_prime_sup(int nb)
{
    int found = 0;
    int i = nb;

    while (found != 1) {
        if (my_is_prime(i) == 1) {
            found = 1;
        } else
            i = i + 1;
    }
    return i;
}
