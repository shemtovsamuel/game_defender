/*
** EPITECH PROJECT, 2020
** my_compute_square_root.c
** File description:
** square root
*/

int my_compute_square_root(int nb)
{
    int count = 0;

    if (nb < 0 || nb == 0) {
        return (0);
    } else {
        while (count * count != nb) {
            count = count + 1;
            if (count > nb) {
                return (0);
            }
        }
    }
    return (count);
}
