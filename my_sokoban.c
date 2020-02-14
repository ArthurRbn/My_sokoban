/*
** EPITECH PROJECT, 2019
** my_popup
** File description:
** ncurses
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

void free_all(data_t *data)
{
    int i = 0;

    for (i = 0; i < data->lines; ++i) {
        free(data->Tmap[i]);
        free(data->save_map[i]);
    }
    free(data->Tmap);
    free(data->save_map);
    free(data);
}

void size_warning(data_t *data)
{
    for (;COLS < data->len || LINES < data->lines - 1;) {
        mvprintw(LINES / 2, COLS / 2 - 10, "%s", "Enlarge the terminal");
        refresh();
        clear();
        usleep(3000);
    }
}

int main_function(int fd, char *filepath, data_t *data)
{
    int return_val = 0;

    init_struct(data);
    initscr();
    keypad(stdscr, TRUE);
    curs_set(0);
    get_map(filepath, fd, data);
    if (data->touch != 84) {
        init_tabs(data);
        get_item(data);
        game_loop(data);
    }
    return_val = data->touch;
    free_all(data);
    endwin();
    return (return_val);
}

int main(int ac, char **av)
{
    int value = 0;
    data_t *data = (data_t *) malloc(sizeof(data_t));

    if (ac > 1) {
        value = analyse_arg(av, data);
        return (value);
    }
    return (84);
}