/*
** EPITECH PROJECT, 2019
** functions to analyse arguments
** File description:
** regular game or usage display
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

int aff_h(void)
{
    struct stat *des = malloc(sizeof(struct stat));
    int size;
    char *txt;
    int fd = open("help_txt", O_RDONLY);

    if (fd == -1)
        return (84);
    stat("help_txt", des);
    size = des->st_size;
    txt = malloc(sizeof(char) * (size + 1));
    read(fd, txt, size);
    txt[size] = 0;
    close(fd);
    free(des);
    my_putstr(txt);
    free(txt);
    return (0);
}

int analyse_arg(char **av, data_t *data)
{
    int i = 0;
    char *flag = "-h";
    int fd = -1;

    for (i = 0; flag[i] != 0 && flag[i] == av[1][i]; ++i);
    if (i == 2) {
        aff_h();
        return (0);
    } else {
        fd = open(av[1], O_RDONLY);
        if (fd == -1)
            return (84);
        fd = main_function(fd, av[1], data);
        return (fd);
    }
}