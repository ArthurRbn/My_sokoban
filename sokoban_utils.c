/*
** EPITECH PROJECT, 2019
** sokoban utils
** File description:
** sokoban functions
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

int getlines(char *map)
{
    int i = 0;
    int lines = 0;

    for (; map[i] != '\0'; ++i) {
        lines = (map[i] == 10)?lines + 1:lines;
    }
    return (lines);
}

void init_struct(data_t *data)
{
    data->len = 0;
    data->lines = 0;
    data->touch = 2;
    data->num_x = 0;
    data->num_o = 0;
    data->x_fill = 0;
    data->o_fill = 0;
    data->Play_x = 0;
    data->Play_y = 0;
}

void swit2(int car, data_t *data)
{
    switch (car) {
    case KEY_UP:
        haut(data);
        break;
    case ' ':
        reset_map(data);
        break;
    default:
        break;
    }
}

void swit(int car, data_t *data)
{
    car = getch();
    switch (car) {
    case KEY_RIGHT:
        droite(data);
        break;
    case KEY_LEFT:
        gauche(data);
        break;
    case KEY_DOWN:
        bas(data);
        break;
    default:
        swit2(car, data);
        break;
    }
}

int init_tabs(data_t *data)
{
    for (int line = 0; line < data->lines - 1; ++line) {
        for (int column = 0; column < data->len; ++column) {
            data->num_x += (data->Tmap[line][column] == 'X')?1:0;
            data->num_o += (data->Tmap[line][column] == 'O')?1:0;
        }
    }
    data->TabX = malloc(sizeof(item_t) * data->num_o + 1);
    data->TabO = malloc(sizeof(item_t) * data->num_x + 1);
    if (data->TabO == NULL || data->TabX == NULL)
        return (84);
    for (int i = 0; i < data->num_x; ++i) {
        data->TabX[i] = malloc(sizeof(item_t *) * 1);
        data->TabO[i] = malloc(sizeof(item_t *) * 1);
        if (data->TabO[i] == NULL || data->TabX[i] == NULL)
            return (84);
    }
}