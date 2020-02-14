/*
** EPITECH PROJECT, 2019
** sokoban read
** File description:
** functions to read sokoban's map
*/

#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <string.h>
#include <signal.h>
#include <sys/types.h>
#include "include/my.h"
#include "include/struct.h"

void sort_item(int line, int column, data_t *data)
{
    if (data->Tmap[line][column] == 'X') {
        data->TabX[data->x_fill]->X = line;
        data->TabX[data->x_fill]->Y = column;
        ++data->x_fill;
    } else if (data->Tmap[line][column] == 'O') {
        data->TabO[data->o_fill]->X = line;
        data->TabO[data->o_fill]->Y = column;
        ++data->o_fill;
    }
}

char **copy_map(char *map, data_t *data)
{
    int k = 0;
    int T = 0;

    for (int i = 0; i < data->lines - 1; ++i) {
        for (T = 0; map[k] != '\n' && map[k] != '\0'; ++T, ++k) {
            data->Tmap[i][T] = map[k];
            data->save_map[i][T] = map[k];
            data->touch = (map[k] != '#' && map[k] != ' ' && map[k] != 'P' &&
            map[k] != 'X' && map[k] != 'O' && map[k] != '\n' && map[k] != '\0')
            ? 84 : data->touch;
        }
        ++k;
    }
    return (data->Tmap);
}

void get_item(data_t *data)
{
    for (int line = 0; line < data->lines - 1; ++line)
        for (int column = 0; column < data->len; ++column)
            sort_item(line, column, data);
    get_player(data);
}

void fill_tab(char *map, data_t *data)
{
    data->len = getlen(map);
    data->lines = getlines(map) + 1;
    data->Tmap = malloc(sizeof(char *) * data->lines);
    data->save_map = malloc(sizeof(char *) * data->lines);
    int i = 0;

    if (data->Tmap != NULL) {
        for (; i < data->lines; ++i) {
            data->Tmap[i] = malloc(sizeof(char) * data->len);
            data->save_map[i] = malloc(sizeof(char) * data->len);
            if (data->Tmap[i] == NULL || data->save_map[i] == NULL)
                return;
            for (int k = 0; k < data->len; ++k) {
                data->Tmap[i][k] = 0;
                data->save_map[i][k] = 0;
            }
        }
    }
    data->Tmap[i - 1] = NULL;
    data->save_map[i - 1] = NULL;
    data->Tmap = copy_map(map, data);
}

void get_map(char *filepath, int fd, data_t *data)
{
    struct stat *matrix = malloc(sizeof(struct stat) * 1);
    long int size;
    char *map;

    stat(filepath, matrix);
    size = matrix->st_size;
    map = malloc(size + 1);
    read(fd, map, size);
    close(fd);
    free(matrix);
    close(fd);
    map[size] = '\0';
    fill_tab(map, data);
    free(map);
}

