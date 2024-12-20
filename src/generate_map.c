/*
** EPITECH PROJECT, 2024
** generate_map
** File description:
** generate from patch
*/

#include <stdio.h>
#include "../include/my.h"
#include "../include/setting_up.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

void check_end_patch(char *patch, int *i_patch)
{
    if (patch[*i_patch] == '\0'){
        *i_patch = 0;
    }
}

char *generate_str_map(int size, char *patch)
{
    int len_map = size * size + size + 1;
    char *str_map = malloc(sizeof(char) * len_map);
    int i_patch = 0;

    if (str_map == NULL)
        return NULL;
    for (int index = 0; index < len_map; index++){
        if (index % (size + 1) == 0){
            str_map[index] = '\n';
        } else {
            check_end_patch(patch, &i_patch);
            str_map[index] = patch[i_patch];
            i_patch++;
        }
    }
    return str_map;
}

char **generate_tab_map(int size, char *str_map)
{
    char **tab_map = malloc(sizeof(char *) * size + 1);
    int index = 1;

    if (tab_map == NULL)
        return NULL;
    create_array_map(tab_map, str_map, index);
    return tab_map;
}

map_t generate_map(int size, char *patch)
{
    char *str_map = generate_str_map(size, patch);
    char **tab_map = generate_tab_map(size, str_map);
    map_t map = {size, size, tab_map};

    free(str_map);
    return map;
}
