/*
** EPITECH PROJECT, 2020
** struct file
** File description:
** struct
*/

#if !defined(STRUCT_H)
#define STRUCT_H

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

#endif // STRUCT_H
