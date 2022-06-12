/*
** EPITECH PROJECT, 2020
** my_str_to_word_array
** File description:
** convert words into an array of words
*/

#include <stddef.h>
#include <stdlib.h>

int my_strlen(char const *str);

int my_isalphanum(char c)
{
    int x = 0;

    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
        return (1);
    else if (c >= '0' && c <= '9') {
        return (1);
    } else {
        return (0);
    }
}

int get_word_length(char const *src, int index)
{
    int f = 0;

    for ( ; my_isalphanum(src[index]) == 1; f++) {
        index++;
    }
}

int get_number_of_words(char const *str, int length)
{
    int i = 0;
    int x = 0;
    while (i <= length) {
        if (my_isalphanum(str[i]) == 1) {
            x++;
        }
        while (my_isalphanum(str[i]) == 1 && i <= length) {
            i++;
        }
        if (i <= length)
            i++;
    }
    return x;
}

char **my_str_to_word_array(char const *str)
{
    int i = 0, x = 0, word_index = 0, length = my_strlen(str);
    char **final = NULL;

    final = malloc(sizeof(char *) * (get_number_of_words(str, length) + 1));
    while (word_index < get_number_of_words(str, length)) {
        x = 0;
        while (my_isalphanum(str[i]) == 0) {
            i++;
        }
        final[word_index] = malloc(sizeof(char) *
        (get_word_length(str, i) + 1));
        while (my_isalphanum(str[i]) == 1) {
            final[word_index][x] = str[i];
            i++;
            x++;
        }
        final[word_index][x] = '\0';
        word_index++;
    }
    final[word_index] = NULL;
    return (final);
}
