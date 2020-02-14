/*
** EPITECH PROJECT, 2019
** sokoban game functions
** File description:
** sokoban game loop
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

void game_loop(data_t *data)
{
    int car = 0;

    while (data->touch == 2) {
        print_map(data);
        swit(car, data);
        state_check(data);
        size_warning(data);
    }
    print_map(data);
    refresh();
}

void bas(data_t *data)
{
    char c = data->Tmap[data->Play_y + 1][data->Play_x];

    if (c == ' ' || c == 'O') {
        data->Tmap[data->Play_y + 1][data->Play_x] = 'P';
        data->Tmap[data->Play_y][data->Play_x] = ' ';
        data->Play_y += 1;
    } else if (c == '#') {
        return;
    } else {
        move_x(data, 0, 1);
    }
}

void gauche(data_t *data)
{
    char c = data->Tmap[data->Play_y][data->Play_x - 1];

    if (c == ' ' || c == 'O') {
        data->Tmap[data->Play_y][data->Play_x - 1] = 'P';
        data->Tmap[data->Play_y][data->Play_x] = ' ';
        data->Play_x -= 1;
    } else if (c == '#') {
        return;
    } else {
        move_x(data, -1, 0);
    }
}

void droite(data_t *data)
{
    char c = data->Tmap[data->Play_y][data->Play_x + 1];

    if (c == ' ' || c == 'O') {
        data->Tmap[data->Play_y][data->Play_x + 1] = 'P';
        data->Tmap[data->Play_y][data->Play_x] = ' ';
        data->Play_x += 1;
    } else if (c == '#') {
        return;
    } else {
        move_x(data, 1, 0);
    }
}

void haut(data_t *data)
{
    char c = data->Tmap[data->Play_y - 1][data->Play_x];

    if (c == ' ' || c == 'O') {
        data->Tmap[data->Play_y - 1][data->Play_x] = 'P';
        data->Tmap[data->Play_y][data->Play_x] = ' ';
        data->Play_y -= 1;
    } else if (c == '#') {
        return;
    } else {
        move_x(data, 0, -1);
    }
}