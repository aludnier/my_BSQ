/*
** EPITECH PROJECT, 2024
** create_map
** File description:
** create a map
*/

#include <stdio.h>
#include "../include/my.h"
#include "../include/setting_up.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

char *append_str(char *src, char *buffer)
{
    int len = my_strlen(src) + my_strlen(buffer);
    char *tmp = malloc(sizeof(char) * len);
    int len_src = my_strlen(src);

    if (tmp == NULL)
        return NULL;
    for (int index = 0; index < len_src; index++){
        tmp[index] = src[index];
    }
    for (int index = 0; index < my_strlen(buffer); index++){
        tmp[len_src + index] = buffer[index];
    }
    return tmp;
}

char *get_str_map(char *file_path)
{
    char *map = malloc(sizeof(char) * 1025);
    char buffer[1025];
    int fd;
    int size;

    if (map == NULL)
        return NULL;
    fd = open(file_path, O_RDONLY);
    if (fd == -1){
        my_printf("failed open file\n");
        return NULL;
    }
    size = read(fd, buffer, 1024);
    while (size > 0){
        buffer[size] = '\0';
        map = append_str(map, buffer);
        size = read(fd, buffer, size);
    }
    close(fd);
    return map;
}

void create_array_map(char **tab_map, char *str_map, int index)
{
    int length = 0;
    int nb_line = 0;

    while (str_map[index] != '\0'){
        while (str_map[index] != '\n' && str_map[index] != '\0'){
            index++;
            length++;
        }
        tab_map[nb_line] = malloc(sizeof(char *) * (length + 1));
        for (int i = length; i > 0; i--){
            tab_map[nb_line][length - i] = str_map[index - i];
        }
        if (str_map[index] == '\0'){
            return;
        }
        index++;
        nb_line++;
        length = 0;
    }
}

char **convert_map_to_array(char *str_map, char *file_path)
{
    int nb_line = get_nb_line(file_path);
    char **tab_map = (char **)malloc(sizeof(char *) * (nb_line + 2));
    int index = 0;
    int length = 0;

    if (tab_map == NULL)
        return NULL;
    while (str_map[index] != '\n'){
        index++;
    }
    index += 1;
    create_array_map(tab_map, str_map, index);
    if (!verify_nb_line(tab_map, nb_line)){
        free(tab_map);
        return NULL;
    }
    return tab_map;
}

map_t create_map(char *file_path)
{
    char *str_map = get_str_map(file_path);
    char **tab_map = NULL;
    map_t map = {0, 0, NULL};

    if (str_map == NULL)
        return map;
    tab_map = convert_map_to_array(str_map, file_path);
    if (tab_map == NULL)
        return map;
    map.nb_line = get_nb_line(file_path);
    map.nb_column = my_strlen(tab_map[0]);
    map.tab_map = tab_map;
    free(str_map);
    return map;
}
