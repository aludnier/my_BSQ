/*
** EPITECH PROJECT, 2024
** replace square
** File description:
** replace square with size
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

void replace_square(char **map, square_t square, char replace_char)
{
    int x = square.x;
    int y = square.y;
    int size = square.size;

    if (size == 0){
        return;
    }
    for (int replace_x = x; replace_x < x + size; replace_x++){
        for (int replace_y = y; replace_y < y + size; replace_y++){
            map[replace_y][replace_x] = replace_char;
        }
    }
}
