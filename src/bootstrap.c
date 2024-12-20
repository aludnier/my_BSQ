/*
** EPITECH PROJECT, 2024
** bootstrap
** File description:
** setting up
*/

#include "../include/my.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int get_nb_line(char const *filepath)
{
    int fd = open(filepath, O_RDONLY);
    char buffer[501];
    int size = read(fd, buffer, 500);
    int nb = 0;
    int i = 0;

    if (fd == -1)
        return -1;
    if (is_nbr(buffer[i]) == -1){
        return -1;
    }
    for (i = 0; buffer[i] != '\n' && is_nbr(buffer[i]) != -1; i++){
        nb = nb * 10 + is_nbr(buffer[i]);
    }
    close(fd);
    return nb;
}
