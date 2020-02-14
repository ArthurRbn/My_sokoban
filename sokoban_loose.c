/*
** EPITECH PROJECT, 2019
** functions to check is game loose
** File description:
** game loosed ?
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

void sort_x(int line, int column, data_t *data)
{
    if (data->Tmap[line][column] == 'X') {
        data->TabX[data->x_fill]->X = line;
        data->TabX[data->x_fill]->Y = column;
        ++data->x_fill;
    }
}

void get_x(data_t *data)
{
    data->x_fill = 0;
    for (int line = 0; line < data->lines - 1; ++line) {
        for (int column = 0; column < data->len; ++column) {
            sort_x(line, column, data);
        }
    }
}

int o_presence(data_t *data, int x, int y)
{
    int count_presence = 0;

    for (int i = 0; i < data->o_fill && count_presence == 0; ++i) {
        if (data->TabO[i]->X == x && data->TabO[i]->Y == y)
            count_presence += 1;
    }
    return (count_presence);
}

void check_corners(data_t *data, int x, int y, int i)
{
    if (data->Tmap[x + 1][y + 1] == '#') {
        data->cnt += (data->Tmap[x + 1][y] == '#')? 1 : 0;
        data->cnt += (data->Tmap[x][y + 1] == '#')? 1 : 0;
    } else if (data->Tmap[x - 1][y - 1] == '#') {
        data->cnt += (data->Tmap[x - 1][y] == '#')? 1 : 0;
        data->cnt += (data->Tmap[x][y - 1] == '#')? 1 : 0;
    }
    if (data->Tmap[x + 1][y - 1] == '#') {
        data->cnt += (data->Tmap[x + 1][y] == '#')? 1 : 0;
        data->cnt += (data->Tmap[x][y - 1] == '#')? 1 : 0;
    } else if (data->Tmap[x - 1][y + 1] == '#') {
        data->cnt += (data->Tmap[x - 1][y] == '#')? 1 : 0;
        data->cnt += (data->Tmap[x][y + 1] == '#')? 1 : 0;
    }
}

void loose_check(data_t *data)
{
    int x_stuck = 0;
    int o_here = 0;

    x_stuck = 0;
    for (int i = 0; i < data->x_fill; ++i) {
        get_x(data);
        o_here = o_presence(data, data->TabX[i]->X, data->TabX[i]->Y);
        data->cnt = 0;
        if (o_here == 0) {
            check_corners(data, data->TabX[i]->X, data->TabX[i]->Y, i);
        }
        x_stuck += (data->cnt > 2)?1:0;
    }
    data->touch = (x_stuck == data->x_fill)?1:data->touch;
}