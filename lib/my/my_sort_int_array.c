/*
** EPITECH PROJECT, 2020
** my_sort_int_array.c
** File description:
** my_sort_int_array
*/

void my_sort_int_array(int *array, int size)
{
    int temp = 0;
    int i = 0;

    while ( i != size ) {
        if (array[i] > array[i + 1]) {
            temp = array[i];
            array[i] = array[i + 1];
            array[i + 1] = temp;
            i = -1;
        }
        i = i + 1;
    }
}
