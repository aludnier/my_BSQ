/*
** EPITECH PROJECT, 2024
** verify
** File description:
** verify arg
*/

#include <stdbool.h>
#include <stdio.h>
#include "../include/my.h"
#include "../include/setting_up.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

bool verify_nb_line(char **tab_map, int nb_line_expected)
{
    int nb_line = 0;

    while (tab_map[nb_line] != NULL){
        nb_line++;
    }
    if (nb_line == nb_line_expected){
        return true;
    }
    return false;
}

bool verify_generate(char *size, char *patch)
{
    int len_nb = my_strlen(size);
    int len_patch = my_strlen(patch);

    for (int i_nb = 0; i_nb < len_nb; i_nb++){
        if (is_nbr(size[i_nb]) == -1){
            return false;
        }
    }
    if (patch[0] == '\0'){
        return false;
    }
    for (int i_patch = 0; i_patch < len_patch; i_patch++){
        if (patch[i_patch] != '.' && patch[i_patch] != 'o'){
            return false;
        }
    }
    return true;
}

bool verify_create(char *path_file)
{
    int fd = 0;
    char buff[51];
    int rd = 0;

    fd = open(path_file, O_RDONLY);
    if (fd == -1){
        close(fd);
        return false;
    }
    rd = read(fd, buff, 50);
    if (rd == -1){
        close(fd);
        return false;
    }
    close(fd);
    return true;
}
