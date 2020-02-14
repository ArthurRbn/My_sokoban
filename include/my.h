/*
** EPITECH PROJECT, 2019
** my
** File description:
** my
*/

#ifndef MY_H
#define MY_H

#include <stdarg.h>
#include <unistd.h>

typedef struct item_s
{
    int X;
    int Y;
} item_t;

typedef struct data_s
{
    char **Tmap;
    char **save_map;
    item_t **TabX;
    item_t **TabO;
    int num_x;
    int num_o;
    int x_fill;
    int o_fill;
    int Play_x;
    int Play_y;
    int touch;
    int len;
    int lines;
    int cnt;
} data_t;

void haut(data_t *data);
void bas(data_t *data);
void gauche(data_t *data);
void droite(data_t *data);
void swit2(int car, data_t *data);
void swit(int car, data_t *data);
int getlen(char *src);
int getlines(char *map);
char **copy_map(char *map, data_t *data);
void fill_tab(char *map, data_t *data);
void get_map(char *filepath, int fd, data_t *data);
void free_all(data_t *data);
void init_struct(data_t *data);
void reinit_struct(data_t *data);
void sort_item(int line, int column, data_t *data);
void get_item(data_t *data);
int main_function(int fd, char *filepath, data_t *data);
void game_loop(data_t *data);
int init_tabs(data_t *data);
void get_player(data_t *data);
void print_map(data_t *data);
void put_o(data_t *data);
void move_x(data_t *data, int move_x, int move_y);
void state_check(data_t *data);
void size_warning(data_t *data);
void reset_map(data_t *map);
void items(data_t *data);
int analyse_arg(char **av, data_t *data);
void my_putchar(char c);
void my_putstr(char const *str);
void get_x(data_t *data);
void sort_x(int line, int column, data_t *data);
void loose_check(data_t *data);
void check_corners(data_t *data, int x, int y, int i);

#endif //MY_H
