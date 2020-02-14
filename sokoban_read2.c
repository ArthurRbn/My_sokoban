/*
** EPITECH PROJECT, 2019
** sokoban functions to read
** File description:
** sokoban functions to get palyer
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

int getlen(char *src)
{
    int k = 0;

    while (src[k] != '\n') {
        ++k;
    }
    return (k);
}

void get_player(data_t *data)
{
    for (int i = 0; i < data->lines && data->Play_x == 0; ++i) {
        for (int k = 0; k < data->len && data->Play_x == 0; ++k) {
            data->Play_x = (data->Tmap[i][k] == 'P')?k:data->Play_x;
            data->Play_y = (data->Tmap[i][k] == 'P')?i:data->Play_y;
        }
    }
}

void reinit_struct(data_t *data)
{
    data->touch = 2;
    data->x_fill = 0;
    data->o_fill = 0;
    data->Play_x = 0;
    data->Play_y = 0;
}

void items(data_t *data)
{
    for (int line = 0; line < data->lines - 1; ++line)
        for (int column = 0; column < data->len; ++column)
            sort_item(line, column, data);
    get_player(data);
}

void reset_map(data_t *data)
{
    reinit_struct(data);
    for (int i = 0; i < data->lines - 1; ++i)
        for (int k = 0; k < data->len; ++k)
            data->Tmap[i][k] = data->save_map[i][k];
    items(data);
}