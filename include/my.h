/*
** EPITECH PROJECT, 2020
** my.h
** File description:
** prototypes of my lib
*/
#ifndef MY_H_
#define MY_H_
void my_putchar(char);
int get_number_of_words(char const *, int );
int get_word_length(char const *, int );
int my_putnbr_base(int, char const *);
int check_previous_char(char c);
void check_uppercase_char(char *, int );
void check_lowercase_char(char *, int );
char *concat_params(int , char **);
int my_isneg(int);
int my_put_nbr(int);
void my_swap(int *, int *);
int my_putstr(char const *);
char *my_strcapitalize(char *str);
int my_strlen(char const *);
int my_getnbr(char const *);
void my_sort_int_array(int *, int);
int my_isalphanum(char );
int my_compute_power_rec(int, int);
int my_compute_square_root(int);
int my_is_prime(int);
int my_str_isalpha(char const *);
int my_find_prime_sup(int);
char *my_strcpy(char *, char const *);
char *my_strncpy(char *, char const *, int);
char *my_revstr(char *);
char *my_strstr(char *, char const *);
int my_strcmp(char const *, char const *);
int my_strncmp(char const *, char const *, int);
char *my_strupcase(char *);
char *my_strlowcase(char *);
char *my_capitalize(char *);
int my_isalpha(char const *);
int my_str_isnum(char const *);
int my_str_islower(char const *);
int my_str_isupper(char const *);
int my_str_isprintable(char const *);
char **my_str_to_word_array(char const *);
int my_showstr(char const *);
int my_showmem(char const *, int);
int my_show_word_array(char * const *);
char *my_strcat(char *, char const *);
char *my_strncat(char *, char const *, int);
char *my_strdup(char const *);
char *calc_neg(char *str1, char *str2, char *result, int reste);
void check_finished(int *nb1, int *nb2, char *str1, char *str2, int i);
void check_neg(char **str1, char **str2, int *is_neg1, int *is_neg2);
void clean_zeros(char *result);
int compare (char *str1, char *str2);
void swap_and_sign(char **str1, char **str2,
int i1, int i2);
void inter(char *str1, char *str2, char *result);
#endif
