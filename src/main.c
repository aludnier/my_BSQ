/*
** EPITECH PROJECT, 2024
** main
** File description:
** setting_up
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

void print_map(map_t map)
{
    int index = 0;

    while (index < map.nb_line){
        write(1, map.tab_map[index], map.nb_column);
        my_putchar('\n');
        index++;
    }
}

int generate_setting_up(char **av)
{
    map_t map;

    if (!verify_generate(av[1], av[2])){
        return 84;
    }
    map = generate_map(my_getnbr(av[1]), av[2]);
    find_square(map);
    print_map(map);
    free(map.tab_map);
    return 0;
}

int create_from_file_setting_up(char **av)
{
    map_t map;

    if (!verify_create(av[1])){
        return 84;
    }
    map = create_map(av[1]);
    if (map.tab_map == NULL)
        return 84;
    find_square(map);
    print_map(map);
    free(map.tab_map);
    return 0;
}

int main(int ac, char **av)
{
    if (ac < 2 || ac > 3){
        return 84;
    } else if (ac == 3){
        return generate_setting_up(av);
    }
    return create_from_file_setting_up(av);
}
