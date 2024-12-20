/*
** EPITECH PROJECT, 2024
** find_square
** File description:
** find all square
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

void is_greater(square_t *great_square, int *x, int y, char char_size)
{
    int int_size = char_size - '0';

    if (char_size != 'o' && int_size > great_square->size){
        great_square->size = int_size;
        great_square->x = *x;
        great_square->y = y;
        *x += int_size;
    }
    *x += 1;
    return;
}

square_t find_greatest_square(map_t map, char **map_cp)
{
    square_t greatest_square = {0, 0, 0};
    int x = 0;

    for (int y = 0; y < map.nb_line; y++){
        x = 0;
        while (x < map.nb_column){
            is_greater(&greatest_square, &x, y, map_cp[y][x]);
        }
    }
    return greatest_square;
}

void copy_map(map_t map_src, char **dest)
{
    for (int line = 0; line < map_src.nb_line; line++){
        dest[line] = malloc(sizeof(char) * (map_src.nb_column + 1));
        for (int column = 0; column < map_src.nb_column; column++){
            dest[line][column] = map_src.tab_map[line][column];
        }
    }
}

void put_size(char **map_cp, square_t square)
{
    if (square.size != 0){
        map_cp[square.y][square.x] = '0' + square.size;
    }
}

void find_square(map_t map)
{
    char **map_cp = malloc(sizeof(char *) * (map.nb_line + 2));
    int y = 0;
    int x = 0;
    square_t square;

    copy_map(map, map_cp);
    for (y = 0; y < map.nb_line; y++){
        for (x = 0; x < map.nb_column; x++){
            square = check_square(map_cp, x, y, map.nb_line);
            put_size(map_cp, square);
        }
    }
    square = find_greatest_square(map, map_cp);
    replace_square(map.tab_map, square, 'x');
    free(map_cp);
}
