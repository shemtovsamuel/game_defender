/*
** EPITECH PROJECT, 2020
** my_copmpute_power_rec.c
** File description:
** compute power n
*/

int my_compute_power_rec(int nb, int p)
{
    int result = nb;
    if (p == 0) {
        return 1;
    }
    else if (p < 0) {
        return 0;
    }
    p = p - 1;
    result = nb * my_compute_power_rec (nb, p);
    return result;
}
