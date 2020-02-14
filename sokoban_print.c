/*
** EPITECH PROJECT, 2019
** functions to print
** File description:
** functions to print
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

void state_check(data_t *data)
{
    int count_fill = 0;

    for (int i = 0; i < data->o_fill; ++i) {
        if (data->Tmap[data->TabO[i]->X][data->TabO[i]->Y] == 'X')
            count_fill += 1;
    }
    data->touch = (count_fill == data->o_fill)?0:data->touch;
    loose_check(data);
}

void move_x(data_t *data, int mx, int my)
{
    char c = data->Tmap[data->Play_y + my * 2][data->Play_x + mx * 2];

    if (c == ' ' || c == 'O') {
        data->Tmap[data->Play_y + my * 2][data->Play_x + mx * 2] = 'X';
        data->Tmap[data->Play_y + my][data->Play_x + mx] = 'P';
        data->Tmap[data->Play_y][data->Play_x] = ' ';
        data->Play_y += my;
        data->Play_x += mx;
    } else if (c == '#') {
        return;
    }
}

void put_o(data_t *data)
{
    for (int i = 0; i < data->o_fill; ++i) {
        if (data->Tmap[data->TabO[i]->X][data->TabO[i]->Y] != 'P' &&
            data->Tmap[data->TabO[i]->X][data->TabO[i]->Y] != 'X')
            data->Tmap[data->TabO[i]->X][data->TabO[i]->Y] = 'O';
    }
}

void print_map(data_t *data)
{
    int Y = 0;
    int X = 0;

    clear();
    put_o(data);
    for (int i = 0; data->Tmap[i] != NULL; ++i) {
        for (int k = 0; k < data->len; ++k) {
            move(X, Y);
            printw("%c", data->Tmap[i][k]);
            ++Y;
        }
        Y = 0;
        ++X;
    }
    move(data->Play_y, data->Play_x);
}