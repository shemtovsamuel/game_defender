/*
** EPITECH PROJECT, 2020
** undefined
** File description:
** load_map.c
*/

#include "../include/defender.h"

char **mem_char_2d_array(int rows, int cols)
{
    char **arr = malloc(sizeof(char *) * rows);

    for (int i = 0; i < rows; i++) {
        arr[i] = malloc(sizeof(char) * cols);
        if (arr == NULL)
            return (NULL);
    }
    return (arr);
}

char *load_map(int argc, char **argv)
{
    char c;
    int fd;
    int end = 0;
    struct stat buff;

    stat(argv[1], &buff);
    char *map = malloc(sizeof(char) * buff.st_size + 1);

    fd =  open(argv[1], O_RDONLY);
    for (int i = 0; read(fd, &c, 1) > 0; i++) {
        map[i] = c;
        end = i;
    }
    map[end + 1] = '\0';
    close(fd);
    return (map);
}

char **str_to_2d(char const *str, int rows, int cols)
{
    int i_str = 0;
    char **arr = mem_char_2d_array(rows, cols);

    for (int j = 0; j < rows; j++) {
        for (int i = 0; i < cols; i++) {
            arr[j][i] = str[i_str];
            i_str++;
        }
    }
    return (arr);
}

void clear_map(game_t *game)
{
    enemy_t *current = game->scenes[1].enemy_list->first;
    enemy_t *next = NULL;
    background_t *bg = game->scenes[1].background;

    game->life = 100;
    game->money = 400;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    game->scenes[1].enemy_list->first = NULL;
    for (int i = 0; bg->slots[i].pos.x != 0; i++) {
        bg->slots[i].type = 0;
    }
    sfSprite_setPosition(game->scenes[1].objs[2].sprite,
    (sfVector2f){2000, 1100});
}