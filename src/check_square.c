/*
** EPITECH PROJECT, 2024
** check_square
** File description:
** check the actual square
*/

#include "../include/setting_up.h"
#include "../include/my.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stddef.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int check_size_sup(char **map_cp, coordinates_t co, int size, int nb_line)
{
    int x_temp = co.x;
    int y_temp = co.y;

    if (co.y + size >= nb_line){
        return size;
    }
    while (y_temp <= co.y + size){
        if (!IS_POINT(map_cp[y_temp][co.x + size])){
            return size;
        }
        y_temp++;
    }
    while (x_temp <= co.x + size){
        if (!IS_POINT(map_cp[co.y + size][x_temp])){
            return size;
        }
        x_temp++;
    }
    return check_size_sup(map_cp, co, size + 1, nb_line);
}

square_t check_square(char **map_cp, int x, int y, int nb_line)
{
    int size = 0;
    square_t square;
    coordinates_t co = {x, y};

    if (IS_POINT(map_cp[co.y][co.x])){
        size = 1;
        size = check_size_sup(map_cp, co, size, nb_line);
    }
    square.x = x;
    square.y = y;
    square.size = size;
    return square;
}
